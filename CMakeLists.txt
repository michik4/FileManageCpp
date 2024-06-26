cmake_minimum_required(VERSION 2.8.12)
project(FileManageC C)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

include_directories(
    "include"
)
add_definitions(-DDEBUG)

set(SRC_LIST 
    "main.c"
    "flags/flags_analys.c"
    "file/name/exten.c"
    "file/copy/txt.c"
    "file/copy/bin.c"
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

