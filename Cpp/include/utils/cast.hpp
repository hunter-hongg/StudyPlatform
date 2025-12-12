#pragma once
#include <string>
#include <sstream>
#include <stdexcept>
#include <type_traits>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <limits>

// 特化版本：字符串到字符串的直接返回
template <typename Target>
inline Target lexical_cast(const std::string& arg)
{
    return arg;
}

// 特化版本：C风格字符串到字符串
template <typename Target>
inline Target lexical_cast(const char* arg)
{
    return std::string(arg);
}

// 通用实现
template <typename Target, typename Source>
inline typename std::enable_if<!std::is_same<Target, Source>::value, Target>::type
lexical_cast(const Source& arg)
{
    std::stringstream interpreter;
    Target result;

    if (!(interpreter << arg)) {
        throw std::runtime_error("lexical_cast: source formatting failed");
    }

    if (!(interpreter >> result)) {
        throw std::runtime_error("lexical_cast: target parsing failed");
    }

    // 检查是否有剩余字符未被解析
    char remaining;
    if (interpreter >> remaining) {
        throw std::runtime_error("lexical_cast: unconverted data remaining");
    }

    return result;
}

// 数值类型到字符串的优化特化
template <>
inline std::string lexical_cast<std::string, int>(const int& arg)
{
    return std::to_string(arg);
}

template <>
inline std::string lexical_cast<std::string, double>(const double& arg)
{
    return std::to_string(arg);
}

// 字符串到数值类型的优化特化
template <>
inline int lexical_cast<int, std::string>(const std::string& arg)
{
    try {
        size_t pos;
        int result = std::stoi(arg, &pos);
        if (pos != arg.length()) {
            throw std::invalid_argument("lexical_cast: invalid characters");
        }
        return result;
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("lexical_cast: ") + e.what());
    }
}

template <>
inline double lexical_cast<double, std::string>(const std::string& arg)
{
    try {
        size_t pos;
        double result = std::stod(arg, &pos);
        if (pos != arg.length()) {
            throw std::invalid_argument("lexical_cast: invalid characters");
        }
        return result;
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("lexical_cast: ") + e.what());
    }
}
