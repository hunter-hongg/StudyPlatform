#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstdlib>
#include <sstream>

using std::ostream;
using std::string;
using std::ofstream;
using std::ifstream;

namespace functions
{
class SwordException:public std::exception
{
public:
    explicit SwordException(const char* err)
    {
        msg=string(err);
    }
    const char* what() const noexcept override
    {
        return msg.c_str();
    }
protected:
    string msg;
};
enum class SwordEnum { gold,wood,water,fire,soil };
class SwordInFile
{
public:
    explicit SwordInFile(string& file1)
    {
        file=file1;
        ofstream tmp(file,std::ios::app);
        tmp.close();
    }
    explicit SwordInFile(string&& file1)
    {
        file=file1;
        ofstream tmp(file,std::ios::app);
        tmp.close();
    }
    SwordEnum get()
    {
        ifstream inputFile(file);
        string tmp;
        getline(inputFile,tmp);
        int tmp2=atoi(tmp.c_str());
        if(!((tmp2>=0)&&(tmp2<=4))) return SwordEnum::gold;
        return static_cast<SwordEnum>(tmp2);
    }
    int set(const SwordEnum& thing)
    {
        int tmp=static_cast<int>(thing);
        ofstream outputFile(file);
        outputFile << tmp;
        return 0;
    }
protected:
    string file;
};
}
static ostream& operator<<(ostream& stream,const functions::SwordEnum& enumA)
{
    if(enumA==functions::SwordEnum::gold) {
        return stream << "金剑";
    } else if(enumA==functions::SwordEnum::wood) {
        return stream << "木剑";
    } else if(enumA==functions::SwordEnum::water) {
        return stream << "水剑";
    } else if(enumA==functions::SwordEnum::fire) {
        return stream << "火剑";
    } else {
        return stream << "土剑";
    }
}
static std::string swordToString(const functions::SwordEnum& enumA)
{
    std::stringstream ss;
    ss << enumA;
    return ss.str();
}
