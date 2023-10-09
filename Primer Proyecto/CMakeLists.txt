cmake_minimum_required(VERSION 3.26)
project(Primer_Proyecto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Primer_Proyecto main.cpp
        aeronave.cpp
        aeronave.h
        avion.cpp
        avion.h
        helicoptero.cpp
        helicoptero.h
        Jet.cpp
        Jet.h
        vuelo.cpp
        vuelo.h
        persona.cpp
        persona.h
        pasajero.cpp
        pasajero.h
        tripulacion.cpp
        tripulacion.h
        puertaEmbarque.cpp
        puertaEmbarque.h)
