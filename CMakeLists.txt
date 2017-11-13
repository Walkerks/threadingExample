cmake_minimum_required(VERSION 3.5)
project(ThreadCounter CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

add_executable(UnsafeThreadCounter unsafethreadcounter.cpp)
add_executable(SafeThreadCounter safethreadcounter.cpp)
add_executable(SafeThreadCounterInorder safethreadcounterinorder.cpp)
