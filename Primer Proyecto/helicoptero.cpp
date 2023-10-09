//
// Created by Santiago on 9/10/2023.
//

#include "helicoptero.h"

int helicoptero::contadorHelicopteros;
map<int, helicoptero *> helicoptero::mapaHelicopteros;

helicoptero::helicoptero(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima,
                         int autonomia, int anioFabricacion, string estado, int cantidadRotores,
                         int capacidadElevacion, string usoEspecifico, int id) : aeronave(marca, modelo,
                                                                                          capacidadPasajeros,
                                                                                          velocidadMaxima, autonomia,
                                                                                          anioFabricacion, estado) {
    this->cantidadRotores = cantidadRotores;
    this->capacidadElevacion = capacidadElevacion;
    this->usoEspecifico = usoEspecifico;
    this->id = id;
}

helicoptero::~helicoptero() {
}

void helicoptero::ingresarInformacion() {
    cout << "Marca del helicoptero?" << endl;
    cin.ignore();
    getline(cin, marca);

    cout << "Modelo del helicoptero?" << endl;
    getline(cin, modelo);

    do {
        cout << "Estado del helicoptero? (servicio, asignado, mantenimiento)" << endl;
        getline(cin, estado);
        if (estado != "servicio" && estado != "Servicio" && estado != "asignado" && estado != "Asignado" &&
            estado != "mantenimiento" && estado != "Mantenimiento") {
            cout << "Las opciones validas son las de los parentesis" << endl;
        }
    } while (estado != "servicio" && estado != "Servicio" && estado != "asignado" && estado != "Asignado" &&
             estado != "mantenimiento" && estado != "Mantenimiento");

    do {
        cout << "Uso especifico del helicoptero? (rescate, turismo, transporte)" << endl;
        getline(cin, usoEspecifico);
        if (usoEspecifico != "rescate" && usoEspecifico != "Rescate" && usoEspecifico != "turismo" &&
            usoEspecifico != "Turismo" && usoEspecifico != "transporte" && usoEspecifico != "Transporte") {
            cout << "Las opciones validas son las de los parentesis" << endl;
        }
    } while (usoEspecifico != "rescate" && usoEspecifico != "Rescate" && usoEspecifico != "turismo" &&
             usoEspecifico != "Turismo" && usoEspecifico != "transporte" && usoEspecifico != "Transporte");

    cout << "Capacidad de pasajeros del helicoptero?" << endl;
    cin >> capacidadPasajeros;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> capacidadPasajeros;
    }

    cout << "Velocidad maxima del helicoptero?" << endl;
    cin >> velocidadMaxima;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> velocidadMaxima;
    }

    cout << "Autonomia del helicoptero?" << endl;
    cin >> autonomia;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> autonomia;
    }

    cout << "Anio de fabricacion del helicoptero?" << endl;
    cin >> anioFabricacion;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> anioFabricacion;
    }

    cout << "Cantidad de rotores del helicoptero?" << endl;
    cin >> cantidadRotores;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> cantidadRotores;
    }

    cout << "Capacidad de elevacion del helicoptero?" << endl;
    cin >> capacidadElevacion;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> capacidadElevacion;
    }
}

void
helicoptero::ingresarHelicoptero(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima,
                                 int autonomia, int anioFabricacion, string estado, int cantidadRotores,
                                 int capacidadElevacion, string usoEspecifico) {
    helicoptero *pHelicoptero = new helicoptero(marca, modelo, capacidadPasajeros, velocidadMaxima, autonomia,
                                                anioFabricacion, estado, cantidadRotores, capacidadElevacion,
                                                usoEspecifico, contadorHelicopteros);
    mapaHelicopteros.insert({contadorHelicopteros, pHelicoptero});
    cout << "Se registro el helicoptero de id " << contadorHelicopteros << endl;
    contadorHelicopteros++;
}

void helicoptero::consultarInformacion(int idHelicoptero) {
    map<int, helicoptero *>::iterator itHelicoptero;
    itHelicoptero = mapaHelicopteros.find(idHelicoptero);
    if (itHelicoptero != mapaHelicopteros.end()) {
        helicoptero *pHelicoptero = itHelicoptero->second;
        cout << "El helicoptero de id " << idHelicoptero << " fue encontrado" << endl;
        cout << "La marca del helicoptero es " << pHelicoptero->getMarca() << endl;
        cout << "El modelo del helicoptero es " << pHelicoptero->getModelo() << endl;
        cout << "La capacidad de pasajeros es de " << pHelicoptero->getCapacidadPasajeros() << " pasajeros" << endl;
        cout << "La velocidad maxima que alcanza el helicoptero es de " << pHelicoptero->getVelocidadMaxima() << " km/h"
             << endl;
        cout << "La autonomia del helicoptero es de " << pHelicoptero->getAutonomia() << " km" << endl;
        cout << "El anio de fabricacion del helicoptero es " << pHelicoptero->getAnioFabricacion() << endl;
        cout << "El estado del helicoptero es " << pHelicoptero->getEstado() << endl;
        cout << "La cantidad de rotores del helicoptero es de " << pHelicoptero->getCantidadRotores() << " rotores"
             << endl;
        cout << "La capacidad de elevacion es de " << pHelicoptero->getCapacidadElevacion() << " kg" << endl;
        cout << "El uso especifico del helicoptero es " << pHelicoptero->getUsoEspecifico() << endl;
    } else {
        cout << "No se pudo encontrar el ID del helicoptero solicitado en el sistema" << endl;
    }
}

