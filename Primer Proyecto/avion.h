//
// Created by Santiago on 3/10/2023.
//

#ifndef PRIMER_PROYECTO_AVION_H
#define PRIMER_PROYECTO_AVION_H

#include <iostream>
#include "aeronave.h"

using namespace std;

class avion : public aeronave {
private:
    int altitudMaxima;
    int cantidadMotores;
    string categoria;
    int id;
    static int contadorAviones;
    static map<int, avion *> mapaAviones;

public:
    avion(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia, int anioFabricacion,
          string estado, int altitudMaxima, int cantidadMotores, string categoria, int id);

    ~avion();

    void ingresarInformacion() override;

    void ingresarAvion(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
                       int anioFabricacion,
                       string estado, int altitudMaxima, int cantidadMotores, string categoria);

    void consultarInformacion(int idAvion) override;

    void modificarInformacion(int idAvion) override;

    int getAltitudMaxima();

    int getCantidadMotores();

    string getCategoria();

    static map<int, avion *> getMapaAviones();
};

#endif //PRIMER_PROYECTO_AVION_H