#pragma once
#include <utils/old/file_password.h>
#include <macro.hpp>
#include <filesystem>

class PasswordFile: protected file_password
{
public:
    PasswordFile(const std::string& filename_, const std::string& p):file_password(filename_,p) {}
    PasswordFile(const std::string& filename_, const std::string& p, int d):file_password(filename_,p) {
        std::error_code ec;
        if (!std::filesystem::exists(filename_, ec)) {
            this -> write(d) ;
        }
    }
    std::string read_str()
    {
        // 读取存储数字返回std::string
        auto tmp = this->read_real();
        auto rtt = TOSTR(atoi(tmp.c_str()));
        return rtt;
    }
    int read_int()
    {
        // 读取存储数字返回int
        auto tmp = this->read_real();
        return atoi(tmp.c_str());
    }
    void addnum(int a)
    {
        // 增加存储数字
        if(a<0) return;
        this->add(a);
    }
    void minusnum(int a)
    {
        // 减小存储数字，不检查是否为负数
        if(a<0) return;
        this->add(-a);
    }
    void minusnum_if(int a) {
        // 减小存储数字，若不足则减至0
        if(a<0) return;
        if(this->high(a)) {
            this -> minusnum(a);
        }
        else {
            this -> minusnum(this -> read_int());
        }
    }
    bool high(int a)
    {
        // 判断是否大于等于指定数字，返回bool
        return (read_int() >= a);
    }
    bool canminus(int a)
    {
        // 判断是否大于等于指定数字，若满足则减去，不满足则不变，返回bool代表是否满足
        if(!high(a)) return false;
        minusnum(a);
        return true;
    }
};
