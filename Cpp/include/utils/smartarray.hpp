#ifndef SMARTARRAY_HPP
#define SMARTARRAY_HPP

#include <stdexcept>
#include <algorithm>
#include <utility>

template<typename T>
class SmartArray
{
public:
    explicit SmartArray(int size)
    {
        if (size <= 0) throw std::invalid_argument("Size must be positive");
        size_ = static_cast<size_t>(size);
        array_ = new T[size_] {};
    }

    ~SmartArray()
    {
        delete[] array_;
    }

    SmartArray(const SmartArray&) = delete;
    SmartArray& operator=(const SmartArray&) = delete;

    SmartArray(SmartArray&& other) noexcept
        : array_(other.array_), size_(other.size_)
    {
        other.array_ = nullptr;
        other.size_ = 0;
    }

    SmartArray& operator=(SmartArray&& other) noexcept
    {
        if (this != &other) {
            delete[] array_;
            array_ = other.array_;
            size_ = other.size_;
            other.array_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    T& operator[](int index)
    {
        return array_[checkedIndex(index)];
    }
    const T& operator[](int index) const
    {
        return array_[checkedIndex(index)];
    }

    SmartArray<T> slice(int start, int end) const
    {
        int s = adjustIndex(start, true);
        int e = adjustIndex(end, false);
        s = std::clamp(s, 0, static_cast<int>(size_));
        e = std::clamp(e, s, static_cast<int>(size_));

        SmartArray<T> result(e - s);
        for (int i = 0; i < result.size(); ++i) {
            result[i] = array_[s + i];
        }
        return result;
    }

    size_t size() const
    {
        return size_;
    }

    // 新增方法：检查指针是否为空
    bool is_empty() const
    {
        return array_ == nullptr;
    }

private:
    T* array_ = nullptr;
    size_t size_ = 0;

    size_t checkedIndex(int index) const
    {
        int adjusted = index >= 0 ? index : static_cast<int>(size_) + index;
        if (adjusted < 0 || adjusted >= static_cast<int>(size_))
            throw std::out_of_range("Index out of range");
        return static_cast<size_t>(adjusted);
    }

    int adjustIndex(int index, bool isStart) const
    {
        if (index < 0) index += static_cast<int>(size_);
        return isStart ? std::max(0, index) : std::min(index, static_cast<int>(size_));
    }
};

#endif // SMARTARRAY_HPP