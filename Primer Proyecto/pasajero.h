//
// Created by Santiago on 9/10/2023.
//

#ifndef PRIMER_PROYECTO_PASAJERO_H
#define PRIMER_PROYECTO_PASAJERO_H

#include <iostream>
#include "persona.h"

// Misma logica utilizada en las clases correspondientes a avion, helicoptero y jet... con la diferencia de que
// aqui no existe un metodo para modificacion de datos de una instancia, en este caso la correspondiente a pasajero
// Lo mismo para la clase tripulacion, por lo tanto no vale la pena comentarla

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