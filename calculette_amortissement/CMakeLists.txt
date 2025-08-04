cmake_minimum_required(VERSION 3.16)
project(CalculetteAmortissement)

set(CMAKE_PREFIX_PATH "C:/QtStatic")  # ton chemin Qt

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOUIC ON)  # active la génération automatique de ui_*.h
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)  # si tu utilises des ressources .qrc

add_executable(CalculetteAmortissement WIN32
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    my_app.rc
)

target_link_libraries(CalculetteAmortissement PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

