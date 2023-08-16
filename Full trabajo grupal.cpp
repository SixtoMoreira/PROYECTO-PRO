#include <iostream>
#include <cstdlib>
#include <cctype>
#include <conio.h>

using namespace std;

bool validarCedula(const string &cedula) {
    if (cedula.length() != 10)
        return false;

    for (size_t i = 0; i < cedula.length(); ++i) {
        if (!isdigit(cedula[i]))
            return false;
    }

    return true;
}

bool validarTexto(const string &texto) {
    for (size_t i = 0; i < texto.length(); ++i) {
        if (!isalpha(texto[i]))
            return false;
    }
    return true;
}

bool validarNumero(const string &numero) {
    for (size_t i = 0; i < numero.length(); ++i) {
        if (!isdigit(numero[i]) && numero[i] != '.') // Permitir decimales
            return false;
    }
    return true;
}

bool validarNota(double nota) {
    return (nota >= 0 && nota <= 20);
}

string generarCorreo(const string &nombre, const string &apellido) {
    string iniciales = nombre.substr(0, 2) + apellido;
    string correo = iniciales + "@espe.edu.ec";
    return correo;
}

void ingresarDatos() {
    system("cls");
    cout << "Sistema de Calificaciones Estudiantil" << endl;
    cout << "------------------------------------" << endl;
    string cedula;
    cout << "Opcion: Ingreso de datos del estudiante" << endl;

    do {
        cout << "Ingrese la cedula: ";
        cin >> cedula;

        if (!validarCedula(cedula))
            cout << "Error: Cedula invalida. Ingrese solo numeros." << endl;
    } while (!validarCedula(cedula));

    string primerNombre, apellido;
    int edad;

    do {
        cout << "Ingrese el primer nombre: ";
        cin >> primerNombre;

        if (!validarTexto(primerNombre))
            cout << "Error: Ingrese solo letras." << endl;
    } while (!validarTexto(primerNombre));

    do {
        cout << "Ingrese el apellido: ";
        cin >> apellido;

        if (!validarTexto(apellido))
            cout << "Error: Ingrese solo letras." << endl;
    } while (!validarTexto(apellido));

    string edadStr;
    bool edadValida = false;
    while (!edadValida) {
        cout << "Ingrese la edad: ";
        cin >> edadStr;

        if (validarNumero(edadStr)) {
            edad = atoi(edadStr.c_str());
            edadValida = true;
        } else {
            cout << "Error: Ingrese solo numeros." << endl;
        }
    }

    cout << "Datos ingresados:" << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Primer Nombre: " << primerNombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Edad: " << edad << endl;

    cout << "Pulsa una tecla para continuar...";
    _getch();
}

void ingresarNotasAsignatura(string cedula) {
    double notas[10]; // Ahora se permiten hasta 10 notas
    int numNotas = 0; // Contador de notas ingresadas

    while (numNotas < 5) {
        string notaStr;
        double nota;

        do {
            system("cls"); // Limpiar la pantalla
            cout << "Sistema de Calificaciones Estudiantil" << endl;
            cout << "------------------------------------" << endl;
            cout << "Opcion: Ingreso de notas del estudiante" << endl;
            cout << "Cedula del estudiante: " << cedula << endl;
            cout << "Asignatura " << numNotas + 1 << ": ";
            cin >> notaStr;

            if (validarNumero(notaStr)) {
                nota = atof(notaStr.c_str());
                if (validarNota(nota)) {
                    notas[numNotas] = nota;
                    numNotas++;
                    break;
                } else {
                    cout << "Error: Ingrese una nota entre 0 y 20." << endl;
                    _getch();
                }
            } else {
                cout << "Error: Ingrese solo numeros." << endl;
                _getch();
            }
        } while (true);
    }

    int opcion = -1;
    while (opcion != 0 && numNotas < 10) {
        cout << "Desea ingresar mas notas? (1: Si, 0: No): ";
        cin >> opcion;

        if (opcion == 1) {
            string notaStr;
            double nota;

            do {
                system("cls"); // Limpiar la pantalla
                cout << "Sistema de Calificaciones Estudiantil" << endl;
                cout << "------------------------------------" << endl;
                cout << "Opcion: Ingreso de notas del estudiante" << endl;
                cout << "Cedula del estudiante: " << cedula << endl;
                cout << "Asignatura " << numNotas + 1 << ": ";
                cin >> notaStr;

                if (validarNumero(notaStr)) {
                    nota = atof(notaStr.c_str());
                    if (validarNota(nota)) {
                        notas[numNotas] = nota;
                        numNotas++;
                        break;
                    } else {
                        cout << "Error: Ingrese una nota entre 0 y 20." << endl;
                        _getch();
                    }
                } else {
                    cout << "Error: Ingrese solo numeros." << endl;
                    _getch();
                }
            } while (true);
        }
    }

    cout << "Notas ingresadas:" << endl;
    for (int i = 0; i < numNotas; ++i) {
        cout << "Asignatura " << i + 1 << ": " << notas[i] << endl;
    }

    while (true) {
        cout << "Desea editar alguna nota? (1: Si, 0: No): ";
        cin >> opcion;

        if (opcion == 1) {
            int numNotaEditar;
            cout << "Ingrese el número de la nota que desea editar (1-" << numNotas << "): ";
            cin >> numNotaEditar;

            if (numNotaEditar >= 1 && numNotaEditar <= numNotas) {
                string notaStr;
                double nota;

                do {
                    cout << "Ingrese la nueva nota " << numNotaEditar << ": ";
                    cin >> notaStr;

                    if (validarNumero(notaStr)) {
                        nota = atof(notaStr.c_str());
                        if (validarNota(nota)) {
                            notas[numNotaEditar - 1] = nota;
                            break;
                        } else {
                            cout << "Error: Ingrese una nota entre 0 y 20." << endl;
                        }
                    } else {
                        cout << "Error: Ingrese solo numeros." << endl;
                    }
                } while (true);
            } else {
                cout << "Número de nota inválido." << endl;
            }
        } else {
            break;
        }
    }

    cout << "Notas actualizadas:" << endl;
    for (int i = 0; i < numNotas; ++i) {
        cout << "Asignatura " << i + 1 << ": " << notas[i] << endl;
    }

    cout << "Pulsa una tecla para continuar...";
    _getch();
}

