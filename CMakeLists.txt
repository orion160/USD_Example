cmake_minimum_required(VERSION 3.28)
project("USD Example" LANGUAGES C CXX)

find_package(pxr CONFIG REQUIRED)

include_directories(${PXR_INCLUDE_DIRS})
link_libraries(${PXR_LIBRARIES})

add_executable(main)
set_target_properties(main PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
target_sources(main PRIVATE main.cpp)
target_link_libraries(main PRIVATE usd_usdGeom)
