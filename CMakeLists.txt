cmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)
project(hellozapi CXX)
set(CMAKE_CXX_STANDARD 11)
# register zapi cmake modules, you must modify this according to your self zapi install prefix 
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/zapi")

# here find zendAPI lib
find_package(zendAPI 0.0.1 EXACT REQUIRED CONFIG)

add_library(hellozapi MODULE 
    hellozapi/defs.h
    hellozapi/impls.cpp
    hellozapi/entry.cpp)
set_target_properties(hellozapi PROPERTIES 
    OUTPUT_NAME hellozapi
    PREFIX "")

target_link_libraries(hellozapi ${ZAPI_LIBRARY})
install(TARGETS hellozapi DESTINATION ${ZAPI_PHP_EXTENSION_DIR})
set(PHP_INI_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/assets/php.ini)
# add test
add_custom_target(Tests
    SOURCES 
    tests/test_extloaded.php
    tests/test_const.php
    tests/test_function.php
    tests/test_class.php
    tests/test_ini.php)

enable_testing()

add_test(NAME ExtLoadedTest COMMAND ${ZAPI_PHP_EXECUTABLE} -c ${PHP_INI_FILENAME} tests/test_extloaded.php
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME ConstTest COMMAND ${ZAPI_PHP_EXECUTABLE} -c ${PHP_INI_FILENAME} tests/test_const.php
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME FunctionTest COMMAND ${ZAPI_PHP_EXECUTABLE} -c ${PHP_INI_FILENAME} tests/test_function.php
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME ClassTest COMMAND ${ZAPI_PHP_EXECUTABLE} -c ${PHP_INI_FILENAME} tests/test_class.php
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME IniTest COMMAND ${ZAPI_PHP_EXECUTABLE} -c ${PHP_INI_FILENAME} tests/test_ini.php
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
