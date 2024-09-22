cmake_minimum_required(VERSION 3.10)

project(SpaceInvaders VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE MATCHES "SI_RELEASE")
    message(WARNING "Building for release")
    add_definitions(-DSI_RELEASE)
else()
    message(STATUS "Building for development")
endif()

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_image)
add_subdirectory(external/SDL_mixer)

set(SDL2TTF_VENDORED ON CACHE BOOL "Use vendored third-party libraries for SDL_ttf")
add_subdirectory(external/SDL_ttf)
add_subdirectory(external/json)

set(SOURCES src/main.cpp)
add_executable(SpaceInvaders ${SOURCES})

target_include_directories(SpaceInvaders PRIVATE ${SDL_INCLUDE_DIR})

target_link_libraries(SpaceInvaders PRIVATE
        SDL2::SDL2
        SDL2_image::SDL2_image
        SDL2_mixer::SDL2_mixer
        SDL2_ttf::SDL2_ttf
        nlohmann_json::nlohmann_json
)
