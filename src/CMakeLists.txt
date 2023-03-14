#网络库*.cpp文件链接到一个共享库中,共享库名 web_shared
file(GLOB_RECURSE web_sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(web_shared SHARED ${web_sources})