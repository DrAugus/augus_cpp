# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.

set(CURRENT_DIR_NAME "linux")
include(${CMAKE_SOURCE_DIR}/cmake/CMakeFunctions.cmake)

file(GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} APP_SOURCES)
set(LANGUAGE "CXX")
foreach_all_files(${LANGUAGE} ${CURRENT_DIR_NAME} ${APP_SOURCES})

file(GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)

# AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} APP_SOURCES)
set(LANGUAGE "C")
foreach_all_files(${LANGUAGE} ${CURRENT_DIR_NAME} ${APP_SOURCES})

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)