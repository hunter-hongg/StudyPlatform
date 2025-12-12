#pragma once
#include <markdown_parser.hpp>
#include <markdown_sqlite.hpp>
#include <string>
#include <fstream>

namespace MFile{
class File {
public:
    File(std::string file_path, std::string d) {
        fpath_ = file_path;
        dpath_ = d;
    }
    int into_database() {
        std::string rawcon;
        std::ifstream ifs(fpath_);
        if(!ifs.is_open()) {
            ifs.close();
            return 1;
        }
        std::string line;
        while(getline(ifs, line) ) {
            rawcon += line;
            rawcon += '\n';
        }
        ifs.close();
        MParser::MarkdownParser p;
        p.parse(rawcon);
        auto [title, keyword] = p.get_results();
        MSQLite::Database db_(dpath_.data());
        db_.create_table();
        db_.insert_document(title, rawcon, keyword);
        return 0;
    }
private:
    std::string fpath_;
    std::string dpath_;
};
}
