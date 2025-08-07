#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <utils/algo.hpp>
#include <algorithm>

static std::vector<std::string> emptyVec;

class Cards
{
public:
    Cards() = delete;
    Cards(const std::string& filename,const std::vector<std::string>& v,const int addnum):
        filename(filename),cardname(v),addnum(addnum) {}
    std::vector<std::string> Get()
    {
        std::ofstream tmp(filename,std::ios::app);
        tmp.close();
        std::ifstream readstream(filename);
        if(!readstream.is_open()) {
            readstream.close();
            return emptyVec;
        }
        std::string rawstr;
        readstream >> rawstr;
        auto rawvec = split(rawstr,',');
        std::vector<int> rawIntVec;
        for(const auto& i : rawvec) {
            if(!i.starts_with("/x/")) continue;
            auto realstr=i.substr(3,i.size()-3);
            rawIntVec.push_back(atoi(realstr.c_str()));
        }
        std::vector<int> realIntVec;
        for(const auto& i : rawIntVec) {
            if(std::find(realIntVec.begin(),realIntVec.end(),i - addnum) != realIntVec.end()) continue;
            realIntVec.push_back(i - addnum);
        }
        std::vector<std::string> realCardVec;
        for(const auto& i : realIntVec) {
            if(i < 0 || i >= cardname.size()) continue;
            realCardVec.push_back(cardname[i]);
        }
        return realCardVec;
    }
    int Write(int index)
    {
        if(index < 0 || index >= cardname.size()) return -1;
        std::ofstream ofs(filename,std::ios::app);
        ofs << ",/x/" << (addnum+index);
        return 0;
    }
    std::string operator[] (int index)
    {
        if(index < 0 || index >= cardname.size()) return std::string("");
        return cardname[index];
    }
protected:
    std::vector<std::string> cardname;
    std::string filename;
    int addnum;
};
