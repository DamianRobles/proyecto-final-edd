// ***************************************************
// Fecha: SesiÃ³n 21
// Autor: Rebeca
// PrÃ¡ctica No.: 28
// Objetivo: LSEA (Lista Simplemente Enlazada Abierta) ORDENADA
// ***************************************************

// LibrerÃ­as
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

// TDA
struct videojuego {
    // InformaciÃ³n
    char nombre[30];
    char clasificacion[20];
    char categoria[20];
    char consola[15];
    int lanzamiento;
    // Apuntador al siguiente
    videojuego *next;
};

// Prototipos
void menu(void);
void agregarInicio(void);
void consultarLista(void);
void eliminarPrimero(void);
void agregarFinal(void);
void buscarNombre(void);
void buscarFecha(void);
void eliminarUltimo(void);
void ordenarLista(void);

// Apuntador a mi LSEA
videojuego *biblioteca=NULL;    // Variable GLOBAL

// ***************************************************
// FunciÃ³n principal
int main(void) {
    int opcion;
    do {
        menu();
        cout << "Digita tu opcion --> ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                agregarInicio();
                break;
            case 2:
                consultarLista();
                break;
            case 3:
                eliminarPrimero();
                break;
            case 4:
                agregarFinal();
                break;
            case 5:
                buscarNombre();
                break;
            case 6:
                buscarFecha();
                break;
            case 7:
                eliminarUltimo();
                break;
            case 8:
                ordenarLista();
                break;
            case 0:
                cout << "Seleccionaste SALIR !!!!" << endl;
                break;
            default:
                cout << "Opcion no valida !!!!" << endl;
                break;
        } // switch
        system("pause");
    } while ( opcion != 0 );
    return 0;
} // main
// ***************************************************

// DefiniciÃ³n de funciones
// -------------------------------------------------------
void ordenarLista(void){
    //declarar apuntadores
    videojuego *i=NULL, *j=NULL;
    videojuego *paso;
    int vueltas;

    //Caso A - Lista vacia
    if ( biblioteca == NULL ) {
        system("cls");
        cout << "No existen videojuegos registrados en la lista. No se puede ordenar la lista." <<endl;
        return;
    } //termina if

    // solicito memoria de nuevo
    paso = (videojuego *) malloc( sizeof(videojuego) );

    // valido
    if ( paso == NULL ) {
        cout << "No hay memoria suficiente para crear variable de paso." << endl;
        return;
    } // if

    // Calcular nÅ“mero de vueltas a la lista
    i=biblioteca;
    vueltas=0;
    while ( i->next != NULL ) {
        vueltas++;
        i = i -> next;
    } // while

    // Lista con dos o mas nodos.
    while( vueltas > 0 ){
        i=biblioteca;
        // Recorretodo el arreglo para colocar uno en su lugar
        while( i->next != NULL){
            j = i->next;
            // Comparar los aâ€“os de lanzamiento del videojuego, si es necesario intercambia informaciâ€”n de los nodos i y j
            if ( i->lanzamiento > j->lanzamiento  ){

                // 1) Copiar i -> paso
                strcpy(paso->nombre, i->nombre);
                strcpy(paso->clasificacion, i->clasificacion);
                strcpy(paso->categoria, i->categoria);
                strcpy(paso->consola, i->consola);
                paso->lanzamiento = i->lanzamiento;

                // 2) Copiar j -> i
                strcpy(i->nombre, j->nombre);
                strcpy(i->clasificacion, j->clasificacion);
                strcpy(i->categoria, j->categoria);
                strcpy(i->consola, j->consola);
                i->lanzamiento = j->lanzamiento;

                // 3) Copiar paso -> j
                strcpy(j->nombre, paso->nombre);
                strcpy(j->clasificacion, paso->clasificacion);
                strcpy(j->categoria, paso->categoria);
                strcpy(j->consola, paso->consola);
                j->lanzamiento = paso->lanzamiento;

            }	// if - intercambia informacion nodos
            i = i->next;
        } // while
        vueltas--;
    } // while

    cout<< "Los datos han sido ordenados por fecha Lanzamiento " <<endl;
    cout<< "Ingresar a la OPCION 2 para consultarlo." <<endl << endl;

    return;
} // ordenarLista

