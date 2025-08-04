cmake_minimum_required(VERSION 3.16)
project(CalculetteAmortissement)

# Explique qu'on veut bien une compilation statique
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")

# Chemin vers Qt compilé en statique
set(CMAKE_PREFIX_PATH "C:/QtStatic")

# Options de compilation
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Forcer la compilation statique avec MinGW
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")

# Ajout des fichiers sources
add_executable(CalculetteAmortissement WIN32
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    my_app.rc
)

# Lien avec les modules Qt statiques
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

target_link_libraries(CalculetteAmortissement PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
