/*
    ! Fecha: miercoles 27 de noviembre de 2024
    ! Autor: Miguel Salvador Calata Rodríguez y Damian Dali Robles de Anda
    ! Practica No.: Proyecto Final
    ! Objetivo: LSEA - lista simplemente enlazada abierta
*/

//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//* tda's
struct membresia {
    // 1. parte informacion
    int numero;
    char nombre[99];
    char fechaContrat[20];
    float costo;
    char tipo[5];
    char servicios[99];
    // Los otros cuatro datos propuestos:
    char telefono[11];
    int sucursal;
    int edad;
    char correo[51];
  // 2. apuntador al siguiente elemento
    membresia *next;
};

//* operaciones de LSEA
void agregarInicio();
void consultarLista();
void buscarTitulo();
void agregarFinal();
void eliminarFinal();
void agregarSegundo();
void eliminarSegundo();
void filtrarPrecio(); 
void eliminarInicio(); 
void menu();

//* variables globales
// apuntador a mi lista
membresia *apLISTA = NULL;

//* funcion principal
int main(void) {
  // declaracion de variables
    int opcion;

    do {

        menu();
        cout << "Ingresa tu opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            agregarInicio();
            break;
        case 2:
            consultarLista();
            break;
        case 3:
            buscarTitulo();
            break;
        case 4:
            agregarFinal();
            break;
        case 5:
            eliminarFinal();
            break;
        case 6:
            agregarSegundo();
            break;
        case 7:
            eliminarSegundo();
            break;
        case 8:
            filtrarPrecio();
            break;
        case 9:
            eliminarInicio();
            break;
        case 0:
            cout << "Seleccionaste salir" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        } // switch
        } while (opcion);

        return 0;
}

//* implementacion de operaciones - funciones
//! agregarInicio()
//! ==============================================================
void agregarInicio() {
    // 1) declarar un apuntador
    membresia *apNuevo = NULL;

    // 2) solicitar memoria dinamica
    apNuevo = (membresia *)malloc(sizeof(membresia));

    // 3) validar el apuntador
    if (apNuevo == NULL) {
        cout << "No se tiene memoria suficiente" << endl;
    } // if

    // 4) guardar los datos del nuevo videojuego
    cout << endl << endl;
    cout << "Ingresa los datos del nuevo miembro" << endl;

    cout << "Numero del miembro: ";
    cin >> apNuevo->numero;

    cout << "Nombre completo del miembro: ";
    cin.ignore();
    cin.getline(apNuevo->nombre, 99, '\n');

    cout << "Fecha del contrado: ";
    cin.ignore();
    cin.getline(apNuevo->fechaContrat, 30, '\n');

    cout << "Costo de la mensualidad: ";
    cin >> apNuevo->costo




    cout << "Titulo: ";
    cin.ignore();
    cin.getline(apNuevo->titulo, 30, '\n');
    cout << "Genero: ";
    cin.getline(apNuevo->genero, 20, '\n');
    cout << "Clasificacion: ";
    cin.getline(apNuevo->clasificacion, 20, '\n');
    cout << "Precio: ";
    cin >> apNuevo->precio;

    // 5) agregar a la LSEA
    // caso A) Lista vacia
    if (apLISTA == NULL) {
        apLISTA = apNuevo;
        apNuevo->next = NULL;
        cout << "Videojuego agregado corrrectamente al inicio de la lista" << endl;
        return;
    } // if

    // caso B) lista no vacia
    apNuevo->next = apLISTA;
    apLISTA = apNuevo;
    cout << "Videojuego agregado correctamente al inicio de la lista" << endl;

    return;
} // agregarInicio()

//! consultarLista()
//! ==============================================================
void consultarLista() {

    return;
} // consultarLista()

//! buscarTitulo()
//! ==============================================================
void buscarTitulo() {

    return;
} // buscarTitulo()


//! agregarFinal()
//! ==============================================================
void agregarFinal(){

    return;
} // agregarFinal()

//! agregarSegundo()  TAREA
//! ==============================================================
void agregarSegundo(){

    return;
} // agrearSegundo()

//! eliminarSegundo()  TAREA
//! ==============================================================
void eliminarSegundo(){

    return;
} // eliminarSegundo()

//! eliminarFinal() 
//! ==============================================================
void eliminarFinal(){

    return;
} // eliminarFinal()

//! filtrarPrecio()  TAREA
//! ==============================================================
void filtrarPrecio(){

    return;
} // filtrarPrecio()

//! eliminarInicio()  TAREA
//! ==============================================================
void eliminarInicio(){

    return;
} // eliminarInicio()

//! menu()
//! ==============================================================
void menu(void) {
cout << endl << endl;
cout << "Listado de mis videojuegos favoritos" << endl;
cout << "====================================" << endl;
cout << "1. Agregar un videojuego al inicio de la lista" << endl;
cout << "2. Consultar mi listado de videojuegos" << endl;
cout << "3. Buscar un videojuego por su tipo" << endl;
cout << "4. Agregar un videojuego al final de la lista" << endl;
cout << "5. Eliminar el videojuego al final de la lista" << endl;
cout << "6. Agregar un videojuego en la segunda posicion dela lista" << endl;
cout << "7. Eliminar el videojuego en la segunda posicion de la lista" << endl;
cout << "8. Filtrar videojuegos por precio" << endl;
cout << "9. Eliminar el videojuego al inicio de la lista (Tarea)" << endl;
cout << "0. Salir" << endl;

return;
} // menu() 
