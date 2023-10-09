//
// Created by Santiago on 9/10/2023.
//

#ifndef PRIMER_PROYECTO_PASAJERO_H
#define PRIMER_PROYECTO_PASAJERO_H

#include <iostream>
#include "persona.h"

using namespace std;

class pasajero : public persona {
private:
    string nacionalidad;
    int cantidadMaletas;
    string informacionMedica;
    int id;
    static int contadorPasajeros;
    static map<int, pasajero *> mapaPasajeros;

public:
    pasajero(string cedula, string nombres, string apellidos, string fechaNacimiento, string genero, string direccion,
             string numeroTelefono, string correoElectronico, string nacionalidad, int cantidadMaletas,
             string informacionMedica, int id);

    ~pasajero();

    void ingresarInformacion() override;

    void ingresarPasajero(string cedula, string nombres, string apellidos, string fechaNacimiento, string genero,
                          string direccion,
                          string numeroTelefono, string correoElectronico, string nacionalidad, int cantidadMaletas,
                          string informacionMedica);

    void consultarInformacion(int idPasajero) override;

    string getNacionalidad();

    int getCantidadMaletas();

    string getInformacionMedica();

    static map<int, pasajero *> getMapaPasajeros();
};

#endif //PRIMER_PROYECTO_PASAJERO_H