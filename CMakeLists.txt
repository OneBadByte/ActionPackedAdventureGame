cmake_minimum_required(VERSION 3.3)
project(ActionPackedAdventureGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Tools.cpp Tools.h Entity.cpp Entity.h Screen.cpp Screen.h Items.cpp Items.h Img/Welcome.bmp Level.cpp Level.h Thread.cpp Thread.h)
add_executable(ActionPackedAdventureGame ${SOURCE_FILES})


INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)


INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})