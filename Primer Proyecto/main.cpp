#include <iostream>
#include "avion.h"
#include "helicoptero.h"
#include "jet.h"
#include "pasajero.h"
#include "tripulacion.h"

map<int, avion *> mapaAviones;

int main() {

    int opcionPrincipal;
    int opcionAeronave;
    int opcionGestionAeronave;
    int opcionUsuario;
    int opcionGestionUsuario;
    avion *pAvion;
    helicoptero *pHelicoptero;
    jet *pJet;
    pasajero *pPasajero;
    tripulacion *pTripulacion;
    int idAvion;
    int idHelicoptero;
    int idJet;
    int idPasajero;
    int idTripulacion;

    cout << "Buenos dias administrador del sistema. Que tarea desea hacer el dia de hoy?" << endl;
    do {
        cout << "1) Gestion de aeronaves \n2) Gestion de usuarios \n5) Salir" << endl;
        cin >> opcionPrincipal;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
            cin >> opcionPrincipal;
        }
        switch (opcionPrincipal) {
            case 1:
                cout << "Que tipo de aeronave gestionara el dia de hoy?" << endl;
                cout << "1) Aviones \n2) Helicopteros \n3) Jets \n4) Volver al menu principal" << endl;
                cin >> opcionAeronave;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> opcionAeronave;
                }
                switch (opcionAeronave) {
                    case 1:
                        do {
                            cout
                                    << "1) Crear avion \n2) Consultar avion \n3) Modificar avion \n4) Volver al menu"
                                    << endl;
                            cin >> opcionGestionAeronave;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                                cin >> opcionGestionAeronave;
                            }
                            switch (opcionGestionAeronave) {
                                case 1:
                                    pAvion = new avion("", "", 0, 0, 0, 0, "", 0, 0, "", 0);
                                    pAvion->ingresarInformacion();
                                    pAvion->ingresarAvion(pAvion->getMarca(), pAvion->getModelo(),
                                                          pAvion->getCapacidadPasajeros(),
                                                          pAvion->getVelocidadMaxima(), pAvion->getAutonomia(),
                                                          pAvion->getAnioFabricacion(),
                                                          pAvion->getEstado(), pAvion->getAltitudMaxima(),
                                                          pAvion->getCantidadMotores(),
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
                                            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:"
                                                 << endl;
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
                                            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:"
                                                 << endl;
                                            cin >> idAvion;
                                        }
                                        pAvion->modificarInformacion(idAvion);
                                    }
                                    break;
                                case 4:
                                    cout << "Volviendo al menu" << endl;
                                    break;
                                default:
                                    cout << "Opcion invalida" << endl;
                                    break;
                            }
                        } while (opcionGestionAeronave != 4);
                        break;
                    case 2:
                        do {
                            cout
                                    << "1) Crear helicoptero  \n2) Consultar helicoptero \n3) Modificar helicoptero \n4) Volver al menu"
                                    << endl;
                            cin >> opcionGestionAeronave;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                                cin >> opcionGestionAeronave;
                            }
                            switch (opcionGestionAeronave) {
                                case 1:
                                    pHelicoptero = new helicoptero("", "", 0, 0, 0, 0, "", 0, 0, "", 0);
                                    pHelicoptero->ingresarInformacion();
                                    pHelicoptero->ingresarHelicoptero(pHelicoptero->getMarca(),
                                                                      pHelicoptero->getModelo(),
                                                                      pHelicoptero->getCapacidadPasajeros(),
                                                                      pHelicoptero->getVelocidadMaxima(),
                                                                      pHelicoptero->getAutonomia(),
                                                                      pHelicoptero->getAnioFabricacion(),
                                                                      pHelicoptero->getEstado(),
                                                                      pHelicoptero->getCantidadRotores(),
                                                                      pHelicoptero->getCapacidadElevacion(),
                                                                      pHelicoptero->getUsoEspecifico());
                                    break;
                                case 2:
                                    if (helicoptero::getMapaHelicopteros().empty()) {
                                        cout << "No existen helicopteros en el sistema" << endl;
                                    } else {
                                        cout << "Ingrese el ID del helicoptero que desea consultar" << endl;
                                        cin >> idHelicoptero;
                                        while (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:"
                                                 << endl;
                                            cin >> idHelicoptero;
                                        }
                                        pHelicoptero->consultarInformacion(idHelicoptero);
                                    }
                                    break;
                                case 3:
                                    if (helicoptero::getMapaHelicopteros().empty()) {
                                        cout << "No existen helicopteros en el sistema" << endl;
                                    } else {
                                        cout << "Ingrese el ID del helicoptero que desea modificar" << endl;
                                        cin >> idHelicoptero;
                                        while (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:"
                                                 << endl;
                                            cin >> idHelicoptero;
                                        }
                                        pHelicoptero->modificarInformacion(idHelicoptero);
                                    }
                                    break;
                                case 4:
                                    cout << "Volviendo al menu" << endl;
                                    break;
                                default:
                                    cout << "Opcion invalida" << endl;
                                    break;
                            }
                        } while (opcionGestionAeronave != 4);
                        break;
                    case 3:
                        do {
                            cout
                                    << "1) Crear jet \n2) Consultar jet \n3) Modificar jet \n4) Volver al menu"
                                    << endl;
                            cin >> opcionGestionAeronave;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                                cin >> opcionGestionAeronave;
                            }
                            switch (opcionGestionAeronave) {
                                case 1:
                                    pJet = new jet("", "", 0, 0, 0, 0, "", "", "", "", 0);
                                    pJet->ingresarInformacion();
                                    pJet->ingresarJet(pJet->getMarca(), pJet->getModelo(),
                                                      pJet->getCapacidadPasajeros(),
                                                      pJet->getVelocidadMaxima(), pJet->getAutonomia(),
                                                      pJet->getAnioFabricacion(),
                                                      pJet->getEstado(), pJet->getPropietario(),
                                                      pJet->getListaServicios(),
                                                      pJet->getListaDestinosFrecuentes());
                                    break;
                                case 2:
                                    if (jet::getMapaJets().empty()) {
                                        cout << "No existen jets en el sistema" << endl;
                                    } else {
                                        cout << "Ingrese el ID del jet que desea consultar" << endl;
                                        cin >> idJet;
                                        while (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:"
                                                 << endl;
                                            cin >> idJet;
                                        }
                                        pJet->consultarInformacion(idJet);
                                    }
                                    break;
                                case 3:
                                    if (jet::getMapaJets().empty()) {
                                        cout << "No existen jets en el sistema" << endl;
                                    } else {
                                        cout << "Ingrese el ID del jet que desea modificar" << endl;
                                        cin >> idJet;
                                        while (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:"
                                                 << endl;
                                            cin >> idJet;
                                        }
                                        pJet->modificarInformacion(idJet);
                                    }
                                    break;
                                case 4:
                                    cout << "Volviendo al menu" << endl;
                                    break;
                                default:
                                    cout << "Opcion invalida" << endl;
                                    break;
                            }
                        } while (opcionGestionAeronave != 4);
                        break;
                    case 4:
                        cout << "Volviendo al menu principal" << endl;
                        break;
                    default:
                        cout << "Opcion invalida" << endl;
                        break;
                }
                break;
            case 2:
                cout << "Que tipo de persona gestionara el dia de hoy?" << endl;
                cout << "1) Pasajeros \n2) Tripulacion \n3) Volver al menu principal" << endl;
                cin >> opcionUsuario;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                    cin >> opcionUsuario;
                }
                switch (opcionUsuario) {
                    case 1:
                        do {
                            cout
                                    << "1) Crear pasajero \n2) Consultar pasajero \n3) Volver al menu"
                                    << endl;
                            cin >> opcionGestionUsuario;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                                cin >> opcionGestionUsuario;
                            }
                            switch (opcionGestionUsuario) {
                                case 1:
                                    pPasajero = new pasajero("", "", "", "", "", "", "", "", "", 0, "", 0);
                                    pPasajero->ingresarInformacion();
                                    pPasajero->ingresarPasajero(pPasajero->getCedula(), pPasajero->getNombres(),
                                                                pPasajero->getApellidos(),
                                                                pPasajero->getFechaNacimiento(),
                                                                pPasajero->getGenero(),
                                                                pPasajero->getDireccion(),
                                                                pPasajero->getNumeroTelefono(),
                                                                pPasajero->getCorreoElectronico(),
                                                                pPasajero->getNacionalidad(),
                                                                pPasajero->getCantidadMaletas(),
                                                                pPasajero->getInformacionMedica());
                                    break;
                                case 2:
                                    if (pasajero::getMapaPasajeros().empty()) {
                                        cout << "No existen pasajeros en el sistema" << endl;
                                    } else {
                                        cout << "Ingrese el ID del pasajero que desea consultar" << endl;
                                        cin >> idPasajero;
                                        while (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:"
                                                 << endl;
                                            cin >> idPasajero;
                                        }
                                        pPasajero->consultarInformacion(idPasajero);
                                    }
                                    break;
                                case 3:
                                    cout << "Volviendo al menu" << endl;
                                    break;
                                default:
                                    cout << "Opcion invalida" << endl;
                                    break;
                            }
                        } while (opcionGestionUsuario != 3);
                        break;
                    case 2:
                        do {
                            cout
                                    << "1) Crear tripulacion \n2) Consultar tripulacion \n3) Volver al menu"
                                    << endl;
                            cin >> opcionGestionUsuario;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:" << endl;
                                cin >> opcionGestionUsuario;
                            }
                            switch (opcionGestionUsuario) {
                                case 1:
                                    pTripulacion = new tripulacion("", "", "", "", "", "", "", "", "", 0, 0, 0);
                                    pTripulacion->ingresarInformacion();
                                    pTripulacion->ingresarTripulacion(pTripulacion->getCedula(),
                                                                      pTripulacion->getNombres(),
                                                                      pTripulacion->getApellidos(),
                                                                      pTripulacion->getFechaNacimiento(),
                                                                      pTripulacion->getGenero(),
                                                                      pTripulacion->getDireccion(),
                                                                      pTripulacion->getNumeroTelefono(),
                                                                      pTripulacion->getCorreoElectronico(),
                                                                      pTripulacion->getPuesto(),
                                                                      pTripulacion->getAniosExperiencia(),
                                                                      pTripulacion->getHorasTrabajoDiarias());
                                    break;
                                case 2:
                                    if (tripulacion::getMapaTripulacion().empty()) {
                                        cout << "No existe tripulacion en el sistema" << endl;
                                    } else {
                                        cout << "Ingrese el ID de la tripulacion que desea consultar" << endl;
                                        cin >> idTripulacion;
                                        while (cin.fail()) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout << "Error: La entrada no fue un valor entero. Ingrese nuevamente:"
                                                 << endl;
                                            cin >> idTripulacion;
                                        }
                                        pTripulacion->consultarInformacion(idTripulacion);
                                    }
                                    break;
                                case 3:
                                    cout << "Volviendo al menu" << endl;
                                    break;
                                default:
                                    cout << "Opcion invalida" << endl;
                                    break;
                            }
                        } while (opcionGestionUsuario != 3);
                        break;
                    case 3:
                        cout << "Volviendo al menu principal" << endl;
                        break;
                    default:
                        cout << "Opcion invalida" << endl;
                        break;
                }
                break;
            case 5:
                cout << "Hasta luego tenga buen dia" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (opcionPrincipal != 5);
}