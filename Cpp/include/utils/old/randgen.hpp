#ifndef RANDGEN_HPP
#define RANDGEN_HPP

#include <vector>
#include <chrono>
#include <random>

class RandGen
{
public:
    std::vector<int> generateMulti(int min, int max, int count)
    {
        auto now = std::chrono::high_resolution_clock::now();
        auto timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
        std::mt19937 engine(static_cast<unsigned int>(timestamp));
        std::uniform_int_distribution<> dist(min, max);
        std::vector<int> result;
        for (int i = 0; i < count; ++i) {
            result.push_back(dist(engine));
        }
        return result;
    }

    int generateSingle(int min, int max)
    {
        auto numbers = generateMulti(min, max, 1000);
        auto index = generateMulti(0, 999, 1)[0];
        return numbers[index];
    }
};

#endif
