cmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)
project(hellozapi CXX)
set(CMAKE_CXX_STANDARD 11)
# register zapi cmake modules, you must modify this according to your self zapi install prefix 
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/zapi")

# here find zendAPI lib
find_package(zendAPI 0.0.1 EXACT REQUIRED CONFIG)

add_library(hellozapi MODULE 
    hellozapi/defs.h
    hellozapi/entry.cpp)
set_target_properties(hellozapi PROPERTIES 
    OUTPUT_NAME hellozapi
    PREFIX "")

target_link_libraries(hellozapi ${ZAPI_LIBRARIES})
install(TARGETS hellozapi DESTINATION ${ZAPI_PHP_EXTENSION_DIR})
