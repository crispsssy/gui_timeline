cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Gui_Window)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(MAINWINDOW ${CMAKE_CURRENT_SOURCE_DIR}/src/MainWindow.cxx)
target_include_directories(MAINWINDOW PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(MAINWINDOW PUBLIC Qt6::Widgets)

add_executable(Gui_Window ${CMAKE_CURRENT_SOURCE_DIR}/app/main.cxx)
target_link_libraries(Gui_Window PUBLIC  MAINWINDOW)

install(TARGETS Gui_Window DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
