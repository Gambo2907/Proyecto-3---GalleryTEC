cmake_minimum_required(VERSION 3.20)
project(Proyecto_3_GalleryTEC)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})

add_executable(Proyecto_3_GalleryTEC
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        registerdialog.cpp
        registerdialog.h
        registerdialog.ui
        galleriesdialog.cpp
        galleriesdialog.h
        galleriesdialog.ui
        imagesdialog.cpp
        imagesdialog.h
        imagesdialog.ui
        visualizerdialog.cpp
        visualizerdialog.h
        visualizerdialog.ui
        mongodbHandler.cpp mongodbHandler.h)
target_link_libraries(Proyecto_3_GalleryTEC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        mongo::bsoncxx_shared
        mongo::mongocxx_shared
        )

