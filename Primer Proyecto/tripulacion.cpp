//
// Created by Santiago on 9/10/2023.
//

#include "tripulacion.h"

#include "tripulacion.h"

int tripulacion::contadorTripulacion;
map<int, tripulacion *> tripulacion::mapaTripulacion;

tripulacion::tripulacion(string cedula, string nombres, string apellidos, string fechaNacimiento,
                         string genero, string direccion, string numeroTelefono, string correoElectronico,
                         string puesto, int aniosExperiencia, int horasTrabajoDiarias, int id) : persona(cedula,
                                                                                                         nombres,
                                                                                                         apellidos,
                                                                                                         fechaNacimiento,
                                                                                                         genero,
                                                                                                         direccion,
                                                                                                         numeroTelefono,
                                                                                                         correoElectronico) {
    this->puesto = puesto;
    this->aniosExperiencia = aniosExperiencia;
    this->horasTrabajoDiarias = horasTrabajoDiarias;
    this->id = id;
}

tripulacion::~tripulacion() {
}

void tripulacion::ingresarInformacion() {
    cout << "Cedula de la tripulacion?" << endl;
    cin.ignore();
    getline(cin, cedula);

    cout << "Nombres de la tripulacion?" << endl;
    getline(cin, nombres);

    cout << "Apellidos de la tripulacion?" << endl;
    getline(cin, apellidos);

    cout << "Fecha de nacimiento de la tripulacion?" << endl;
    getline(cin, fechaNacimiento);

    cout << "Genero de la tripulacion?" << endl;
    getline(cin, genero);

    cout << "Direccion de la tripulacion?" << endl;
    getline(cin, direccion);

    cout << "Numero de telefono de la tripulacion?" << endl;
    getline(cin, numeroTelefono);

    cout << "Correo electronico de la tripulacion?" << endl;
    getline(cin, correoElectronico);

    cout << "Puesto de la tripulacion?" << endl;
    getline(cin, puesto);

    cout << "Anios de experiencia de la tripulacion?" << endl;
    cin >> aniosExperiencia;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> aniosExperiencia;
    }

    cout << "Horas de trabajo diarias de la tripulacion?" << endl;
    cin >> horasTrabajoDiarias;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> horasTrabajoDiarias;
    }
}

void tripulacion::ingresarTripulacion(string cedula, string nombres, string apellidos, string fechaNacimiento,
                                      string genero, string direccion, string numeroTelefono, string correoElectronico,
                                      string puesto, int aniosExperiencia, int horasTrabajoDiarias) {
    tripulacion *pTripulacion = new tripulacion(cedula, nombres, apellidos, fechaNacimiento, genero, direccion,
                                                numeroTelefono, correoElectronico, puesto, aniosExperiencia,
                                                horasTrabajoDiarias, contadorTripulacion);
    mapaTripulacion.insert({contadorTripulacion, pTripulacion});
    cout << "Se registro la tripulacion de id " << contadorTripulacion << endl;
    contadorTripulacion++;
}

void tripulacion::consultarInformacion(int idTripulacion) {
    map<int, tripulacion *>::iterator itTripulacion;
    itTripulacion = mapaTripulacion.find(idTripulacion);
    if (itTripulacion != mapaTripulacion.end()) {
        tripulacion *pTripulacion = itTripulacion->second;
        cout << "La tripulacion de id " << idTripulacion << " fue encontrada" << endl;
        cout << "La cedula de la tripulacion es " << pTripulacion->getCedula() << endl;
        cout << "El nombre de la tripulacion es " << pTripulacion->getNombres() << endl;
        cout << "El apellido de la tripulacion es " << pTripulacion->getApellidos() << endl;
        cout << "La fecha de nacimiento de la tripulacion es " << pTripulacion->getFechaNacimiento() << endl;
        cout << "El genero de la tripulacion es " << pTripulacion->getGenero() << endl;
        cout << "La direccion de la tripulacion es " << pTripulacion->getDireccion() << endl;
        cout << "El numero de telefono de la tripulacion es " << pTripulacion->getNumeroTelefono() << endl;
        cout << "El correo electronico de la tripulacion es " << pTripulacion->getCorreoElectronico() << endl;
        cout << "El puesto de la tripulacion es " << pTripulacion->getPuesto() << endl;
        cout << "Los anios de experiencia de la tripulacion son " << pTripulacion->getAniosExperiencia() << " anios"
             << endl;
        cout << "Las horas de trabajo diarias de la tripulacion son " << pTripulacion->getHorasTrabajoDiarias()
             << " horas" << endl;
    } else {
        cout << "No se pudo encontrar el ID de la tripulacion solicitado en el sistema" << endl;
    }
}

string tripulacion::getPuesto() {
    return puesto;
}

int tripulacion::getAniosExperiencia() {
    return aniosExperiencia;
}

int tripulacion::getHorasTrabajoDiarias() {
    return horasTrabajoDiarias;
}

map<int, tripulacion *> tripulacion::getMapaTripulacion() {
    return mapaTripulacion;
}