// -------------------------------------------------------
void eliminarUltimo(void) {
    // DeclaraciÃ³n de variables
    videojuego *ultimo, *penultimo;
    char respuesta;

    // caso a) Lista vacÃ­a
    if ( biblioteca == NULL) {
        cout << "No se tienen videojuegos registrados!!!" << endl;
        return;
    } // if

    // caso b) 1 Ãºnico nodo en la LSEA
    if ( biblioteca->next == NULL ) {
        cout << "Videojuego a eliminar:" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Nombre         : " << biblioteca->nombre << endl;
        cout << "Clasificiacion : " << biblioteca->clasificacion << endl;
        cout << "Categoria      : " << biblioteca->categoria << endl;
        cout << "Consola        : " << biblioteca->consola << endl;
        cout << "Lanzamiento    : " << biblioteca->lanzamiento << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Estas seguro de eliminarlo (S/s) para Si --> ";
        cin >> respuesta;
        if ( respuesta == 'S' || respuesta == 's' ) {
            free(biblioteca);
            biblioteca=NULL;
            cout << "Videojuego fue eliminado de la lista !!!" << endl;
            return;
        } // if - respuesta
        cout << "El Videojuego NO fue eliminado !!!" << endl;
        return;
    } // if

    // caso c) 2 o mÃ¡s nodos
    penultimo=biblioteca;
    ultimo=penultimo->next;

    while ( ultimo->next != NULL ) {
        penultimo = penultimo->next;
        ultimo = ultimo->next;
    } // while

    cout << "Videojuego a eliminar:" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Nombre         : " << ultimo->nombre << endl;
    cout << "Clasificiacion : " << ultimo->clasificacion << endl;
    cout << "Categoria      : " << ultimo->categoria << endl;
    cout << "Consola        : " << ultimo->consola << endl;
    cout << "Lanzamiento    : " << ultimo->lanzamiento << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Estas seguro de eliminarlo (S/s) para Si --> ";
    cin >> respuesta;
    if ( respuesta == 'S' || respuesta == 's' ) {
        free(ultimo);
        penultimo->next = NULL;
        cout << "Videojuego fue eliminado de la lista !!!" << endl;
        return;
    } // if - respuesta
    cout << "El Videojuego NO fue eliminado !!!" << endl;
    return;
} // eliminarUltimo

// -------------------------------------------------------
void buscarFecha(void) {
    // DeclaraciÃ³n de variables
    int fechaInicio, fechaFin;
    videojuego *buscar=biblioteca;
    bool localizado=false;

    // Lista vacÃ­a, no hay nada que buscar
    if ( biblioteca == NULL ) {
        cout << "No se tienen videojuegos registrados en la lista !!!" << endl;
        return;
    } // if

    // Solicitar el rango de fechas a buscar
    cout << "Axo de Lanzamiento (fecha inicio de busqueda) Ej. 1999 --> ";
    cin >> fechaInicio;

    cout << "Axo de Lanzamiento (fecha termina la busqueda) Ej. 2020 --> ";
    cin >> fechaFin;

    // Iniciar la bÃºsqueda
    system("cls");
    cout << "Videojuegos desde " << fechaInicio << " hasta " << fechaFin << endl;
    cout << "---------------------------------------------" << endl;
    while ( buscar != NULL ){
        if (buscar->lanzamiento>=fechaInicio && buscar->lanzamiento<=fechaFin) {
            cout << "Nombre         : " << buscar->nombre 			<< endl;
            cout << "Clasificiacion : " << buscar->clasificacion 	<< endl;
            cout << "Categoria      : " << buscar->categoria 		<< endl;
            cout << "Consola        : " << buscar->consola 			<< endl;
            cout << "Lanzamiento    : " << buscar->lanzamiento 		<< endl;
            cout << endl;
            localizado=true;
        } // if
        buscar = buscar->next;
    } // while
    if ( localizado == false ){
        cout << "No se tienen videojuegos registrados entre " << fechaInicio
             << " y " << fechaFin << endl;
    } // if
    cout << "---------------------------------------------" << endl;
    return;
} // buscarFecha

