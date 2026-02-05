cmake_minimum_required(VERSION 3.16)

project(Viikkoteht_5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Viikkoteht_5 main.cpp
    seuraaja.h seuraaja.cpp
    notifikaattori.h notifikaattori.cpp)

include(GNUInstallDirs)
install(TARGETS Viikkoteht_5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
