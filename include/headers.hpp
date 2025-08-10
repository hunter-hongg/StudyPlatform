#pragma once

// std
#include <sstream> // 字符串流
#include <deque> // 双向队列
#include <vector> // 动态数组
#include <chrono> // 高精度时间
#include <ctime> // C时间处理库
#include <filesystem> // 文件夹创建

// wxWidgets
#include <wx/wx.h> // wxWidgets头文件

// 自定义
#include <var.hpp> // 定义文件变量等
#include <type.hpp> // 定义类型别名等
#include <macro.hpp> // 定义宏等
#include <mine/MyFonts.h> // 定义字体等
#include <mine/MyFlags.h> // 定义对齐方式等
#include <mine/MyColour.h> // 定义颜色等

// 自定义工具
#include <utils/rand.hpp> // 旧随机数生成，现使用ffi/rust/Rand/RandCpp.hpp
#include <utils/new/loger/loger.hpp> // 早期loger，现在已不使用
#include <utils/new/timer/timer.hpp> // 早期实现学习计时使用的Timer

// 辅助函数
#include <functions/ancient/jinjian.hpp> // 古代文官-直言进谏 结果判断模块
#include <functions/ancient/shengguan.hpp> // 古代文官-政绩升官 判断模块
#include <functions/jifen/jifen.hpp> // 早期积分处理函数
#include <functions/xianbi/sword.hpp> // 神话传说-仙器 佩剑选择模块
#include <functions/xianbi/fali.hpp> // 神话传说-法力 判断模块

// FFI(Zig)

// BookShelf
#include <ffi/zig/BookShelf/BookShelfCpp.hpp>
#include <ffi/zig/BookShelf/BookShelfMacro.hpp>

// AncientBaoWu
#include <ffi/zig/AncientBaoWu/AncientBaoWuCpp.hpp>
#include <ffi/zig/AncientBaoWu/AncientBaoWuMacro.hpp>

// AncientWenGuan
#include <ffi/zig/AncientWenGuan/AncientWenGuanCpp.hpp>

// AncientYuZhan
#include <ffi/zig/AncientYuZhan/AncientYuZhanCpp.hpp>

// AncientJinYinZhu
#include <ffi/zig/AncientJinYinZhu/AncientJinYinZhuCpp.hpp>
#include <ffi/zig/AncientJinYinZhu/AncientJinYinZhuMacro.hpp>

// AncientBaoWuCha
#include <ffi/zig/AncientBaoWuCha/AncientBaoWuChaCpp.hpp>
#include <ffi/zig/AncientBaoWuCha/AncientBaoWuChaMacro.hpp>

// AncientGuWanCha
#include <ffi/zig/AncientGuWanCha/AncientGuWanChaCpp.hpp>
#include <ffi/zig/AncientGuWanCha/AncientBaoWuChaMacro.hpp>

// FFI(Rust)

// Rand
#include <ffi/rust/Rand/RandCpp.hpp>

// BaoShiChouJiang1
#include <ffi/rust/BaoShiChouJiang1/BaoShiChouJiang1Cpp.hpp>
#include <ffi/rust/BaoShiChouJiang1/BaoShiChouJiang1Macro.hpp>

// FFI(Golang)

// BookShelfShouCang
#include <ffi/golang/BookShelfShouCang/BookShelfShouCang.hpp> 
                                            // 符号链接指向项目根目录下的.headers_go下的文件

// FFI(D)

// AncientJuanZeng
#include <ffi/d/AncientJuanZeng/AncientJuanZengCpp.hpp>

// 类定义
#include <function.hpp> // 类MyApp以及MyFrame

// EasyCoding
#include <EasyCoding.hpp>

// namespace
using namespace ShengGuanSpace;
using namespace Files;
using namespace Card;
using namespace Check;
