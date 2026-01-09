cmake_minimum_required(VERSION 3.16)

project(Viikkoteht_1_Arvauspeli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Viikkoteht_1_Arvauspeli main.cpp)

include(GNUInstallDirs)
install(TARGETS Viikkoteht_1_Arvauspeli
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
