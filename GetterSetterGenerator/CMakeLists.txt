cmake_minimum_required(VERSION 3.5)

project(GetterSetterGenerator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FIND_PACKAGE( Boost COMPONENTS program_options chrono REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(GetterSetterGenerator boost_main.cpp Variables.cpp Variables.hpp)

TARGET_LINK_LIBRARIES( GetterSetterGenerator LINK_PUBLIC ${Boost_LIBRARIES} )

install(TARGETS GetterSetterGenerator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
