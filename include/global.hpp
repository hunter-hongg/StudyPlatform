#pragma once
#include <chrono>
#include <vector>
#include <clibs/ancient/ChuZheng.hpp>
namespace Global {
namespace AncientWuGuanChuZheng {
static int bingl_ot = -1;
static int bingl_sf = -1;
}
namespace AncientWuGuanChuZhengReal {
static int bingl_ot_now = -1;
static int bingl_sf_now = -1;
static std::vector<WuGuanChuZheng::Choices> usr_cho({});
}
namespace AncientBookstoreJiaomai {
inline int times = 0;
inline std::chrono::steady_clock::time_point PushStart;
inline std::chrono::steady_clock::time_point PushEnd;
}
}
