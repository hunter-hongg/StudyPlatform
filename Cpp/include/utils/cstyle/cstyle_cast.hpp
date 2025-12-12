// cstyle_cast.hpp
#pragma once

#include <type_traits> // for std::enable_if, std::is_pointer, etc.
#include <cassert>     // for assert
#include <utility>     // for std::forward

namespace cstyle
{

//-------------------------------
// 基础类型转换（模仿C的强制转换，但更安全）
//-------------------------------

// 1. 指针转换（带运行时检查）
template <typename To, typename From>
std::enable_if_t<std::is_pointer_v<To> && std::is_pointer_v<From>, To>
pointer_cast(From ptr) noexcept
{
    // 确保 From 和 To 是兼容的指针类型（至少是 void*）
    static_assert(
        std::is_void_v<std::remove_pointer_t<From>> ||
        std::is_void_v<std::remove_pointer_t<To>> ||
        std::is_convertible_v<std::remove_pointer_t<From>*, std::remove_pointer_t<To>*>,
        "Incompatible pointer types"
    );
    return reinterpret_cast<To>(ptr);
}

// 2. 数值类型转换（带边界检查）
template <typename To, typename From>
std::enable_if_t<std::is_arithmetic_v<To> && std::is_arithmetic_v<From>, To>
numeric_cast(From value)
{
    // 浮点到整数时检查范围
    if constexpr (std::is_floating_point_v<From> && std::is_integral_v<To>) {
        assert(value >= static_cast<From>(std::numeric_limits<To>::min()) &&
               value <= static_cast<From>(std::numeric_limits<To>::max()));
    }
    return static_cast<To>(value);
}

// 3. 类型安全的 reinterpret_cast（仅允许特定场景）
template <typename To, typename From>
std::enable_if_t<
sizeof(To) == sizeof(From) &&
std::is_trivially_copyable_v<To> &&
std::is_trivially_copyable_v<From>,
    To
    >
    bit_cast(const From& src) noexcept
{
    // C++17 下模拟 std::bit_cast（C++20 才原生支持）
    To dst;
    std::memcpy(&dst, &src, sizeof(To));
    return dst;
}

//-------------------------------
// C 风格宏的替代品
//-------------------------------

// 4. 替代宏的常量表达式转换
template <typename To, typename From>
constexpr To const_cast_expr(From value) noexcept
{
    return static_cast<To>(value);
}

// 5. 安全的对象地址转换（类似 C 的 `(void*)&obj`）
template <typename T>
std::enable_if_t<!std::is_pointer_v<T>, void*>
object_to_void(T& obj) noexcept
{
    return reinterpret_cast<void*>(std::addressof(obj));
}

} // namespace cstyle