void helicoptero::modificarInformacion(int idHelicoptero) {
    map<int, helicoptero *>::iterator itHelicoptero;
    itHelicoptero = mapaHelicopteros.find(idHelicoptero);
    if (itHelicoptero != mapaHelicopteros.end()) {
        int opcion;
        helicoptero *pHelicoptero = itHelicoptero->second;
        cout << "El helicoptero de id " << idHelicoptero << " sera modificado... Que desea modificar?" << endl;
        cout
                << "1) Marca \n2) Modelo \n3) Capacidad de pasajeros \n4) Velocidad maxima \n5) Autonomia \n6) Anio de fabricacion \n7) Estado \n8) Cantidad de rotores \n9) Capacidad de elevacion \n10) Uso especifico"
                << endl;
        cin >> opcion;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
            cin >> opcion;
        }
        switch (opcion) {
            case 1:
                cout << "Ingrese la nueva marca" << endl;
                cin.ignore();
                getline(cin, pHelicoptero->marca);
                break;
            case 2:
                cout << "Ingrese el nuevo modelo" << endl;
                cin.ignore();
                getline(cin, pHelicoptero->modelo);
                break;
            case 3:
                cout << "Ingrese la nueva capacidad de pasajeros" << endl;
                cin >> pHelicoptero->capacidadPasajeros;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pHelicoptero->capacidadPasajeros;
                }
                break;
            case 4:
                cout << "Ingrese la nueva velocidad maxima" << endl;
                cin >> pHelicoptero->velocidadMaxima;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pHelicoptero->velocidadMaxima;
                }
                break;
            case 5:
                cout << "Ingrese la nueva autonomia" << endl;
                cin >> pHelicoptero->autonomia;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pHelicoptero->autonomia;
                }
                break;
            case 6:
                cout << "Ingrese el nuevo anio de fabricacion" << endl;
                cin >> pHelicoptero->anioFabricacion;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pHelicoptero->anioFabricacion;
                }
                break;
            case 7:
                cin.ignore();
                do {
                    cout << "Ingrese el nuevo estado (servicio, asignado, mantenimiento)" << endl;
                    getline(cin, pHelicoptero->estado);
                    if (pHelicoptero->estado != "servicio" && pHelicoptero->estado != "Servicio" &&
                        pHelicoptero->estado != "asignado" && pHelicoptero->estado != "Asignado" &&
                        pHelicoptero->estado != "mantenimiento" && pHelicoptero->estado != "Mantenimiento") {
                        cout << "Las opciones validas son las de los parentesis" << endl;
                    }
                } while (pHelicoptero->estado != "servicio" && pHelicoptero->estado != "Servicio" &&
                         pHelicoptero->estado != "asignado" && pHelicoptero->estado != "Asignado" &&
                         pHelicoptero->estado != "mantenimiento" && pHelicoptero->estado != "Mantenimiento");
                break;
            case 8:
                cout << "Ingrese la nueva cantidad de rotores" << endl;
                cin >> pHelicoptero->cantidadRotores;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pHelicoptero->cantidadRotores;
                }
                break;
            case 9:
                cout << "Ingrese la nueva capacidad de elevacion" << endl;
                cin >> pHelicoptero->capacidadElevacion;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pHelicoptero->capacidadElevacion;
                }
                break;
            case 10:
                cin.ignore();
                do {
                    cout << "Ingrese el nuevo uso especifico (rescate, turismo, transporte)" << endl;
                    getline(cin, pHelicoptero->usoEspecifico);
                    if (pHelicoptero->usoEspecifico != "rescate" && pHelicoptero->usoEspecifico != "Rescate" &&
                        pHelicoptero->usoEspecifico != "turismo" &&
                        pHelicoptero->usoEspecifico != "Turismo" && pHelicoptero->usoEspecifico != "transporte" &&
                        pHelicoptero->usoEspecifico != "Transporte") {
                        cout << "Las opciones validas son las de los parentesis" << endl;
                    }
                } while (pHelicoptero->usoEspecifico != "rescate" && pHelicoptero->usoEspecifico != "Rescate" &&
                         pHelicoptero->usoEspecifico != "turismo" &&
                         pHelicoptero->usoEspecifico != "Turismo" && pHelicoptero->usoEspecifico != "transporte" &&
                         pHelicoptero->usoEspecifico != "Transporte");
                break;
            default:
                cout << "Opcion digitada invalida" << endl;
                break;
        }
    } else {
        cout << "No se pudo encontrar el ID del helicoptero solicitado en el sistema" << endl;
    }
}

int helicoptero::getCantidadRotores() {
    return cantidadRotores;
}

int helicoptero::getCapacidadElevacion() {
    return capacidadElevacion;
}

string helicoptero::getUsoEspecifico() {
    return usoEspecifico;
}

map<int, helicoptero *> helicoptero::getMapaHelicopteros() {
    return mapaHelicopteros;
}