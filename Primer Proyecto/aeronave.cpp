//
// Created by Santiago on 3/10/2023.
//

#include "aeronave.h"

// Clase padre que permite gestionar clases derivadas como aviones, helicopteros y jets

aeronave::aeronave(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
                   int anioFabricacion, string estado) {
    this->marca = marca;
    this->modelo = modelo;
    this->capacidadPasajeros = capacidadPasajeros;
    this->velocidadMaxima = velocidadMaxima;
    this->autonomia = autonomia;
    this->anioFabricacion = anioFabricacion;
    this->estado = estado;
}

// Los metodos no se usaran directamente desde la clase de aeronave, por lo tanto no se agrega logica a los metodos

void aeronave::ingresarInformacion() {
}

void aeronave::consultarInformacion(int idAeronave) {
}

void aeronave::modificarInformacion(int idAeronave) {
}

// Metodos getters para los atributos "base" que se crean en la clase aeronave y que se heredaran en las clases derivadas

string aeronave::getMarca() {
    return marca;
}

string aeronave::getModelo() {
    return modelo;
}

int aeronave::getCapacidadPasajeros() {
    return capacidadPasajeros;
}

int aeronave::getVelocidadMaxima() {
    return velocidadMaxima;
}

int aeronave::getAutonomia() {
    return autonomia;
}

int aeronave::getAnioFabricacion() {
    return anioFabricacion;
}

string aeronave::getEstado() {
    return estado;
}