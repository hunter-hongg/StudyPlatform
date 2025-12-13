#ifndef SMARTPTR_HPP
#define SMARTPTR_HPP

#include <utility> // for std::move

template <typename T>
class SmartPtr
{
public:
    // 默认构造函数，初始化为nullptr
    SmartPtr() noexcept : ptr_(nullptr) {}

    // 显式构造函数，接受原生指针
    explicit SmartPtr(T* ptr) noexcept : ptr_(ptr) {}

    // 禁止拷贝构造
    SmartPtr(const SmartPtr&) = delete;

    // 移动构造函数
    SmartPtr(SmartPtr&& other) noexcept : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }

    // 析构函数
    ~SmartPtr()
    {
        delete ptr_;
    }

    // 禁止拷贝赋值
    SmartPtr& operator=(const SmartPtr&) = delete;

    // 移动赋值操作符
    SmartPtr& operator=(SmartPtr&& other) noexcept
    {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // 重载*操作符
    T& operator*() const noexcept
    {
        return *ptr_;
    }

    // 重载->操作符
    T* operator->() const noexcept
    {
        return ptr_;
    }

    // 获取原生指针
    T* get() const noexcept
    {
        return ptr_;
    }

    // 释放所有权
    T* release() noexcept
    {
        T* ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    // 重置指针
    void reset(T* ptr = nullptr) noexcept
    {
        delete ptr_;
        ptr_ = ptr;
    }

    // 检查是否为空
    explicit operator bool() const noexcept
    {
        return ptr_ != nullptr;
    }

private:
    T* ptr_;
};

#endif // SMARTPTR_HPP
