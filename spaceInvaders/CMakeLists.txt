cmake_minimum_required(VERSION 3.10)

project(SpaceInvaders VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE MATCHES "Release")
    message(WARNING "Building for release")
    add_definitions(-DSI_Release)
    add_definitions(-DNDEBUG)
else ()
    message(STATUS "Building for development")
    add_definitions(-DSI_Debug)
endif ()

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_image)
add_subdirectory(external/SDL_mixer)

set(SDL2TTF_VENDORED ON CACHE BOOL "Use vendored third-party libraries for SDL_ttf")
add_subdirectory(external/SDL_ttf)

set(SOURCES src/main.cpp
        src/videomode.hpp
        src/videomode.cpp
        src/globals.hpp
        external/tileson/tileson.hpp
        src/surface.hpp
        src/texture.hpp
        src/font.hpp
        src/sound.hpp
        src/music.hpp
        src/logger.hpp
        src/eventManager.hpp
        src/sceneInterface.hpp
        src/sceneFactory.hpp
        src/titleScene.cpp
        src/gameplayScene.cpp
        src/backgroundTile.cpp
)
add_executable(SpaceInvaders ${SOURCES})

target_include_directories(SpaceInvaders PRIVATE
        ${SDL_INCLUDE_DIR}
        external/tileson/)

target_link_libraries(SpaceInvaders PRIVATE
        SDL2::SDL2
        SDL2_image::SDL2_image
        SDL2_mixer::SDL2_mixer
        SDL2_ttf::SDL2_ttf
)

# Copy the media directory to the output directory
add_custom_target(copy_media ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/media ${CMAKE_BINARY_DIR}/media
        COMMENT "Copying media directory"
)
add_dependencies(SpaceInvaders copy_media)