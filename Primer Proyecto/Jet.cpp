//
// Created by Santiago on 9/10/2023.
//

#include "jet.h"

int jet::contadorJets;
map<int, jet *> jet::mapaJets;

jet::jet(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima,
         int autonomia, int anioFabricacion, string estado, string propietario,
         string listaServicios, string listaDestinosFrecuentes, int id) : aeronave(marca, modelo,
                                                                                   capacidadPasajeros,
                                                                                   velocidadMaxima,
                                                                                   autonomia,
                                                                                   anioFabricacion,
                                                                                   estado) {
    this->propietario = propietario;
    this->listaServicios = listaServicios;
    this->listaDestinosFrecuentes = listaDestinosFrecuentes;
    this->id = id;
}

jet::~jet() {
}

void jet::ingresarInformacion() {
    cout << "Marca del jet?" << endl;
    cin.ignore();
    getline(cin, marca);

    cout << "Modelo del jet?" << endl;
    getline(cin, modelo);

    do {
        cout << "Estado del jet? (servicio, asignado, mantenimiento)" << endl;
        getline(cin, estado);
        if (estado != "servicio" && estado != "Servicio" && estado != "asignado" && estado != "Asignado" &&
            estado != "mantenimiento" && estado != "Mantenimiento") {
            cout << "Las opciones validas son las de los parentesis" << endl;
        }
    } while (estado != "servicio" && estado != "Servicio" && estado != "asignado" && estado != "Asignado" &&
             estado != "mantenimiento" && estado != "Mantenimiento");

    cout << "Propietario del jet?" << endl;
    getline(cin, propietario);

    cout << "Lista de servicios contratados del jet?" << endl;
    getline(cin, listaServicios);

    cout << "Lista de destinos frecuentes del jet?" << endl;
    getline(cin, listaDestinosFrecuentes);

    cout << "Capacidad de pasajeros del jet?" << endl;
    cin >> capacidadPasajeros;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> capacidadPasajeros;
    }

    cout << "Velocidad maxima del jet?" << endl;
    cin >> velocidadMaxima;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> velocidadMaxima;
    }

    cout << "Autonomia del jet?" << endl;
    cin >> autonomia;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> autonomia;
    }

    cout << "Anio de fabricacion del jet?" << endl;
    cin >> anioFabricacion;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> anioFabricacion;
    }
}

void
jet::ingresarJet(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
                 int anioFabricacion, string estado, string propietario, string listaServicios,
                 string listaDestinosFrecuentes) {
    jet *pJet = new jet(marca, modelo, capacidadPasajeros, velocidadMaxima, autonomia, anioFabricacion, estado,
                        propietario, listaServicios, listaDestinosFrecuentes, contadorJets);
    mapaJets.insert({contadorJets, pJet});
    cout << "Se registro el jet de id " << contadorJets << endl;
    contadorJets++;
}

void jet::consultarInformacion(int idJet) {
    map<int, jet *>::iterator itJet;
    itJet = mapaJets.find(idJet);
    if (itJet != mapaJets.end()) {
        jet *pJet = itJet->second;
        cout << "El jet de id " << idJet << " fue encontrado" << endl;
        cout << "La marca del jet es " << pJet->getMarca() << endl;
        cout << "El modelo del jet es " << pJet->getModelo() << endl;
        cout << "La capacidad de pasajeros es de " << pJet->getCapacidadPasajeros() << " pasajeros" << endl;
        cout << "La velocidad maxima que alcanza el jet es de " << pJet->getVelocidadMaxima() << " km/h" << endl;
        cout << "La autonomia del jet es de " << pJet->getAutonomia() << " km" << endl;
        cout << "El anio de fabricacion del jet es " << pJet->getAnioFabricacion() << endl;
        cout << "El estado del jet es " << pJet->getEstado() << endl;
        cout << "El propietario del jet es " << pJet->getPropietario() << endl;
        cout << "Lista de servicios contratados del jet: " << pJet->getListaServicios() << endl;
        cout << "Lista de destinos frecuentes del jet: " << pJet->getListaDestinosFrecuentes() << endl;
    } else {
        cout << "No se pudo encontrar el ID del jet solicitado en el sistema" << endl;
    }
}

void jet::modificarInformacion(int idJet) {
    map<int, jet *>::iterator itJet;
    itJet = mapaJets.find(idJet);
    if (itJet != mapaJets.end()) {
        int opcion;
        jet *pJet = itJet->second;
        cout << "El jet de id " << idJet << " sera modificado... Que desea modificar?" << endl;
        cout
                << "1) Marca \n2) Modelo \n3) Capacidad de pasajeros \n4) Velocidad maxima \n5) Autonomia \n6) Anio de fabricacion \n7) Estado \n8) Propietario \n9) Lista de Servicios \n10) Lista de Destinos Frecuentes"
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
                getline(cin, pJet->marca);
                break;
            case 2:
                cout << "Ingrese el nuevo modelo" << endl;
                cin.ignore();
                getline(cin, pJet->modelo);
                break;
            case 3:
                cout << "Ingrese la nueva capacidad de pasajeros" << endl;
                cin >> pJet->capacidadPasajeros;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pJet->capacidadPasajeros;
                }
                break;
            case 4:
                cout << "Ingrese la nueva velocidad maxima" << endl;
                cin >> pJet->velocidadMaxima;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pJet->velocidadMaxima;
                }
                break;
            case 5:
                cout << "Ingrese la nueva autonomia" << endl;
                cin >> pJet->autonomia;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pJet->autonomia;
                }
                break;
            case 6:
                cout << "Ingrese el nuevo anio de fabricacion" << endl;
                cin >> pJet->anioFabricacion;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pJet->anioFabricacion;
                }
                break;
            case 7:
                cin.ignore();
                do {
                    cout << "Ingrese el nuevo estado (servicio, asignado, mantenimiento)" << endl;
                    getline(cin, pJet->estado);
                    if (pJet->estado != "servicio" && pJet->estado != "Servicio" &&
                        pJet->estado != "asignado" && pJet->estado != "Asignado" &&
                        pJet->estado != "mantenimiento" && pJet->estado != "Mantenimiento") {
                        cout << "Las opciones validas son las de los parentesis" << endl;
                    }
                } while (pJet->estado != "servicio" && pJet->estado != "Servicio" &&
                         pJet->estado != "asignado" && pJet->estado != "Asignado" &&
                         pJet->estado != "mantenimiento" && pJet->estado != "Mantenimiento");
                break;
            case 8:
                cout << "Ingrese el nuevo propietario" << endl;
                cin.ignore();
                getline(cin, pJet->propietario);
                break;
            case 9:
                cout << "Ingrese la nueva lista de servicios" << endl;
                cin.ignore();
                getline(cin, pJet->listaServicios);
                break;
            case 10:
                cout << "Ingrese la nueva lista de destinos frecuentes" << endl;
                cin.ignore();
                getline(cin, pJet->listaDestinosFrecuentes);
                break;
            default:
                cout << "Opcion digitada invalida" << endl;
                break;
        }
    }
}

string jet::getPropietario() {
    return propietario;
}

string jet::getListaServicios() {
    return listaServicios;
}

string jet::getListaDestinosFrecuentes() {
    return listaDestinosFrecuentes;
}

map<int, jet *> jet::getMapaJets() {
    return mapaJets;
}