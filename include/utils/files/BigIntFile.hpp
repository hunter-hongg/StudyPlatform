#pragma once
#include <fstream>
#include <string>

class BigIntFile {
public:
    BigIntFile() = delete;
    BigIntFile(std::string f) {
        file = f ;
    }
    std::string GetFile() {
        return file ;
    }
    std::string Read() {
        std::ifstream f(file);
        if(!f.is_open()) {
            f.close();
            std::ofstream t(file);
            t << "0";
            t.close();
            return "0";
        }
        std::string ttt;
        f >> ttt;
        f.close();
        return ttt;
    }
    void Write(std::string n) {
        std::ofstream f(file);
        f << n;
        f.close();
    }
protected:
    std::string file;
};
