#ifndef CSTYLE_ARRAY_HPP
#define CSTYLE_ARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <iterator>
#include <type_traits>
#include <initializer_list>
#include <algorithm>
#include <concepts>  // C++20 概念支持

namespace cstyle
{

// C++20 概念约束：可交换类型
template <typename T>
concept Swappable = requires(T& a, T& b)
{
    std::swap(a, b);
};

template <typename T, std::size_t N>
struct array {
    // 成员类型定义
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // 数据成员 - 原生 C 数组
    T data_[N];

    // 默认构造函数（值初始化）
    constexpr array() noexcept(std::is_nothrow_default_constructible_v<T>) = default;

    // 初始化列表构造函数
    constexpr array(std::initializer_list<T> init)
    {
        std::copy_n(init.begin(), std::min(init.size(), N), data_);
    }

    // 元素访问
    constexpr reference operator[](size_type pos) noexcept
    {
        return data_[pos];
    }

    constexpr const_reference operator[](size_type pos) const noexcept
    {
        return data_[pos];
    }

    constexpr reference at(size_type pos)
    {
        return pos < N ? data_[pos] : throw std::out_of_range("array::at");
    }

    constexpr const_reference at(size_type pos) const
    {
        return pos < N ? data_[pos] : throw std::out_of_range("array::at");
    }

    constexpr reference front() noexcept
    {
        return data_[0];
    }

    constexpr const_reference front() const noexcept
    {
        return data_[0];
    }

    constexpr reference back() noexcept
    {
        return data_[N - 1];
    }

    constexpr const_reference back() const noexcept
    {
        return data_[N - 1];
    }

    constexpr pointer data() noexcept
    {
        return data_;
    }

    constexpr const_pointer data() const noexcept
    {
        return data_;
    }

    // 迭代器
    constexpr iterator begin() noexcept
    {
        return iterator(data_);
    }

    constexpr const_iterator begin() const noexcept
    {
        return const_iterator(data_);
    }

    constexpr const_iterator cbegin() const noexcept
    {
        return const_iterator(data_);
    }

    constexpr iterator end() noexcept
    {
        return iterator(data_ + N);
    }

    constexpr const_iterator end() const noexcept
    {
        return const_iterator(data_ + N);
    }

    constexpr const_iterator cend() const noexcept
    {
        return const_iterator(data_ + N);
    }

    constexpr reverse_iterator rbegin() noexcept
    {
        return reverse_iterator(end());
    }

    constexpr const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(end());
    }

    constexpr const_reverse_iterator crbegin() const noexcept
    {
        return const_reverse_iterator(cend());
    }

    constexpr reverse_iterator rend() noexcept
    {
        return reverse_iterator(begin());
    }

    constexpr const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(begin());
    }

    constexpr const_reverse_iterator crend() const noexcept
    {
        return const_reverse_iterator(cbegin());
    }

    // 容量
    [[nodiscard]] constexpr bool empty() const noexcept
    {
        return N == 0;
    }

    [[nodiscard]] constexpr size_type size() const noexcept
    {
        return N;
    }

    [[nodiscard]] constexpr size_type max_size() const noexcept
    {
        return N;
    }

    // 操作
    constexpr void fill(const T& value)
    {
        std::fill_n(begin(), N, value);
    }

    constexpr void swap(array& other) noexcept(Swappable<T>)
    {
        std::swap_ranges(begin(), end(), other.begin());
    }

    // C++20 概念约束的运算符重载
    friend constexpr bool operator==(const array& lhs, const array& rhs)
    requires std::equality_comparable<T> {
        return std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    friend constexpr bool operator!=(const array& lhs, const array& rhs)
    requires std::equality_comparable<T> {
        return !(lhs == rhs);
    }

    friend constexpr bool operator<(const array& lhs, const array& rhs)
    requires std::totally_ordered<T> {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    friend constexpr bool operator<=(const array& lhs, const array& rhs)
    requires std::totally_ordered<T> {
        return !(rhs < lhs);
    }

    friend constexpr bool operator>(const array& lhs, const array& rhs)
    requires std::totally_ordered<T> {
        return rhs < lhs;
    }

    friend constexpr bool operator>=(const array& lhs, const array& rhs)
    requires std::totally_ordered<T> {
        return !(lhs < rhs);
    }
};

// 特化 N=0 的情况（C++17 允许零长度数组）
template <typename T>
struct array<T, 0> {
    // 所有方法均为空或返回默认值
    [[nodiscard]] constexpr bool empty() const noexcept
    {
        return true;
    }
    [[nodiscard]] constexpr std::size_t size() const noexcept
    {
        return 0;
    }
    // ... 其他方法类似
};

} // namespace cstyle

#endif // CSTYLE_ARRAY_HPP
