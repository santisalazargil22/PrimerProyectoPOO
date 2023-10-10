//
// Created by Santiago on 3/10/2023.
//

#include "avion.h"

// Inicializacion del contador de aeronave correspondiente que funcionara como llave de la instancia en el mapa
// Inicializacion del mapa tambien, esto me permitira el manejo global del contador y del mapa

int avion::contadorAviones;
map<int, avion *> avion::mapaAviones;

// Constructor donde especifican los atributos heredados y se inicializan los "especificos de la clase heredada"

avion::avion(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
             int anioFabricacion, string estado, int altitudMaxima, int cantidadMotores, string categoria, int id)
        : aeronave(
        marca, modelo, capacidadPasajeros, velocidadMaxima, autonomia, anioFabricacion, estado) {
    this->altitudMaxima = altitudMaxima;
    this->cantidadMotores = cantidadMotores;
    this->categoria = categoria;
    this->id = id;
}

avion::~avion() {
}

void avion::ingresarInformacion() {
    cout << "Marca del avion?" << endl;
    cin.ignore();
    getline(cin, marca);

    // Funcion cin.ignore() para borrar el buffer de entrada del cin y permitir manejo de entradas de tipo string con espacios de por medio

    cout << "Modelo del avion?" << endl;
    getline(cin, modelo);

    do {
        cout << "Estado del avion? (servicio, asignado, mantenimiento)" << endl;
        getline(cin, estado);
        if (estado != "servicio" && estado != "Servicio" && estado != "asignado" && estado != "Asignado" &&
            estado != "mantenimiento" && estado != "Mantenimiento") {
            cout << "Las opciones validas son las de los parentesis" << endl;
        }
    } while (estado != "servicio" && estado != "Servicio" && estado != "asignado" && estado != "Asignado" &&
             estado != "mantenimiento" && estado != "Mantenimiento");

    // Casos do while que se aseguran que se sigan pidiendo datos mientras la entrada no sea una de las estimadas

    do {
        cout << "Categoria del avion? (comercial, carga)" << endl;
        getline(cin, categoria);
        if (categoria != "comercial" && categoria != "Comercial" && categoria != "carga" && categoria != "Carga") {
            cout << "Las opciones validas son las de los parentesis" << endl;
        }
    } while (categoria != "comercial" && categoria != "Comercial" && categoria != "carga" && categoria != "Carga");

    // Manejo de caso donde se espera un valor int y se mete uno distinto, si la entrada esperada falla se limpia la bandera de error
    // despues se limpian TODOS los valores de entrada del buffer correspondientes a la entrada errada y finalmente vuelve a pedir el dato

    cout << "Capacidad de pasajeros del avion?" << endl;
    cin >> capacidadPasajeros;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> capacidadPasajeros;
    }

    cout << "Velocidad maxima del avion?" << endl;
    cin >> velocidadMaxima;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> velocidadMaxima;
    }

    cout << "Autonomia del avion?" << endl;
    cin >> autonomia;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> autonomia;
    }

    cout << "Anio de fabricacion del avion?" << endl;
    cin >> anioFabricacion;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> anioFabricacion;
    }

    cout << "Altitud maxima del avion?" << endl;
    cin >> altitudMaxima;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> altitudMaxima;
    }

    cout << "Cantidad de motores del avion?" << endl;
    cin >> cantidadMotores;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
        cin >> cantidadMotores;
    }
}

void
avion::ingresarAvion(string marca, string modelo, int capacidadPasajeros, int velocidadMaxima, int autonomia,
                     int anioFabricacion, string estado, int altitudMaxima, int cantidadMotores,
                     string categoria) {
    avion *pAvion = new avion(marca, modelo, capacidadPasajeros, velocidadMaxima, autonomia, anioFabricacion,
                              estado, altitudMaxima, cantidadMotores, categoria, contadorAviones);
    // Nueva instancia que se crea y recibe dentro de su constructor como id de referencia un contador que se actualiza automaticamente
    mapaAviones.insert({contadorAviones, pAvion});
    // Como se observa la llave utilizada es el contador
    cout << "Se registro el avion de id " << contadorAviones << endl;
    contadorAviones++;
}

void avion::consultarInformacion(int idAvion) {
    map<int, avion *>::iterator itAvion;
    itAvion = mapaAviones.find(idAvion);
    // Iterador que funcionara como valor que encuentra el id que se esta bsucando correspondiente a la instancia de la aeronave
    // En caso de encontrarla dentro del mapa sera igual al segundo valor del iterador que corresponde a la aeronave que se busca
    // Finalmente imprimira todos los valores de la aeronave uno por uno
    if (itAvion != mapaAviones.end()) {
        avion *pAvion = itAvion->second;
        cout << "El avion de id " << idAvion << " fue encontrado" << endl;
        cout << "La marca del avion es " << pAvion->getMarca() << endl;
        cout << "El modelo del avion es " << pAvion->getModelo() << endl;
        cout << "La capacidad de pasajeros es de " << pAvion->getCapacidadPasajeros() << " pasajeros" << endl;
        cout << "La velocidad maxima que alcanza el avion es de " << pAvion->getVelocidadMaxima() << " km/h"
             << endl;
        cout << "La autonomia del avion es de " << pAvion->getAutonomia() << " km" << endl;
        cout << "El anio de fabricacion del avion es " << pAvion->getAnioFabricacion() << endl;
        cout << "El estado del avion es " << pAvion->getEstado() << endl;
        cout << "La altitud maxima que alcanza el avion es de " << pAvion->getAltitudMaxima() << " m" << endl;
        cout << "La cantidad de motores es de " << pAvion->getCantidadMotores() << " motores" << endl;
        cout << "La categoria del avion es " << pAvion->getCategoria() << endl;
    } else {
        cout << "No se pudo encontrar el ID del avion solicitado en el sistema" << endl;
    }
}

