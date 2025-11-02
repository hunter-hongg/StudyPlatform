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
add_executable(studyplatform ${SRC_FILES})

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
)

target_link_libraries(studyplatform
    ${wxWidgets_LIBRARIES}
    ${STATICLIBS}
    ${SOLIBS}
)

target_include_directories(studyplatform PRIVATE
    /usr/local/include
)

target_include_directories(studyplatform PRIVATE /home/coding/cding/include)

target_compile_options(studyplatform PRIVATE -w -Wnarrowing )

