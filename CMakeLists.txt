cmake_minimum_required(VERSION 3.10)

project(BrainShuck VERSION 1.0)

add_executable(brainshuck main.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS brainshuck DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VENDOR "Parsa Torbati")
set(CPACK_PACKAGE_DESCRIPTION "Simple Brainf**k interpreter in C++")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_GENERATOR "DragNDrop" "TXZ")
set(CPACK_OUTPUT_FILE_PREFIX cpack_packages)
include(CPack)

