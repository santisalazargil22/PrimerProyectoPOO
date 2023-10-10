//
// Created by Santiago on 3/10/2023.
//

#ifndef PRIMER_PROYECTO_AERONAVE_H
#define PRIMER_PROYECTO_AERONAVE_H

#include <cctype>
#include <iostream>
#include <limits>
#include <map>
#include <stdexcept>
#include <string>

using namespace std;

// Los atributos deben ser protegidos para que las clases derivadas puedan heredarlos y manejarlos en sus instancias

class aeronave {
protected:
    string marca;
    string modelo;
    int capacidadPasajeros;
    int velocidadMaxima;
    int autonomia;
    int anioFabricacion;
    string estado;

public:
    aeronave(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
             int anioFabricacion, string estado);

    // metodos virtuales puros para poder manejar herencia de metodos con nombres iguales

    virtual void ingresarInformacion() = 0;

    virtual void consultarInformacion(int idAeronave) = 0;

    virtual void modificarInformacion(int idAeronave) = 0;

    string getMarca();

    string getModelo();

    int getCapacidadPasajeros();

    int getVelocidadMaxima();

    int getAutonomia();

    int getAnioFabricacion();

    string getEstado();
};

#endif //PRIMER_PROYECTO_AERONAVE_H