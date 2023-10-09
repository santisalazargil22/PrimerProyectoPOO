//
// Created by Santiago on 9/10/2023.
//

#ifndef PRIMER_PROYECTO_TRIPULACION_H
#define PRIMER_PROYECTO_TRIPULACION_H

#include <iostream>
#include "persona.h"

using namespace std;

class tripulacion : public persona {
private:
    string puesto;
    int aniosExperiencia;
    int horasTrabajoDiarias;
    int id;
    static int contadorTripulacion;
    static map<int, tripulacion *> mapaTripulacion;

public:
    tripulacion(string cedula, string nombres, string apellidos, string fechaNacimiento, string genero,
                string direccion,
                string numeroTelefono, string correoElectronico, string puesto, int aniosExperiencia,
                int horasTrabajoDiarias, int id);

    ~tripulacion();

    void ingresarInformacion() override;

    void ingresarTripulacion(string cedula, string nombres, string apellidos, string fechaNacimiento, string genero,
                             string direccion, string numeroTelefono, string correoElectronico, string puesto,
                             int aniosExperiencia, int horasTrabajoDiarias);

    void consultarInformacion(int idTripulacion) override;

    string getPuesto();

    int getAniosExperiencia();

    int getHorasTrabajoDiarias();

    static map<int, tripulacion *> getMapaTripulacion();
};

#endif //PRIMER_PROYECTO_TRIPULACION_H