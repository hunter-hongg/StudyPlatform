// cstyle_memory.hpp
#pragma once

#include <cstdlib>   // malloc, free, realloc, aligned_alloc
#include <memory>    // std::unique_ptr
#include <utility>   // std::forward
#include <cstring>   // memcpy, memmove, memset
#include <new>       // std::bad_alloc
#include <type_traits> // std::is_trivially_copyable

namespace cstyle
{

// 基本内存分配（失败时抛出 std::bad_alloc）
inline void* allocate(size_t size)
{
    if (void* ptr = std::malloc(size)) {
        return ptr;
    }
    throw std::bad_alloc{};
}

// 对齐内存分配（C++17 起支持 aligned_alloc）
inline void* allocate_aligned(size_t size, size_t alignment)
{
    if (void* ptr = std::aligned_alloc(alignment, size)) {
        return ptr;
    }
    throw std::bad_alloc{};
}

// 内存释放（noexcept 保证不抛异常）
inline void deallocate(void* ptr) noexcept
{
    std::free(ptr);
}

// 重新分配内存（失败时抛出 std::bad_alloc）
inline void* reallocate(void* ptr, size_t new_size)
{
    if (void* new_ptr = std::realloc(ptr, new_size)) {
        return new_ptr;
    }
    throw std::bad_alloc{};
}

// 安全的内存拷贝（仅适用于平凡可复制类型）
template <typename T, typename U>
std::enable_if_t<std::is_trivially_copyable<T>::value && std::is_trivially_copyable<U>::value>
memory_copy(T* dest, const U* src, size_t count) noexcept
{
    std::memcpy(dest, src, count * sizeof(T));
}

// 安全的内存移动（处理重叠区域）
template <typename T>
std::enable_if_t<std::is_trivially_copyable<T>::value>
memory_move(T* dest, const T* src, size_t count) noexcept
{
    std::memmove(dest, src, count * sizeof(T));
}

// 内存设置（仅适用于平凡可复制类型）
template <typename T>
std::enable_if_t<std::is_trivially_copyable<T>::value>
memory_set(T* dest, int value, size_t count) noexcept
{
    std::memset(dest, value, count * sizeof(T));
}

// 智能指针封装（使用 C 风格释放）
template <typename T>
using unique_ptr = std::unique_ptr<T, void(*)(void*)>;

// 创建 unique_ptr 的工厂函数
template <typename T>
unique_ptr<T> make_unique(size_t count = 1)
{
    if constexpr (std::is_array_v<T>) {
        using element_type = std::remove_extent_t<T>;
        void* ptr = allocate(count * sizeof(element_type));
        return unique_ptr<T>(static_cast<element_type*>(ptr), &deallocate);
    } else {
        void* ptr = allocate(sizeof(T));
        return unique_ptr<T>(static_cast<T*>(ptr), &deallocate);
    }
}

// 对齐分配的 unique_ptr 工厂函数
template <typename T>
unique_ptr<T> make_unique_aligned(size_t alignment, size_t count = 1)
{
    if constexpr (std::is_array_v<T>) {
        using element_type = std::remove_extent_t<T>;
        void* ptr = allocate_aligned(count * sizeof(element_type), alignment);
        return unique_ptr<T>(static_cast<element_type*>(ptr), &deallocate);
    } else {
        void* ptr = allocate_aligned(sizeof(T), alignment);
        return unique_ptr<T>(static_cast<T*>(ptr), &deallocate);
    }
}

// 在已分配内存上构造对象（placement new 封装）
template <typename T, typename... Args>
T* construct_at(T* location, Args&&... args)
{
    return ::new (static_cast<void*>(location)) T(std::forward<Args>(args)...);
}

// 销毁对象（显式调用析构函数）
template <typename T>
void destroy_at(T* location) noexcept
{
    location->~T();
}

} // namespace cstyle