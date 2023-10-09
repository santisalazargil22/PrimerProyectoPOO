//
// Created by Santiago on 9/10/2023.
//

#ifndef PRIMER_PROYECTO_HELICOPTERO_H
#define PRIMER_PROYECTO_HELICOPTERO_H

#include <iostream>
#include "aeronave.h"

using namespace std;

class helicoptero : public aeronave {
private:
    int cantidadRotores;
    int capacidadElevacion;
    string usoEspecifico;
    int id;
    static int contadorHelicopteros;
    static map<int, helicoptero *> mapaHelicopteros;

public:
    helicoptero(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
                int anioFabricacion,
                string estado, int cantidadRotores, int capacidadElevacion, string usoEspecifico, int id);

    ~helicoptero();

    void ingresarInformacion() override;

    void ingresarHelicoptero(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
                             int anioFabricacion,
                             string estado, int cantidadRotores, int capacidadElevacion, string usoEspecifico);

    void consultarInformacion(int idHelicoptero) override;

    void modificarInformacion(int idHelicoptero) override;

    int getCantidadRotores();

    int getCapacidadElevacion();

    string getUsoEspecifico();

    static map<int, helicoptero *> getMapaHelicopteros();
};

#endif //PRIMER_PROYECTO_HELICOPTERO_H