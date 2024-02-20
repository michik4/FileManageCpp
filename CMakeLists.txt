cmake_minimum_required(VERSION 2.8)
project(FileManageC C)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS 
    stdlib.h
    stdio.h
    fstream
    string.h
)


include_directories(
    "include"
)
add_definitions(-DDEBUG)

set(SRC_LIST 
    main.c
    flags/flags_analys.c
    file/rbin/bin_converter.c
    file/name/file_exten.c
    file/copy/file_copy_txt.c
    file/copy/file_copy_bin.c
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

