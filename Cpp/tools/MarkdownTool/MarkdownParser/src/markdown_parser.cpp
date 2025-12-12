#include "markdown_parser.hpp"

namespace MParser{
const std::regex MarkdownParser::HEADER_REGEX{R"(^(#{1,6})\s+(.+))"};
const std::regex MarkdownParser::KEYWORD_REGEX{R"(\*\*(.+?)\*\*|`(.+?)`)"};

int MarkdownParser::test_parser() {
    constexpr std::string_view md_content =
        R"(
# 现代C++特性
**C++20**引入了`模块`、`协程`等新特性
## 正则表达式改进
现在支持`编译期正则`检查
# Neovim
## 插入模式
`插入模式`指正常输入文本的模式
### i按键
i按键可以进入`插入模式`
)"
        ;

    MarkdownParser parser;
    parser.parse(md_content);
    auto t = parser.print_results();
    std::cout << t.str();
    return 0;
}

void MarkdownParser::parse(std::string_view content) {
    for (auto line : split_lines(content)) {
        extract_header(line);
        extract_keywords(line);
    }
}

std::stringstream MarkdownParser::print_results() const {
    std::stringstream ss;
    ss << "Headers:\n";
    for (const auto& h : headers) {
        ss << h.level << " | " << h.text << "\n";
    }

    ss << "\nKeywords:\n";
    for (const auto& k : keywords) {
        ss << k << "\n";
    }

    return ss;
}

std::vector<std::string> MarkdownParser::split_lines(std::string_view text) {
    std::vector<std::string> lines;
    size_t start = 0;
    while (start < text.size()) {
        auto end = text.find('\n', start);
        lines.push_back(std::string(text.substr(start, end - start)));
        start = end != std::string_view::npos ? end + 1 : text.size();
    }
    return lines;
}

void MarkdownParser::extract_header(std::string line) {
    std::smatch matches;
    if (std::regex_match(line, matches, HEADER_REGEX)) {
        headers.push_back({
            static_cast<int>(matches[1].length()), // 标题级别
            matches[2].str()                       // 标题内容
        });
    }
}

void MarkdownParser::extract_keywords(std::string line) {
    auto words_begin = std::sregex_iterator(
                           line.begin(),line.end(), KEYWORD_REGEX);
    auto words_end = std::sregex_iterator();

    for (auto i = words_begin; i != words_end; ++i) {
        // 处理**粗体**和`代码`两种关键词形式
        std::string keyword = (*i)[1].matched ? (*i)[1].str() : (*i)[2].str();
        keywords.insert(std::move(keyword));
    }
}

std::pair<std::vector<Header>, std::unordered_set<std::string>> MarkdownParser::get_results() {
    return std::make_pair(headers, keywords);
}
}
