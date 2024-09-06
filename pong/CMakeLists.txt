cmake_minimum_required(VERSION 3.10)

project(Pong VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE MATCHES "Release")
    message(WARNING "Building for release")
    add_definitions(-DRelease)
else ()
    message(STATUS "Building for development")
    file(COPY ${CMAKE_SOURCE_DIR}/media DESTINATION ${CMAKE_BINARY_DIR})
endif ()

set(SOURCES
        src/main.cpp
        src/pong.hpp
        src/pong.cpp
        src/pathutils.hpp
        src/pathutils.cpp
        src/logger.hpp
)
if (CMAKE_BUILD_TYPE MATCHES "Release")
    add_executable(Pong MACOSX_BUNDLE ${SOURCES})
else ()
    add_executable(Pong ${SOURCES})
endif ()


find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Pong PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

if (CMAKE_BUILD_TYPE MATCHES "Release")
    if (APPLE)
        install(TARGETS Pong
                BUNDLE DESTINATION "."
                RUNTIME DESTINATION "bin"
                LIBRARY DESTINATION "lib"
                ARCHIVE DESTINATION "lib/static"
        )

        include(CPack)
        set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
        set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
        set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Pong game using SFML")
        set(CPACK_PACKAGE_VENDOR "bluesentinelsec")
        set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")

        set(CPACK_GENERATOR "Bundle")
        set_target_properties(Pong PROPERTIES MACOSX_BUNDLE TRUE)
        set_target_properties(Pong PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER "com.bluesentinelsec.Pong")
        set_target_properties(Pong PROPERTIES MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}")
        set_target_properties(Pong PROPERTIES MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")
        set_target_properties(Pong PROPERTIES MACOSX_BUNDLE TRUE)
        set_target_properties(Pong PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/media/macos/Info.plist")
    endif ()
endif ()
