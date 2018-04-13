cmake_minimum_required(VERSION 3.10)
project(VocalChat)

set(CMAKE_CXX_STANDARD 11)

add_executable(VocalChat main.cpp UDP.cpp UDP.h Chat.cpp Chat.h UDPServer.cpp UDPServer.h UDPClient.cpp UDPClient.h)

if (MINGW)
    target_link_libraries(VocalChat ws2_32)
endif()