#pragma once
#include <utils/old/datecheck.h>

class CheckFile : protected DateCheck
{
public:
    CheckFile(string file1,int add,int alltimes) : DateCheck(file1,add),all_times(alltimes)
    {}
    bool CheckTimes()
    {
        return this->check(all_times) ;
    }
protected:
    int all_times;
};