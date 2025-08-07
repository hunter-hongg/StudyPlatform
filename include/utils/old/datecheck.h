#ifndef DATECHECK_H
#define DATECHECK_H
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>

using std::ofstream;
using std::ifstream;
using std::ios;
using std::vector;
using std::to_string;
using std::string;
using std::istringstream;

class DateCheck
{
public:
    DateCheck(string file1,int add)
    {
        file=file1;
        add_num=add;
    }
    bool check(int num)
    {
        ofstream f1(file,ios::app);
        f1.close();
        ifstream f2(file);
        if(!f2.is_open()) {
            f2.close();
            return false;
        }
        string read_thing;
        f2 >> read_thing;
        f2.close();
        auto result=DateCheck::split(read_thing,'&');
        vector<int> rr;
        for(const auto i: result) {
            rr.push_back(atoi(i.c_str()));
        }
        time_t current_time=0;
        time_t now=time(&current_time);
        tm* timep=localtime(&now);

        int rrt=(timep->tm_year)*10000
                +((timep->tm_mon)+1)*100
                +(timep->tm_mday)+add_num;
        int count=0;
        for(const auto i: rr) {
            if(i==rrt) {
                count++;
                if(count>=num) {
                    return false;
                }
            }
        }
        ofstream f3(file,ios::app);
        f3 << "&";
        f3 << to_string(rrt);
        f3.close();
        return true;
    }
protected:
    string file;
    int add_num;
    static vector<string> split(const string &s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

#endif
