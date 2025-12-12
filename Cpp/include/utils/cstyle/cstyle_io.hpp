// cstyle_io.hpp
#pragma once

#include <cstdio>      // vsnprintf, vsscanf
#include <string>      // std::string
#include <vector>      // std::vector
#include <stdexcept>   // std::runtime_error
#include <cstdarg>     // va_list
#include <memory>      // std::unique_ptr
#include <system_error> // std::system_error
#include <cerrno>      // errno

namespace cstyle
{

//-------------------------------
// 错误处理
//-------------------------------
inline void throw_io_error(const char* msg)
{
    throw std::system_error(errno, std::generic_category(), msg);
}

//-------------------------------
// 安全格式化输出（printf风格）
//-------------------------------

// 基础实现（可变参数）
inline int vformat_output(FILE* stream, const char* fmt, va_list args)
{
    errno = 0;
    int ret = std::vfprintf(stream, fmt, args);
    if (ret < 0) throw_io_error("Format output failed");
    return ret;
}

// 格式化输出到文件（类似fprintf）
template <typename... Args>
void printf(FILE* stream, const char* fmt, Args... args)
{
    va_list vl;
    va_start(vl, args);
    try {
        vformat_output(stream, fmt, vl);
        va_end(vl);
    } catch (...) {
        va_end(vl);
        throw;
    }
}

// 格式化输出到字符串（返回std::string）
template <typename... Args>
std::string sprintf(const char* fmt, Args... args)
{
    va_list vl;
    va_start(vl, args);

    // 第一次调用获取长度
    va_list vl_copy;
    va_copy(vl_copy, vl);
    int len = std::vsnprintf(nullptr, 0, fmt, vl_copy);
    va_end(vl_copy);

    if (len < 0) throw_io_error("Format string failed");

    // 实际写入
    std::vector<char> buf(len + 1);
    int ret = std::vsnprintf(buf.data(), buf.size(), fmt, vl);
    va_end(vl);

    if (ret < 0) throw_io_error("Format string failed");
    return std::string(buf.data(), len);
}

//-------------------------------
// 安全格式化输入（scanf风格）
//-------------------------------

// 基础实现（可变参数）
inline int vformat_input(FILE* stream, const char* fmt, va_list args)
{
    errno = 0;
    int ret = std::vfscanf(stream, fmt, args);
    if (ret == EOF && errno != 0) throw_io_error("Format input failed");
    return ret;
}

// 从文件读取格式化输入（类似fscanf）
template <typename... Args>
int scanf(FILE* stream, const char* fmt, Args... args)
{
    va_list vl;
    va_start(vl, args);
    try {
        int ret = vformat_input(stream, fmt, vl);
        va_end(vl);
        return ret;
    } catch (...) {
        va_end(vl);
        throw;
    }
}

// 从字符串读取格式化输入（类似sscanf）
template <typename... Args>
int sscanf(const char* str, const char* fmt, Args... args)
{
    va_list vl;
    va_start(vl, args);
    try {
        int ret = std::vsscanf(str, fmt, vl);
        va_end(vl);
        if (ret == EOF && errno != 0) throw_io_error("String scan failed");
        return ret;
    } catch (...) {
        va_end(vl);
        throw;
    }
}

} // namespace cstyle