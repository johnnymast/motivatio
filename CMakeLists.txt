cmake_minimum_required(VERSION 4.0)
project(motivatio)

set(CMAKE_CXX_STANDARD 17)
set(JSON_BuildTests OFF CACHE INTERNAL "")
set(CMAKE_POLICY_VERSION_MINIMUM 4.0)

if (WIN32)   # Check if we're on Windows
    set(RESOURCE_INSTALL_PATH ${CMAKE_BINARY_DIR} + "/quotes")
else ()      # Assume we're on a POSIX-like system if not Windows
    set(RESOURCE_INSTALL_PATH "/usr/share/motivatio")
endif ()


add_compile_definitions(JSON_BuildTest=Off)
add_definitions("-DRESOURCE_INSTALL_PATH=\"${RESOURCE_INSTALL_PATH}\"")

include(FetchContent)
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
        cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
        GIT_TAG v3.3.1
)

include(FetchContent)

FetchContent_Declare(
        termcolor
        GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor.git
        GIT_TAG v2.1.0  # adjust as needed
)
include(FetchContent)

FetchContent_MakeAvailable(termcolor)

include(FetchContent)
FetchContent_Declare(
        cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
        GIT_TAG v2.3.0
)

FetchContent_MakeAvailable(cxxopts)

add_executable(${PROJECT_NAME} main.cpp
        src/parser.cpp
        src/quotes.cpp
        src/cli.cpp
)


target_include_directories(${PROJECT_NAME} PRIVATE ${cxxopts_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${cxxopts_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} termcolor::termcolor)

install(DIRECTORY quotes DESTINATION ${RESOURCE_INSTALL_PATH})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
