cmake_minimum_required (VERSION 2.6)
project (spam)
find_package(Boost COMPONENTS python)
find_package(PythonLibs 2.7)
find_package(PythonInterp 2.7 EXACT REQUIRED)
include_directories(
    ${Boost_INCLUDE_DIRS}
    "/usr/include/python2.7"
    )
python_add_module(spam spam.cpp)
target_link_libraries(spam
    "/usr/lib/x86_64-linux-gnu/libpython2.7.so"
    ${Boost_LIBRARIES}
    )
