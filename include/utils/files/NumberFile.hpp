#pragma once
#include <iostream>
#include <fstream>
#include <BigInt.hpp>
#include <type.hpp>
#define let const auto
#define lmut auto

class NumberFile {
private: 
    std::string filename_real;
    std::string filename_check;
public: 
    NumberFile() = delete;
    NumberFile(std::string filename_r, std::string filename_c) {
        filename_real = filename_r;
        filename_check = filename_c;
    }
    BigInt Read() {
        std::ifstream fcs(filename_check);
        if ( ! fcs.is_open() ) {
            fcs.close();
            std::ofstream fcso(filename_check);
            fcso << "1";
            fcso.close();
        }
        return BigInt(0);
    }
    int Write(BigInt num) {
        return 0;
    }
};
