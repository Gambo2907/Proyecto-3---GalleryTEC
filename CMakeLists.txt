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
        )
target_link_libraries(Proyecto_3_GalleryTEC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

