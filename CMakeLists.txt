cmake_minimum_required(VERSION 3.19)
project(BMSTestGUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMOC_SCAN_HEADERS ON)

find_package(PkgConfig REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets SerialPort)
pkg_check_modules(LIBSERIAL REQUIRED libserial)

include_directories(
    ${LIBSERIAL_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/inc
)

# qt_standard_project_setup()

add_executable(${PROJECT_NAME}
#   SOURCES    
    src/main.cpp
    src/MainWindow.cpp
    src/BMSTest.cpp
    src/RelayController.cpp
    src/DAQ.cpp
    
#   INCLUDES    
    inc/MainWindow.h
    inc/BMSTest.h
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE Qt6::Core
    PRIVATE Qt6::Widgets
    PRIVATE Qt6::SerialPort
    ${LIBSERIAL_LIBRARIES} 
)