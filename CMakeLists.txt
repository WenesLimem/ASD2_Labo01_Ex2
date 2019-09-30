cmake_minimum_required(VERSION 3.14)
project(ASD2_LABO01_ex2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ASD2_LABO01_ex2
        GraphUsingAdjacencyLists.cpp
        GraphUsingAdjacencyLists.h
        main.cpp
        ParcoursEnLargeur.h
        SymbolGraph.h
        Util.cpp
        Util.h)
