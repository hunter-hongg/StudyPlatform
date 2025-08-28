#pragma once
#include <utils/old/file_password.h>
#include <macro.hpp>

class PasswordFile: protected file_password
{
public:
    PasswordFile(const std::string& fn, const std::string& p):file_password(fn,p) {}
    PasswordFile(const std::string& fn, const std::string& p, int d):file_password(fn,p) { 
        std::error_code ec;
        if (!std::filesystem::exists(fn, ec)) {
            this -> write(d) ; 
        }
    }
    std::string read_str()
    {
        auto tmp = this->read_real();
        auto rtt = TOSTR(atoi(tmp.c_str()));
        return rtt;
    }
    int read_int()
    {
        auto tmp = this->read_real();
        return atoi(tmp.c_str());
    }
    void addnum(int a)
    {
        if(a<0) return;
        this->add(a);
    }
    void minusnum(int a)
    {
        if(a<0) return;
        this->add(-a);
    }
    bool high(int a)
    {
        return (read_int() >= a);
    }
    bool canminus(int a)
    {
        if(!high(a)) return false;
        minusnum(a);
        return true;
    }
};
