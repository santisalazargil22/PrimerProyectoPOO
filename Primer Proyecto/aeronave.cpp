//
// Created by Santiago on 3/10/2023.
//

#include "aeronave.h"

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

void aeronave::ingresarInformacion() {
}

void aeronave::consultarInformacion(int idAeronave) {
}

void aeronave::modificarInformacion(int idAeronave) {
}

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