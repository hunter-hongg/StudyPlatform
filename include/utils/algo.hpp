#ifndef ALGO_HPP
#define ALGO_HPP

#include <string>
#include <vector>
#include <sstream>

inline std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::istringstream tokenStream(s);
    std::string token;

    while (std::getline(tokenStream, token, delimiter)) {
        if (!token.empty()) {  // 可选：跳过空字符串
            tokens.push_back(std::move(token));
        }
    }
    return tokens;
}

#endif