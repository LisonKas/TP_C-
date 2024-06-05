# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# La version du C++ que l'on souhaite utiliser (dans notre cas C++17)
set(CMAKE_CXX_STANDARD 17)

# Le nom du projet
project(TD09)

add_executable(main src/main.cpp src/graph.hpp src/graph.cpp)

#set(CMAKE_CXX_STANDARD 20)