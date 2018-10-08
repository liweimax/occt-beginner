cmake_minimum_required(VERSION 3.5)

project(OcctBeginnerMFC)


set(CASROOT "$ENV{CASROOT}")
if ("${CASROOT}" STREQUAL "")
    set (CASROOT "${CMAKE_SOURCE_DIR}/occt" CACHE PATH "OCCT ROOT directory")
    message("Please specify the CASROOT directory!")
endif()

message(${CASROOT})


set (OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${MSVC_TOOLSET_VERSION}" CACHE PATH "Output directory")

add_subdirectory(OcctBeginner)