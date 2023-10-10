//
// Created by Santiago on 9/10/2023.
//

#include "pasajero.h"

// Misma logica utilizada en las clases correspondientes a avion, helicoptero y jet... con la diferencia de que
// aqui no existe un metodo para modificacion de datos de una instancia, en este caso la correspondiente a pasajero
// Lo mismo para la clase tripulacion, por lo tanto no vale la pena comentarla

int pasajero::contadorPasajeros;
map<int, pasajero *> pasajero::mapaPasajeros;

pasajero::pasajero(string cedula, string nombres, string apellidos, string fechaNacimiento,
                   string genero, string direccion, string numeroTelefono, string correoElectronico,
                   string nacionalidad, int cantidadMaletas, string informacionMedica, int id) : persona(cedula,
                                                                                                         nombres,
                                                                                                         apellidos,
                                                                                                         fechaNacimiento,
                                                                                                         genero,
                                                                                                         direccion,
                                                                                                         numeroTelefono,
                                                                                                         correoElectronico) {
    this->nacionalidad = nacionalidad;
    this->cantidadMaletas = cantidadMaletas;
    this->informacionMedica = informacionMedica;
    this->id = id;
}

pasajero::~pasajero() {
}

void pasajero::ingresarInformacion() {
    cout << "Cedula del pasajero?" << endl;
    cin.ignore();
    getline(cin, cedula);

    cout << "Nombres del pasajero?" << endl;
    getline(cin, nombres);

    cout << "Apellidos del pasajero?" << endl;
    getline(cin, apellidos);

    cout << "Fecha de nacimiento del pasajero?" << endl;
    getline(cin, fechaNacimiento);

    cout << "Genero del pasajero?" << endl;
    getline(cin, genero);

    cout << "Direccion del pasajero?" << endl;
    getline(cin, direccion);

    cout << "Numero de telefono del pasajero?" << endl;
    getline(cin, numeroTelefono);

    cout << "Correo electronico del pasajero?" << endl;
    getline(cin, correoElectronico);

    cout << "Nacionalidad del pasajero?" << endl;
    getline(cin, nacionalidad);

    cout << "Informacion medica del pasajero?" << endl;
    getline(cin, informacionMedica);

    cout << "Cantidad de maletas del pasajero?" << endl;
    cin >> cantidadMaletas;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> cantidadMaletas;
    }
}

void pasajero::ingresarPasajero(string cedula, string nombres, string apellidos, string fechaNacimiento,
                                string genero, string direccion, string numeroTelefono, string correoElectronico,
                                string nacionalidad, int cantidadMaletas, string informacionMedica) {
    pasajero *pPasajero = new pasajero(cedula, nombres, apellidos, fechaNacimiento, genero, direccion,
                                       numeroTelefono, correoElectronico, nacionalidad, cantidadMaletas,
                                       informacionMedica, contadorPasajeros);
    mapaPasajeros.insert({contadorPasajeros, pPasajero});
    cout << "Se registro el pasajero de id " << contadorPasajeros << endl;
    contadorPasajeros++;
}

void pasajero::consultarInformacion(int idPasajero) {
    map<int, pasajero *>::iterator itPasajero;
    itPasajero = mapaPasajeros.find(idPasajero);
    if (itPasajero != mapaPasajeros.end()) {
        pasajero *pPasajero = itPasajero->second;
        cout << "El pasajero de id " << idPasajero << " fue encontrado" << endl;
        cout << "La cedula del pasajero es " << pPasajero->getCedula() << endl;
        cout << "El nombre del pasajero es " << pPasajero->getNombres() << endl;
        cout << "El apellido del pasajero es " << pPasajero->getApellidos() << endl;
        cout << "La fecha de nacimiento del pasajero es " << pPasajero->getFechaNacimiento() << endl;
        cout << "El genero del pasajero es " << pPasajero->getGenero() << endl;
        cout << "La direccion del pasajero es " << pPasajero->getDireccion() << endl;
        cout << "El numero de telefono de pasajero es " << pPasajero->getNumeroTelefono() << endl;
        cout << "El correo electronico del pasajero es " << pPasajero->getCorreoElectronico() << endl;
        cout << "La nacionalidad del pasajero es " << pPasajero->getNacionalidad() << endl;
        cout << "La cantidad de maletas del pasajero es " << pPasajero->getCantidadMaletas() << " maletas" << endl;
        cout << "La informacion medica del pasajero es " << pPasajero->getInformacionMedica() << endl;
    } else {
        cout << "No se pudo encontrar el ID del pasajero solicitado en el sistema" << endl;
    }
}

string pasajero::getNacionalidad() {
    return nacionalidad;
}

int pasajero::getCantidadMaletas() {
    return cantidadMaletas;
}

string pasajero::getInformacionMedica() {
    return informacionMedica;
}

map<int, pasajero *> pasajero::getMapaPasajeros() {
    return mapaPasajeros;
}