// Este metodo realiza la misma verificacion de encontrar el dato (id) buscado al inicio
void avion::modificarInformacion(int idAvion) {
    string verificarEstado;
    map<int, avion *>::iterator itAvion;
    itAvion = mapaAviones.find(idAvion);
    if (itAvion != mapaAviones.end()) {
        int opcion;
        avion *pAvion = itAvion->second;
        cout << "El avion de id " << idAvion << " sera modificado... Que desea modificar?" << endl;
        cout
                << "1) Marca \n2) Modelo \n3) Capacidad de pasajeros \n4) Velocidad maxima \n5) Autonomia \n6) Anio de fabricacion \n7) Estado \n8) Altitud maxima \n9) Cantidad de motores \n10) Categoria"
                << endl;
        cin >> opcion;
        // Bucle while que como se explico mas arriba evita que la entrada del menu switch sea distinta de un entero
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
            cin >> opcion;
        }
        // Switch para elegir el atributo que se desea modificar y cambiar su valor... dependiendo del tipo de dato a modificar
        // utiliza el "manejo de excepciones" que ya explique mas arriba
        switch (opcion) {
            case 1:
                cout << "Ingrese la nueva marca" << endl;
                cin.ignore();
                getline(cin, pAvion->marca);
                break;
            case 2:
                cout << "Ingrese el nuevo modelo" << endl;
                cin.ignore();
                getline(cin, pAvion->modelo);
                break;
            case 3:
                cout << "Ingrese la nueva capacidad de pasajeros" << endl;
                cin >> pAvion->capacidadPasajeros;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pAvion->capacidadPasajeros;
                }
                break;
            case 4:
                cout << "Ingrese la nueva velocidad maxima" << endl;
                cin >> pAvion->velocidadMaxima;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pAvion->velocidadMaxima;
                }
                break;
            case 5:
                cout << "Ingrese la nueva autonomia" << endl;
                cin >> pAvion->autonomia;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pAvion->autonomia;
                }
                break;
            case 6:
                cout << "Ingrese el nuevo anio de fabricacion" << endl;
                cin >> pAvion->anioFabricacion;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pAvion->anioFabricacion;
                }
                break;
            case 7:
                cin.ignore();
                do {
                    cout << "Ingrese el nuevo estado (servicio, asignado, mantenimiento)" << endl;
                    getline(cin, pAvion->estado);
                    if (pAvion->estado != "servicio" && pAvion->estado != "Servicio" && pAvion->estado != "asignado" &&
                        pAvion->estado != "Asignado" &&
                        pAvion->estado != "mantenimiento" && pAvion->estado != "Mantenimiento") {
                        cout << "Las opciones validas son las de los parentesis" << endl;
                    }
                } while (pAvion->estado != "servicio" && pAvion->estado != "Servicio" && pAvion->estado != "asignado" &&
                         pAvion->estado != "Asignado" &&
                         pAvion->estado != "mantenimiento" && pAvion->estado != "Mantenimiento");
                break;
            case 8:
                cout << "Ingrese la nueva altitud maxima" << endl;
                cin >> pAvion->altitudMaxima;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pAvion->altitudMaxima;
                }
                break;
            case 9:
                cout << "Ingrese la nueva cantidad de motores" << endl;
                cin >> pAvion->cantidadMotores;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> pAvion->cantidadMotores;
                }
                break;
            case 10:
                cin.ignore();
                do {
                    cout << "Ingrese la nueva categoria (comercial, carga)" << endl;
                    getline(cin, pAvion->categoria);
                    if (pAvion->categoria != "comercial" && pAvion->categoria != "Comercial" &&
                        pAvion->categoria != "carga" && pAvion->categoria != "Carga") {
                        cout << "Las opciones validas son las de los parentesis" << endl;
                    }
                } while (pAvion->categoria != "comercial" && pAvion->categoria != "Comercial" &&
                         pAvion->categoria != "carga" && pAvion->categoria != "Carga");
                break;
            default:
                cout << "Opcion digitada invalida" << endl;
                break;
        }
    } else {
        cout << "No se pudo encontrar el ID del avion solicitado en el sistema" << endl;
    }
}

int avion::getAltitudMaxima() {
    return altitudMaxima;
}

int avion::getCantidadMotores() {
    return cantidadMotores;
}

string avion::getCategoria() {
    return categoria;
}

map<int, avion *> avion::getMapaAviones() {
    return mapaAviones;
}