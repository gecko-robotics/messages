cmake_minimum_required(VERSION 3.25.0)
project(messages VERSION 2024.09.30.0 LANGUAGES CXX)

# set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(PROJECT_IS_TOP_LEVEL)
    cmake_host_system_information(RESULT HOST QUERY HOSTNAME)
    cmake_host_system_information(RESULT OSN QUERY OS_NAME)
    cmake_host_system_information(RESULT OS_VERSION QUERY OS_RELEASE)
    cmake_host_system_information(RESULT PROC QUERY PROCESSOR_DESCRIPTION)

    message(STATUS "-------------------------------------")
    message(STATUS "  Project: ${PROJECT_NAME}")
    message(STATUS "  Version: ${CMAKE_PROJECT_VERSION}")
    message(STATUS "  C++ ${CMAKE_CXX_STANDARD}")
    message(STATUS "  C ${CMAKE_C_STANDARD}")
    message(STATUS "-------------------------------------")
    message(STATUS " ${HOST}")
    message(STATUS " ${OSN}: ${OS_VERSION}")
    message(STATUS " ${PROC}")
    message(STATUS "-------------------------------------")

    set(BUILD_EXAMPLES ON)
    set(BUILD_TESTS ON)
else()
    message(STATUS "-> ${PROJECT_NAME} is submodule")
    set(BUILD_EXAMPLES OFF)
    set(BUILD_TESTS OFF)
endif()

link_directories(/opt/homebrew/lib)
include_directories(/opt/homebrew/include)

# message(STATUS "-> ${PROJECT_NAME}: yivo is set: ${USE_YIVO}")
message(STATUS "-> ${PROJECT_NAME}: scruffy is set: ${BUILD_TESTS}")
message(STATUS "-> ${PROJECT_NAME}: examples are set: ${BUILD_EXAMPLES}")

set(DEST ${CMAKE_SOURCE_DIR}/src)
file(GLOB MSGS "${CMAKE_SOURCE_DIR}/proto/*.proto")

execute_process(
    COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/src
    COMMAND protoc --cpp_out=${DEST} --proto_path=${CMAKE_SOURCE_DIR}/proto ${MSGS}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

file(GLOB HDRS "${CMAKE_SOURCE_DIR}/src/*.h")
file(GLOB SRCS "${CMAKE_SOURCE_DIR}/src/*.cc")

add_library(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} PUBLIC protobuf)
# add_custom_command(TARGET ${PROJECT_NAME} PRE_LINK
#     COMMAND mkdir -p ${DEST} && protoc --cpp_out=${DEST} --proto_path=${CMAKE_SOURCE_DIR}/proto ${MSGS}
# )

