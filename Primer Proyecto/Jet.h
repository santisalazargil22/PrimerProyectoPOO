//
// Created by Santiago on 9/10/2023.
//

#ifndef PRIMER_PROYECTO_JET_H
#define PRIMER_PROYECTO_JET_H

#include <iostream>
#include "aeronave.h"

using namespace std;

class jet : public aeronave {
private:
    string propietario;
    string listaServicios;
    string listaDestinosFrecuentes;
    int id;
    static int contadorJets;
    static map<int, jet *> mapaJets;

public:
    jet(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia, int anioFabricacion,
        string estado, string propietario, string listaServicios, string listaDestinosFrecuentes, int id);

    ~jet();

    void ingresarInformacion() override;

    void ingresarJet(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
                     int anioFabricacion, string estado, string propietario, string listaServicios,
                     string listaDestinosFrecuentes);

    void consultarInformacion(int idJet) override;

    void modificarInformacion(int idJet) override;

    string getPropietario();

    string getListaServicios();

    string getListaDestinosFrecuentes();

    static map<int, jet *> getMapaJets();
};

#endif //PRIMER_PROYECTO_JET_H