void generarCorreos() {
    system("cls");
    cout << "Sistema de Calificaciones Estudiantil" << endl;
    cout << "------------------------------------" << endl;
    cout << "Opcion: Generador de correos electronicos" << endl;

    string nombre, apellido;
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre;
    cout << "Ingrese el apellido del estudiante: ";
    cin >> apellido;

    cout << "Correo electronico generado: " << generarCorreo(nombre, apellido) << endl;

    cout << "Pulsa una tecla para continuar...";
    _getch();
}

int main() {
    int opcion = 1;
    const int NUMERO_OPCIONES = 4;
    const int NUMERO_MATERIAS = 4;
    int opcionMateria = 1;
    string cedulaEstudiante;

    while (true) {
        system("cls");

        cout << "Sistema de Calificaciones Estudiantil" << endl;
        cout << "------------------------------------" << endl;
        cout << (opcion == 1 ? "> " : "  ") << "1. Ingreso de datos del estudiante" << endl;
        cout << (opcion == 2 ? "> " : "  ") << "2. Ingreso de notas del estudiante" << endl;
        cout << (opcion == 3 ? "> " : "  ") << "3. Generador de correos electronicos" << endl;
        cout << (opcion == 4 ? "> " : "  ") << "4. Salir" << endl;

        int tecla = _getch();

        if (tecla == 224) {
            tecla = _getch();
            switch (tecla) {
                case 72:
                    opcion = (opcion > 1) ? opcion - 1 : NUMERO_OPCIONES;
                    break;
                case 80:
                    opcion = (opcion < NUMERO_OPCIONES) ? opcion + 1 : 1;
                    break;
            }
        } else if (tecla == 13) {
            switch (opcion) {
                case 1:
                    ingresarDatos();
                    break;
                case 2:
                    cout << "Ingrese la cedula del estudiante: ";
                    cin >> cedulaEstudiante;
                    while (true) {
                        system("cls");

                        cout << "Sistema de Calificaciones Estudiantil" << endl;
                        cout << "------------------------------------" << endl;
                        cout << "Opcion: Ingreso de notas del estudiante" << endl;
                        cout << "Cedula del estudiante: " << cedulaEstudiante << endl;
                        cout << "Seleccione la materia:" << endl;
                        cout << (opcionMateria == 1 ? "> " : "  ") << "1. Calculo Diferencial e Integral" << endl;
                        cout << (opcionMateria == 2 ? "> " : "  ") << "2. Algebra Lineal" << endl;
                        cout << (opcionMateria == 3 ? "> " : "  ") << "3. Fundamentos de Programacion" << endl;
                        cout << (opcionMateria == 4 ? "> " : "  ") << "4. Quimica I" << endl;

                        int tecla = _getch();

                        if (tecla == 224) {
                            tecla = _getch();
                            switch (tecla) {
                                case 72:
                                    opcionMateria = (opcionMateria > 1) ? opcionMateria - 1 : NUMERO_MATERIAS;
                                    break;
                                case 80:
                                    opcionMateria = (opcionMateria < NUMERO_MATERIAS) ? opcionMateria + 1 : 1;
                                    break;
                            }
                        } else if (tecla == 13) {
                            switch (opcionMateria) {
                                case 1:
                                    ingresarNotasAsignatura(cedulaEstudiante);
                                    break;
                                case 2:
                                    ingresarNotasAsignatura(cedulaEstudiante);
                                    break;
                                case 3:
                                    ingresarNotasAsignatura(cedulaEstudiante);
                                    break;
                                case 4:
                                    ingresarNotasAsignatura(cedulaEstudiante);
                                    break;
                                default:
                                    break;
                            }
                            cout << "Pulsa una tecla para continuar...";
                            _getch();
                            break;
                        }
                    }
                    break;
                case 3:
                    generarCorreos();
                    break;
                case 4:
                    cout << "Saliendo del programa..." << endl;
                    return 0;
                default:
                    break;
            }
        }
    }

    return 0;
}
