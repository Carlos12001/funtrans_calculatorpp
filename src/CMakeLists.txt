
# Put the executable into the directory bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# CMake configs
set(CMAKE_CXX_STANDARD 23)

# Find and include Boost Lib
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Select all files
file(GLOB_RECURSE SOURCE_FILES true "./*.cpp" "./*.hpp")

# Create Var PROJECT_SOURCES
set(PROJECT_SOURCES ${SOURCE_FILES})

# Create the executable and add the files to the .exe
add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})

# Add the libraries to the .exe
target_link_libraries(${CMAKE_PROJECT_NAME}
        ${Boost_LIBRARIES})
