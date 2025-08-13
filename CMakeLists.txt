cmake_minimum_required(VERSION 3.10)
project(Proj LANGUAGES CXX)

# 强制使用UTF-8编码
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")

# 设置C++标准为C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_PATH $HOME/学习平台/lib)

# 查找所有源文件
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE STATICLIBS "lib/*/*.a")
file(GLOB_RECURSE SOLIBS "lib/*/*.so")

# 获取wxWidgets编译标志
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

# 添加可执行文件
add_executable(studyplatform ${SRC_FILES})

# 设置包含目录
target_include_directories(studyplatform PRIVATE include)

# 设置链接库
target_link_directories(studyplatform PRIVATE 
    lib/ancient
    lib/ffi
    lib/other
    lib/utils
)
target_link_libraries(studyplatform
    ${wxWidgets_LIBRARIES}
    ${STATICLIBS}
    ${SOLIBS}
)

# 链接EasyCoding
target_include_directories(studyplatform PRIVATE
    /localapp/library/EasyCoding/stable/current/include/
)
target_link_directories(studyplatform PRIVATE
    /localapp/library/EasyCoding/stable/current/lib/
)
target_link_libraries(studyplatform
    libeasycoding.so
)

target_compile_options(studyplatform PRIVATE -w -Wnarrowing )
set(CMAKECXXFLAGS "${CMAKECXXFLAGS} -march=x86-64 -mtune=generic -mno-avx512f -DRELEASE")

# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ../target/)

add_custom_target( AfterAll ALL
    DEPENDS studyplatform 
    COMMAND bash ../.scripts/move.sh
    WORKING_DIRECTORY ../target
)

# add_custom_command(TARGET AfterAll POST_BUILD
#     COMMAND bash ../scripts/run.sh
#     WORKING_DIRECTORY ../target
# )