// -------------------------------------------------------
void buscarNombre(void) {
    // DeclaraciÃ³n de variables
    char nombreBuscar[30];
    videojuego *copia=biblioteca;

    // Lista vacÃ­a, no hay nada que buscar
    if ( biblioteca == NULL ) {
        cout << "No se tienen videojuegos registrados en la lista !!!" << endl;
        return;
    } // if

    // Solicitar el nombre del videojuego a Buscar
    cin.ignore();
    cout << "Ingresa el nombre del videojuego a buscar --> ";
    cin.getline(nombreBuscar,30,'\n');

    // Recorrer todos los nodos para buscar el videojuego
    while ( copia != NULL ) {
        if  (  strcmp(copia->nombre,nombreBuscar) == 0 ) {
            cout << "Videojuego localizado" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "Nombre         : " << copia->nombre 			<< endl;
            cout << "Clasificiacion : " << copia->clasificacion 	<< endl;
            cout << "Categoria      : " << copia->categoria 		<< endl;
            cout << "Consola        : " << copia->consola 			<< endl;
            cout << "Lanzamiento    : " << copia->lanzamiento 		<< endl;
            cout << "---------------------------------------------" << endl;
            return;
        } // if
        copia = copia->next;
    } // while

    cout << "Videojuego con el nombre " << nombreBuscar << " no esta registrado en la lista!!!" << endl;
    return;
} // buscarNombre

// -------------------------------------------------------
void agregarFinal(void) {
    // 1) DeclaraciÃ³n del apuntador
    videojuego *aFinal=NULL, *moverUltimo=NULL;

    // 2) Solicitar memoria
    aFinal = (videojuego *) malloc ( sizeof(videojuego) ) ;

    // 3) Validar el apuntador
    if  ( aFinal == NULL ) {
        cout << "No hay memoria suficiente para agregar un nuevo videojuego !!!" << endl;
        return;
    } // if

    // 4) Guardar los datos
    cout << "Ingresa los datos del nuevo videojuego" << endl;
    cin.ignore();
    cout << "Nombre --> ";
    cin.getline(aFinal->nombre,30,'\n');
    cout << "Clasificacion --> ";
    cin.getline(aFinal->clasificacion,20,'\n');
    cout << "Categoria --> ";
    cin.getline(aFinal->categoria,20,'\n');
    cout << "Consola --> ";
    cin.getline(aFinal->consola,15,'\n');
    cout << "Axo de Lanzamiento (ej. 2022) --> ";
    cin >> aFinal->lanzamiento;

    // 5) Agregarlo a la LSEA al FINAL

    // caso a) Lista vacÃ­a
    if ( biblioteca == NULL ) {
        biblioteca = aFinal;
        aFinal->next = NULL;
        cout << "El videojuego se agrego correctamente !!!" << endl;
        return;
    } // if - vacÃ­a

    // caso b) Lista con 1 Ãºnico nodo
    if ( biblioteca->next == NULL ) {
        biblioteca->next = aFinal;
        aFinal->next = NULL;
        cout << "El videojuego se agrego correctamente al final de la lista!!!" << endl;
        return;
    } // if - 1 nodo

    // caso c) Lista con 2 o mÃ¡s nodos
    moverUltimo = biblioteca;
    while ( moverUltimo->next != NULL ) {
        moverUltimo = moverUltimo->next;
    } // while

    aFinal->next = NULL;
    moverUltimo->next = aFinal;
    cout << "El videojuego se agrego correctamente al final de la lista!!!" << endl;
    return;
} // agregarFinal

