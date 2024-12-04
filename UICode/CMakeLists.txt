cmake_minimum_required(VERSION 3.15)  # Minimum required CMake version
project(CalculatorApp)              # Project name 

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find wxWidgets package (ensure this is done before any wxWidgets variables are used)
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Add all source files from the current directory and subdirectories (e.g., Modules)
file(GLOB SOURCES 
    ${CMAKE_SOURCE_DIR}/main.cpp                # Main source file
    ${CMAKE_SOURCE_DIR}/../Variable/*.cpp       # All source files in Variable directory
    ${CMAKE_SOURCE_DIR}/../StatisticsCode/*.cpp
    ${CMAKE_SOURCE_DIR}/../ConversionsCode/*.cpp
    ${CMAKE_SOURCE_DIR}/../GraphingFunction/*.cpp
    ${CMAKE_SOURCE_DIR}/../BaseCalculator/*.cpp
    ${CMAKE_SOURCE_DIR}/*.cpp                   # Any other source files in UICode
)

# Add executable first
add_executable(CalculatorApp ${SOURCES})

# Include directories (for header files)
target_include_directories(CalculatorApp PRIVATE 
    ${CMAKE_SOURCE_DIR}/../BaseCalculator  # Path to header files
    ${CMAKE_SOURCE_DIR}/../ConversionsCode
    ${CMAKE_SOURCE_DIR}/../GraphingFunction
    ${CMAKE_SOURCE_DIR}/../StatisticsCode
    ${CMAKE_SOURCE_DIR}/../Variable
    ${CMAKE_SOURCE_DIR}/
    ${wxWidgets_INCLUDE_DIRS}       # wxWidgets headers
)

# Link wxWidgets to your executable
target_link_libraries(CalculatorApp ${wxWidgets_LIBRARIES})

# Include the necessary directories for wxWidgets
include(${wxWidgets_USE_FILE})
