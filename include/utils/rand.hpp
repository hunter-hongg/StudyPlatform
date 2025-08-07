#pragma once
#include <random>
#include <deque>

class Rand
{
public:
    typedef std::uniform_int_distribution<int> uid;
    int operator() (int start,int end)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        uid dist(start, end);
        return dist(gen);
    }
    std::deque<int> operator() (int start,int end,int number)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        uid dist(start, end);
        std::deque<int> tmp;
        for(int i = 0; i < number; ++i) {
            tmp.push_back(dist(gen));
        }
        return tmp;
    }
};

static Rand GetRandom;

