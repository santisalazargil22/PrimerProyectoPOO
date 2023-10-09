//
// Created by Santiago on 9/10/2023.
//

#ifndef PRIMER_PROYECTO_PERSONA_H
#define PRIMER_PROYECTO_PERSONA_H

#include <iostream>
#include <limits>
#include <map>

using namespace std;

class persona {
protected:
    string cedula;
    string nombres;
    string apellidos;
    string fechaNacimiento;
    string genero;
    string direccion;
    string numeroTelefono;
    string correoElectronico;

public:
    persona(string cedula, string nombres, string apellidos, string fechaNacimiento, string genero, string direccion,
            string numeroTelefono, string correoElectronico);

    virtual void ingresarInformacion() = 0;

    virtual void consultarInformacion(int idPersona) = 0;

    string getCedula();

    string getNombres();

    string getApellidos();

    string getFechaNacimiento();

    string getGenero();

    string getDireccion();

    string getNumeroTelefono();

    string getCorreoElectronico();
};

#endif //PRIMER_PROYECTO_PERSONA_H