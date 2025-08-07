// cstyle_string.hpp
#pragma once

#include <cstdlib>     // malloc, free, realloc
#include <cstring>     // memcpy, strlen
#include <stdexcept>   // std::out_of_range
#include <algorithm>   // std::min
#include <iterator>    // std::begin, std::end
#include <utility>     // std::swap

namespace cstyle
{

class string
{
public:
    //-------------------------------
    // 构造/析构
    //-------------------------------
    string() noexcept : data_(nullptr), size_(0), capacity_(0) {}

    explicit string(const char* str)
    {
        size_ = std::strlen(str);
        capacity_ = size_ + 1;
        data_ = static_cast<char*>(std::malloc(capacity_));
        if (!data_) throw std::bad_alloc();
        std::memcpy(data_, str, capacity_);
    }

    string(const string& other) : string(other.data_) {}

    string(string&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
    {
        other.data_ = nullptr;
        other.size_ = other.capacity_ = 0;
    }

    ~string() noexcept
    {
        std::free(data_);
    }

    //-------------------------------
    // 赋值操作
    //-------------------------------
    string& operator=(const string& other)
    {
        if (this != &other) {
            string temp(other);
            swap(temp);
        }
        return *this;
    }

    string& operator=(string&& other) noexcept
    {
        swap(other);
        return *this;
    }

    string& operator=(const char* str)
    {
        string temp(str);
        swap(temp);
        return *this;
    }

    //-------------------------------
    // 元素访问
    //-------------------------------
    char& operator[](size_t pos)
    {
        if (pos >= size_) throw std::out_of_range("string index out of range");
        return data_[pos];
    }

    const char& operator[](size_t pos) const
    {
        if (pos >= size_) throw std::out_of_range("string index out of range");
        return data_[pos];
    }

    const char* c_str() const noexcept
    {
        return data_ ? data_ : "";
    }
    size_t size() const noexcept
    {
        return size_;
    }
    bool empty() const noexcept
    {
        return size_ == 0;
    }

    //-------------------------------
    // 修改操作
    //-------------------------------
    void clear() noexcept
    {
        size_ = 0;
        if (data_) data_[0] = '\0';
    }

    void reserve(size_t new_capacity)
    {
        if (new_capacity <= capacity_) return;
        resize_buffer(new_capacity);
    }

    void push_back(char ch)
    {
        if (size_ + 1 >= capacity_) {
            reserve(capacity_ ? capacity_ * 2 : 8);
        }
        data_[size_++] = ch;
        data_[size_] = '\0';
    }

    void append(const char* str, size_t count)
    {
        if (count == 0) return;
        if (size_ + count >= capacity_) {
            reserve(size_ + count + 1);
        }
        std::memcpy(data_ + size_, str, count);
        size_ += count;
        data_[size_] = '\0';
    }

    void append(const char* str)
    {
        append(str, std::strlen(str));
    }

    void append(const string& other)
    {
        append(other.data_, other.size_);
    }

    //-------------------------------
    // 工具函数
    //-------------------------------
    void swap(string& other) noexcept
    {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }

private:
    void resize_buffer(size_t new_capacity)
    {
        char* new_data = static_cast<char*>(std::realloc(data_, new_capacity));
        if (!new_data) throw std::bad_alloc();
        data_ = new_data;
        capacity_ = new_capacity;
    }

    char* data_;
    size_t size_;
    size_t capacity_;
};

//-------------------------------
// 非成员函数
//-------------------------------
inline bool operator==(const string& a, const string& b) noexcept
{
    return a.size() == b.size() &&
           std::strcmp(a.c_str(), b.c_str()) == 0;
}

inline bool operator!=(const string& a, const string& b) noexcept
{
    return !(a == b);
}

} // namespace cstyle