# 部分内容请自行更改
cmake_minimum_required(VERSION 3.10)
project(Proj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_PATH $HOME/学习平台/lib) # 自行更改

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE STATICLIBS "lib/*/*.a")
file(GLOB_RECURSE SOLIBS "lib/*/*.so")
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

set(EXECUTABLE_OUTPUT_PATH ../target/)
add_executable(studyplatform 
    ${SRC_FILES}
    tools/MarkdownTool/MainCode/src/markdowntoolmain.cpp  # Markdown笔记管理工具
)
target_compile_options(studyplatform PRIVATE -w)

add_custom_target( AfterAll ALL
    DEPENDS studyplatform 
    COMMAND bash ~/学习平台/shell/copy.sh # 自行更改
    WORKING_DIRECTORY ../target
)

install( TARGETS studyplatform DESTINATION bin )

target_include_directories(studyplatform PRIVATE include)

target_link_directories(studyplatform PRIVATE 
    lib/ancient
    lib/ffi
    lib/other
    lib/utils
    lib/rust
)

target_link_libraries(studyplatform
    ${wxWidgets_LIBRARIES}
    ${STATICLIBS}
    ${SOLIBS}
)

target_include_directories(studyplatform PRIVATE
    /usr/local/include
)

# hunter-hongg/cding
target_include_directories(studyplatform PRIVATE $ENV{HOME}/cding/include)

# GLib GObject
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0 gobject-2.0)
target_compile_options(studyplatform PRIVATE ${GLIB_CFLAGS})
target_link_libraries(studyplatform ${GLIB_LIBRARIES})

# libsigc++
find_package(PkgConfig REQUIRED)
pkg_check_modules(SIGCXX REQUIRED sigc++-3.0)
target_include_directories(studyplatform PRIVATE ${SIGCXX_INCLUDE_DIRS})
target_link_directories(studyplatform PRIVATE ${SIGCXX_LIBRARY_DIRS})
target_link_libraries(studyplatform ${SIGCXX_LIBRARIES})

# hunter-hongg/clog
target_include_directories(studyplatform PRIVATE $ENV{HOME}/clog/include)
target_link_directories(studyplatform PRIVATE $ENV{HOME}/clog/lib/)
target_link_libraries(studyplatform libCLogger.so)

# Markdown笔记管理工具
target_include_directories(studyplatform PRIVATE 
    tools/MarkdownTool/MainCode/include
)

# MarkdownTool系列库
target_include_directories(markdowntool PRIVATE 
    tools/MarkdownTool/MarkdownParser/include 
    tools/MarkdownTool/MarkdownSQLite/include 
    tools/MarkdownTool/MarkdownFile/include 
)
target_link_directories(markdowntool PRIVATE 
    tools/MarkdownTool/MarkdownParser/lib
    tools/MarkdownTool/MarkdownSQLite/lib
)
target_link_libraries(markdowntool 
    libMdSQLite.a 
    libMdParser.a 
)

# 查找 SQLite3 库
find_package(SQLite3 REQUIRED)

# 链接到你的可执行文件
target_link_libraries(markdowntool SQLite::SQLite3)

