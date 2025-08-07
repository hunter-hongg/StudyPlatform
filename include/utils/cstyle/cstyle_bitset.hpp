// cstyle_bitset.hpp
#pragma once

#include <cstdlib>     // malloc, free
#include <cstring>    // memset, memcpy
#include <climits>    // CHAR_BIT
#include <stdexcept>  // std::out_of_range
#include <algorithm>  // std::min, std::fill
#include <utility>    // std::swap

namespace cstyle
{

class bitset
{
public:
    //-------------------------------
    // 构造/析构
    //-------------------------------
    explicit bitset(size_t count, bool init_val = false)
        : size_(count),
          block_count_((count + CHAR_BIT - 1) / CHAR_BIT)
    {
        data_ = static_cast<unsigned char*>(std::malloc(block_count_));
        if (!data_) throw std::bad_alloc();
        std::memset(data_, init_val ? 0xFF : 0x00, block_count_);
    }

    bitset(const bitset& other) : size_(other.size_), block_count_(other.block_count_)
    {
        data_ = static_cast<unsigned char*>(std::malloc(block_count_));
        if (!data_) throw std::bad_alloc();
        std::memcpy(data_, other.data_, block_count_);
    }

    bitset(bitset&& other) noexcept
        : data_(other.data_), size_(other.size_), block_count_(other.block_count_)
    {
        other.data_ = nullptr;
        other.size_ = other.block_count_ = 0;
    }

    ~bitset() noexcept
    {
        std::free(data_);
    }

    //-------------------------------
    // 赋值操作
    //-------------------------------
    bitset& operator=(const bitset& other)
    {
        if (this != &other) {
            bitset temp(other);
            swap(temp);
        }
        return *this;
    }

    bitset& operator=(bitset&& other) noexcept
    {
        swap(other);
        return *this;
    }

    //-------------------------------
    // 元素访问
    //-------------------------------
    bool operator[](size_t pos) const
    {
        if (pos >= size_) throw std::out_of_range("bitset index out of range");
        return (data_[pos / CHAR_BIT] >> (pos % CHAR_BIT)) & 1;
    }

    class reference
    {
    public:
        reference(unsigned char& block, unsigned char mask)
            : block_(block), mask_(mask) {}

        operator bool() const noexcept
        {
            return block_ & mask_;
        }

        reference& operator=(bool val) noexcept
        {
            val ? (block_ |= mask_) : (block_ &= ~mask_);
            return *this;
        }

    private:
        unsigned char& block_;
        unsigned char mask_;
    };

    reference operator[](size_t pos)
    {
        if (pos >= size_) throw std::out_of_range("bitset index out of range");
        return reference(data_[pos / CHAR_BIT], 1 << (pos % CHAR_BIT));
    }

    bool test(size_t pos) const
    {
        return (*this)[pos];
    }
    size_t size() const noexcept
    {
        return size_;
    }

    //-------------------------------
    // 位操作
    //-------------------------------
    void set(size_t pos, bool val = true)
    {
        (*this)[pos] = val; // 利用 reference 类
    }

    void flip(size_t pos)
    {
        (*this)[pos] = !(*this)[pos];
    }

    void fill(bool val) noexcept
    {
        std::memset(data_, val ? 0xFF : 0x00, block_count_);
    }

    //-------------------------------
    // 工具函数
    //-------------------------------
    void swap(bitset& other) noexcept
    {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(block_count_, other.block_count_);
    }

private:
    unsigned char* data_;
    size_t size_;         // 位数量
    size_t block_count_;  // 字节块数量
};

} // namespace cstyle