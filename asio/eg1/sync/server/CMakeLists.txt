# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (server)

include_directories(/usr/local/include)

# Add an executable
add_executable(server server.cpp)
 
target_link_libraries(server /usr/local/lib/libboost_system.a pthread)
