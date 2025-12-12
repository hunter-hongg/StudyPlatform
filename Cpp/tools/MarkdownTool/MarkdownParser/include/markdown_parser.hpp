#pragma once
#include <iostream>
#include <regex>
#include <vector>
#include <string_view>
#include <unordered_set>
#include <string>
#include <sstream>

namespace MParser{
struct Header {
    int level;
    std::string text;
};

class MarkdownParser {
public:

    static const std::regex HEADER_REGEX;
    static const std::regex KEYWORD_REGEX;

    int test_parser();
    void parse(std::string_view content);
    std::stringstream print_results() const;
    std::pair<std::vector<Header>, std::unordered_set<std::string> > get_results();

private:

    std::vector<Header> headers;
    std::unordered_set<std::string> keywords;

    std::vector<std::string> split_lines(std::string_view text);
    void extract_header(std::string line);
    void extract_keywords(std::string line);
};
}
