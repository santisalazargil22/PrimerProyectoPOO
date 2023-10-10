//
// Created by Santiago on 3/10/2023.
//

#ifndef PRIMER_PROYECTO_AVION_H
#define PRIMER_PROYECTO_AVION_H

#include <iostream>
#include "aeronave.h"

using namespace std;

// Dato importante: Esta clase avion, la clase helicoptero y la clase jet son casi que clones pero con sus respectivas carecteristicas unicas
// Los comentarios que se hagan en esta clase no se pondran en helicoptero ni jet debido a que es la misma logica pero para diferentes clases

// Clase derivada de aeronave que hereda los atributos "base" e ingreso, consulta y modificacion de informacion

class avion : public aeronave {
private:
    int altitudMaxima;
    int cantidadMotores;
    string categoria;
    // Es importante manejar un id que se pondra en el constructor de la clase para poder manejar un id con el que se llamar cada instancia
    int id;
    // Funciones de tipo estatico que permiten un manejo global por parte del programa y permite una lectura por parte de todas las instancias
    // En caso de no implementar manejo estatico puede que las instancias de aeronaves (aviones, helicopteros y jets) no se guarden correctamente
    static int contadorAviones;
    static map<int, avion *> mapaAviones;

public:
    avion(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia, int anioFabricacion,
          string estado, int altitudMaxima, int cantidadMotores, string categoria, int id);

    ~avion();

    // Metodos virtuales de aeronave heredados en las clases derivadas

    void ingresarInformacion() override;

    void ingresarAvion(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
                       int anioFabricacion,
                       string estado, int altitudMaxima, int cantidadMotores, string categoria);

    // Recibimiento de parametro idAvion que permitira referenciar instancias en un mapa y encontrarlas mediante un id

    void consultarInformacion(int idAvion) override;

    void modificarInformacion(int idAvion) override;

    int getAltitudMaxima();

    int getCantidadMotores();

    string getCategoria();

    static map<int, avion *> getMapaAviones();
};

#endif //PRIMER_PROYECTO_AVION_H