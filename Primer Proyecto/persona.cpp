//
// Created by Santiago on 9/10/2023.
//

#include "persona.h"

persona::persona(string cedula, string nombres, string apellidos, string fechaNacimiento,
                 string genero, string direccion, string numeroTelefono, string correoElectronico) {
    this->cedula = cedula;
    this->nombres = nombres;
    this->apellidos = apellidos;
    this->fechaNacimiento = fechaNacimiento;
    this->genero = genero;
    this->direccion = direccion;
    this->numeroTelefono = numeroTelefono;
    this->correoElectronico = correoElectronico;
}

void persona::ingresarInformacion() {
}

void persona::consultarInformacion(int idPersona) {
}

string persona::getCedula() {
    return cedula;
}

string persona::getNombres() {
    return nombres;
}

string persona::getApellidos() {
    return apellidos;
}

string persona::getFechaNacimiento() {
    return fechaNacimiento;
}

string persona::getGenero() {
    return genero;
}

string persona::getDireccion() {
    return direccion;
}

string persona::getNumeroTelefono() {
    return numeroTelefono;
}

string persona::getCorreoElectronico() {
    return correoElectronico;
}