// -------------------------------------------------------
void eliminarPrimero(void) {
    // DeclaraciÃ³n de variables
    videojuego *borrar=biblioteca;
    char respuesta;

    // Caso a) Lista vacÃ­a
    if ( biblioteca == NULL ) {
        cout << "La biblioteca de videojuegos no tiene ninguno registrado !!!" << endl;
        return;
    } // if

    // Caso b) Lista con 1 Ãºnico nodo
    // Caso c) Lista con 2 o mÃ¡s nodos
    cout << "Videojuego a eliminar:" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Nombre         : " << borrar->nombre << endl;
    cout << "Clasificiacion : " << borrar->clasificacion << endl;
    cout << "Categoria      : " << borrar->categoria << endl;
    cout << "Consola        : " << borrar->consola << endl;
    cout << "Lanzamiento    : " << borrar->lanzamiento << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Estas seguro de eliminarlo (S/s) para Si --> ";
    cin >> respuesta;

    if ( respuesta == 'S' || respuesta == 's' ) {

        if ( borrar->next == NULL) {
            biblioteca = NULL;
            free(borrar);
            cout << "Videojuego eliminado !!!" << endl;
            return;
        } // un Ãºnico nodo
        else {
            biblioteca = biblioteca->next;
            free(borrar);
            cout << "Videojuego eliminado !!!" << endl;
            return;
        } // 2 o mÃ¡s nodos
    } // if

    cout << "No se elimino el videojuego !!! " << endl;
    return;
} // eliminarPrimero

// -------------------------------------------------------
void consultarLista(void) {
    // DeclaraciÃ³n de variables
    videojuego *copia = biblioteca;

    // Validar si mi lSEA estÃ¡ vacÃ­a
    if ( copia == NULL ) {
        cout << "La biblioteca de videojuegos no tiene ninguno registrado !!!" << endl;
        return;
    } // if

    system("cls");
    cout << "Lista de videojuegos existentes en mi biblioteca" << endl;
    cout << "================================================" << endl;
    while ( copia != NULL ) {
        cout << "Nombre         : " << copia->nombre << endl;
        cout << "Clasificiacion : " << copia->clasificacion << endl;
        cout << "Categoria      : " << copia->categoria << endl;
        cout << "Consola        : " << copia->consola << endl;
        cout << "Lanzamiento    : " << copia->lanzamiento << endl;
        cout << "----------------------------------------------" << endl;
        copia = copia->next ;
    } // while

    return;
} // consultarLista

// -------------------------------------------------------
void agregarInicio(void){
    // 1) Declarar el apuntador
    videojuego *nuevo;

    // 2) Solicitar memoria
    nuevo = (videojuego *) malloc ( sizeof(videojuego)	) ;

    // 3) Validar el apuntador
    if ( nuevo == NULL ) {
        cout << "No se tiene memoria disponible para guardar un nuevo videojuego !!!!" << endl;
        return;
    } // if

    // 4) Guardar los datos
    cout << "Ingresa los datos del nuevo videojuego" << endl;
    cin.ignore();
    cout << "Nombre --> ";
    cin.getline(nuevo->nombre,30,'\n');
    cout << "Clasificacion --> ";
    cin.getline(nuevo->clasificacion,20,'\n');
    cout << "Categoria --> ";
    cin.getline(nuevo->categoria,20,'\n');
    cout << "Consola --> ";
    cin.getline(nuevo->consola,15,'\n');
    cout << "Axo de Lanzamiento (ej. 2022) --> ";
    cin >> nuevo->lanzamiento;

    // 5) Agregarlo a la LSEA
    if ( biblioteca == NULL ) {
        biblioteca = nuevo;
        nuevo->next = NULL;
    } else {
        nuevo->next = biblioteca;
        biblioteca = nuevo;
    }

    cout << "Videojuego agregado exitosamente al INICIO de la LISTA !!!" << endl;
    return;
} // agregarInicio

// -------------------------------------------------------
void menu(void) {
    system("cls");
    cout << "       Tienda de Videojuegos Rolando" << endl;
    cout << "______________________________________________" << endl;
    cout << "1) Agregar un videojuego al inicio de la lista" << endl;
    cout << "2) Consultar la lista de videojuegos" << endl;
    cout << "3) Eliminar el primer videojuego de la lista" << endl;
    cout << "4) Agregar un videojuego al final de la lista" << endl;
    cout << "5) Buscar un videojuego por su nombre" << endl;
    cout << "6) Buscar los videojuegos dentro de un rango de fecha de lanzamiento" << endl;
    cout << "7) Eliminar el ultimo videojuego de la lista" << endl;
    cout << "8) Ordenar la lista x Lanzamiento Ascendente" << endl;
    cout << "______________________________________________" << endl;
    cout << "0) Salir" << endl;
    return;
} // menu

// fin de archivo


