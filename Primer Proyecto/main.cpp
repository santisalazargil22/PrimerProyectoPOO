#include <iostream>
#include "avion.h"

map<int, avion *> mapaAviones;

int main() {

    int opcion;
    avion *pAvion;
    int idAvion;

    do {
        cout << "1) Crear avion \n2) Consultar avion \n3) Modificar avion \n4) Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                pAvion = new avion("", "", 0, 0, 0, 0, "", 0, 0, "", 0);
                pAvion->ingresarInformacion();
                pAvion->ingresarAvion(pAvion->getMarca(), pAvion->getModelo(), pAvion->getCapacidadPasajeros(),
                                      pAvion->getVelocidadMaxima(), pAvion->getAutonomia(),
                                      pAvion->getAnioFabricacion(),
                                      pAvion->getEstado(), pAvion->getAltitudMaxima(), pAvion->getCantidadMotores(),
                                      pAvion->getCategoria());
                break;
            case 2:
                if (avion::getMapaAviones().empty()) {
                    cout << "No existen aviones en el sistema" << endl;
                } else {
                    cout << "Ingrese el ID del avion que desea consultar" << endl;
                    cin >> idAvion;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                        cin >> idAvion;
                    }
                    pAvion->consultarInformacion(idAvion);
                }
                break;
            case 3:
                if (avion::getMapaAviones().empty()) {
                    cout << "No existen aviones en el sistema" << endl;
                } else {
                    cout << "Ingrese el ID del avion que desea modificar" << endl;
                    cin >> idAvion;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                        cin >> idAvion;
                    }
                    pAvion->modificarInformacion(idAvion);
                }
                break;
            case 4:
                cout << "Adios" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);

    return 0;
}