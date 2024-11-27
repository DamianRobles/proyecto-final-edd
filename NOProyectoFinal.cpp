/*
    ! Fecha: miercoles 27 de noviembre de 2024
    ! Autor: Miguel Salvador Calata Rodriguez y Damian Dali Robles de Anda
    ! Practica No.: Proyecto Final
    ! Objetivo: Proyecto Final con LSEA - lista simplemente enlazada abierta
*/



// Documentacion de funciones extras
/**
 * Funcion Sleep
 * Detiene la ejecucion del programa durante un periodo de tiempo especifico.
 *
 * Funcion Beep
 * Emite un sonido en la consola, util para notificaciones o alertas.
 *
 * Funcion SetConsoleTextAttribute
 * Cambia los atributos de texto de la consola, como el color del texto y el color de fondo.
 *
 * Funcion GetStdHandle
 * Obtiene un identificador para un dispositivo estandar (entrada, salida o error).
 *
 * Funcion strchr
 * Busca la primera aparicion de un caracter especifico en una cadena de texto.
 *
 * Funcion istringstream
 * Convierte una cadena de texto en un flujo de entrada, permitiendo la conversion de tipos de datos.
 */



//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream> // Necasario para istringstream
#include <windows.h> // Necesario para Sleep(), Beep, SetConsoleTextAttribute y GetStdHandle
using namespace std;

//* tda's
struct membresia {
    // 1. parte informacion
    int numero;
    char nombre[99];
    char fechaContrat[20];
    float costo;
    char tipo[10];
    char servicios[250];
    // Los otros cuatro datos propuestos:
    char telefono[11];
    char sucursal[15];
    int edad;
    char correo[99];
  // 2. apuntador al siguiente elemento
    membresia *next;
};

// funciones para consola
void consolaBlancoTextoNegro();
void moverVentana(int,int,int,int);
void logo();

//* operaciones de LSEA
void agregarInicio(); //* corregido
void agregarFinal();
void eliminarInicio();
void eliminarFinal();
void consultarLista(); //* corregido
void filtrarEdad();
void buscarNombre(); //* corregido
void guardarArchivo();
void leerArchivo();
void ordenarElementos();
void imprimir(membresia *);
void menu();

//* variables globales
// apuntador a mi lista
membresia *apLISTA = NULL;

//* funcion principal
int main(void) {
  // declaracion de variables
    int opcion;

    // Dos funciones de inicio
    consolaBlancoTextoNegro();
    moverVentana(100, 100, 1600, 800); // Mover y cambiar el tamanio de la ventana de la consola
    Sleep(300);
    logo();
    system("cls");

    do {

        menu();
        cout << "Ingresa tu opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            agregarInicio();
            break;
        case 2:
            agregarFinal();
            break;
        case 3:
            eliminarInicio();
            break;
        case 4:
            eliminarFinal();
            break;
        case 5:
            consultarLista();
            break;
        case 6:
            filtrarEdad();
            break;
        case 7:
            buscarNombre();
            break;
        case 8:
            guardarArchivo();
            break;
        case 9:
            leerArchivo();
            break;
        case 10:
            ordenarElementos();
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


//========================================================[Implementacion de operaciones]======================================================

//! agregarInicio()
//! ==============================================================
void agregarInicio() {
    // 1) declarar un apuntador
    membresia *apNuevo = NULL;
    int tempInt;
    char tempChar[255];
    bool flag = false;

    // 2) solicitar memoria dinamica
    apNuevo = (membresia *)malloc(sizeof(membresia));

    // 3) validar el apuntador
    if (apNuevo == NULL) {
        cout << "No se tiene memoria suficiente" << endl;
        for (int i = 0; i < 4; ++i) {
            Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
            Sleep(166);
        }
    } // if

    // 4) guardar los datos del nuevo miembro
    cout << endl << endl;
    cout << "Ingresa los datos del nuevo miembro" << endl;
    cout << "====================================" << endl;
    
    // Numero del miembro
    cout << "Numero del miembro: ";
    cin >> apNuevo->numero;
    cin.ignore(); // Limpiar el buffer tras un cin>>

    // Datos personales
    cout << "Nombre completo del miembro iniciando por apellidos: ";
    cin.getline(apNuevo->nombre, 99, '\n');
    cout << "Edad del miembro: ";
    cin >> apNuevo->edad;
    cin.ignore(); // Limpiar buffer antes de getline
    cout << "Telefono del miembro (ej. 3337703300): ";
    cin.getline(apNuevo->telefono, 11, '\n');

    // Datos de correo con verificacion que ingrese un correo valido
    while(flag == false){
        cout << "Correo del miembro (ej. asd@asd.com): ";
        cin.getline(tempChar, 51, '\n');
        // se comprueba que en la cadena exista en algun luagr un @ y un .
        if(strchr( tempChar, '@' ) != NULL && strchr( tempChar, '.' ) != NULL){
            flag = true;
            strcpy(apNuevo->correo, tempChar);
        }
        else{
            cout << "Ingrese una direccion de correo valida" << endl;
            for (int i = 0; i < 4; ++i) {
                Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
                Sleep(166);
            }
        }
    }
    flag = false;

    // Datos de la membresia
    // Datos de la fecha del contrato con verificacion que ingrese la fecha como en el ejemplo
    while(flag == false){
        cout << "Fecha del contrato en formato DD/MM/AAAA (ej. 01/12/2024): ";
        cin.getline(tempChar, 30, '\n');
        if(tempChar[2]==47 && tempChar[5]==47){
            flag = true;
            strcpy(apNuevo->fechaContrat, tempChar);
        }
        else{
            cout << "Ingrese la fecha como se indica en el ejemplo" << endl;
            for (int i = 0; i < 4; ++i) {
                Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
                Sleep(166);
            }
            // cin.ignore();
        }
    }
    flag = false;
    cout << "Costo de la mensualidad: ";
    cin >> apNuevo->costo;
    // datos del tipo de membresia con verificacion para que ingrese una de las 3 opciones presentadas
    while(flag == false){
        cout << "Seleccionar el tipo de la membresia (1- Plata  2- Oro  3- Platino): ";
        cin >> tempInt;
        // verificacion
        if(tempInt==1 || tempInt==2 || tempInt==3){
            flag = true;
            switch(tempInt){
                case 1:
                    cout << "Servicios incluidos: Acceso a todas las instalaciones. Clases grupales. Acceso a la sauna y jacuzzi." << endl;
                    // copia al dato servicios la cadena de caracteres
                    strcpy(apNuevo->servicios, "Acceso a todas las instalaciones. Clases grupales. Acceso a la sauna y jacuzzi.");
                    strcpy(apNuevo->tipo, "Plata");
                    break;
                case 2:
                    cout << "Servicios incluidos: Beneficios de la membresia Plata. Acceso preferencial a las clases y canchas. Asesoramiento personalizado por un entrenador. Descuento en servicios de nutricion y fisioterapia." << endl;
                    strcpy(apNuevo->servicios, "Beneficios de la membresia Plata. Acceso preferencial a las clases y canchas. Asesoramiento personalizado por un entrenador. Descuento en servicios de nutricion y fisioterapia.");
                    strcpy(apNuevo->tipo, "Oro");
                    break;
                case 3:
                    cout << "Servicios incluidos: Beneficios de la membresia Plata y Oro. Entrenador personal exclusivo. Acceso a un area de spa privada. Acceso gratuito a servicios de nutricion y fisioterapia." << endl;
                    strcpy(apNuevo->servicios, "Beneficios de la membresia Plata y Oro. Entrenador personal exclusivo. Acceso a un area de spa privada. Acceso gratuito a servicios de nutricion y fisioterapia.");
                    strcpy(apNuevo->tipo, "Platino");
                    break;
            }
        }
        else{
            cout << "Elige una opcion de la lista" << endl;
            for (int i = 0; i < 4; ++i) {
                Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
                Sleep(166);
            }
        }
    }
    // reinicio de variable flag
    flag = false;
    cin.ignore(); // Limpieza del buffer tras cin>>

    // Datos de la sucursal con verificacion para que ingrese una de las 3 opciones presentadas
    while(flag == false){
        cout << "Seleccione la sucursal (1- Centro  2- Zapopan  3- Tlaquepaque): ";
        cin >> tempInt;
        // verificacion
        if(tempInt==1 || tempInt==2 || tempInt==3){
            flag = true;
            switch(tempInt){
                case 1:
                    // copia al dato sucursal la cadena de caracteres
                    strcpy(apNuevo->sucursal, "Centro");
                    break;
                case 2:
                    strcpy(apNuevo->sucursal, "Zapopan");
                    break;
                case 3:
                    strcpy(apNuevo->sucursal, "Tlaquepaque");
                    break;
            }
        }
        else{
            cout << "Elige una opcion de la lista" << endl;
            for (int i = 0; i < 4; ++i) {
                Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
                Sleep(166);
            }
        }
    }
    // reinicio de variable flag
    flag = false;
    cin.ignore(); // Limpieza del buffer tras cin>>


    // 5) agregar a la LSEA
    // caso A) Lista vacia
    if (apLISTA == NULL) {
        apLISTA = apNuevo;
        apNuevo->next = NULL;
        cout << "Miembro agregado exitosamente al inicio de la lista" << endl;
        return;
    } // if

    // caso B) lista no vacia
    apNuevo->next = apLISTA;
    apLISTA = apNuevo;
    cout << "Miembro agregado exitosamente al inicio de la lista" << endl;

    return;
} // agregarInicio()

//! agregarFinal()
//! ==============================================================
void agregarFinal(){
    // 1) declarar un apuntador
    membresia *apNuevo = NULL;
    membresia *apCopia = apLISTA;
    int tempInt;
    char tempChar[255];
    bool flag = false;

    // 2) solicitar memoria dinamica
    apNuevo = (membresia *)malloc(sizeof(membresia));

    // 3) validar el apuntador
    if (apNuevo == NULL) {
        cout << "No se tiene memoria suficiente" << endl;
        for (int i = 0; i < 4; ++i) {
            Beep(300, 200); // Reproduce un sonido de 750 Hz durante 300 ms
            Sleep(200);
        }
    } // if

    // 4) guardar los datos del nuevo miembro
    cout << endl << endl;
    cout << "Ingresa los datos del nuevo miembro" << endl;
    cout << "====================================" << endl;
    
    // Numero del miembro
    cout << "Numero del miembro: ";
    cin >> apNuevo->numero;
    cin.ignore(); // Limpiar el buffer tras un cin>>

    // Datos personales
    cout << "Nombre completo del miembro iniciando por apellidos: ";
    cin.getline(apNuevo->nombre, 99, '\n');
    cout << "Edad del miembro: ";
    cin >> apNuevo->edad;
    cin.ignore(); // Limpiar buffer antes de getline
    cout << "Telefono del miembro (ej. 3337703300): ";
    cin.getline(apNuevo->telefono, 11, '\n');

    // Datos de correo con verificacion que ingrese un correo valido
    while(flag == false){
        cout << "Correo del miembro (ej. asd@asd.com): ";
        cin.getline(tempChar, 51, '\n');
        // se comprueba que en la cadena exista en algun luagr un @ y un .
        if(strchr( tempChar, '@' ) != NULL && strchr( tempChar, '.' ) != NULL){
            flag = true;
            strcpy(apNuevo->correo, tempChar);
        }
        else{
            cout << "Ingrese una direccion de correo valida" << endl;
            for (int i = 0; i < 4; ++i) {
                Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
                Sleep(166);
            }
        }
    }
    flag = false;

    // Datos de la membresia
    // Datos de la fecha del contrato con verificacion que ingrese la fecha como en el ejemplo
    while(flag == false){
        cout << "Fecha del contrato en formato DD/MM/AAAA (ej. 01/12/2024): ";
        cin.getline(tempChar, 30, '\n');
        if(tempChar[2]==47 && tempChar[5]==47){
            flag = true;
            strcpy(apNuevo->fechaContrat, tempChar);
        }
        else{
            cout << "Ingrese la fecha como se indica en el ejemplo" << endl;
            for (int i = 0; i < 4; ++i) {
                Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
                Sleep(166);
            }
            // cin.ignore();
        }
    }
    flag = false;
    cout << "Costo de la mensualidad: ";
    cin >> apNuevo->costo;
    // datos del tipo de membresia con verificacion para que ingrese una de las 3 opciones presentadas
    while(flag == false){
        cout << "Seleccionar el tipo de la membresia (1- Plata  2- Oro  3- Platino): ";
        cin >> tempInt;
        // verificacion
        if(tempInt==1 || tempInt==2 || tempInt==3){
            flag = true;
            switch(tempInt){
                case 1:
                    cout << "Servicios incluidos: Acceso a todas las instalaciones. Clases grupales. Acceso a la sauna y jacuzzi." << endl;
                    // copia al dato servicios la cadena de caracteres
                    strcpy(apNuevo->servicios, "Acceso a todas las instalaciones. Clases grupales. Acceso a la sauna y jacuzzi.");
                    strcpy(apNuevo->tipo, "Plata");
                    break;
                case 2:
                    cout << "Servicios incluidos: Beneficios de la membresia Plata. Acceso preferencial a las clases y canchas. Asesoramiento personalizado por un entrenador. Descuento en servicios de nutricion y fisioterapia." << endl;
                    strcpy(apNuevo->servicios, "Beneficios de la membresia Plata. Acceso preferencial a las clases y canchas. Asesoramiento personalizado por un entrenador. Descuento en servicios de nutricion y fisioterapia.");
                    strcpy(apNuevo->tipo, "Oro");
                    break;
                case 3:
                    cout << "Servicios incluidos: Beneficios de la membresia Plata y Oro. Entrenador personal exclusivo. Acceso a un area de spa privada. Acceso gratuito a servicios de nutricion y fisioterapia." << endl;
                    strcpy(apNuevo->servicios, "Beneficios de la membresia Plata y Oro. Entrenador personal exclusivo. Acceso a un area de spa privada. Acceso gratuito a servicios de nutricion y fisioterapia.");
                    strcpy(apNuevo->tipo, "Platino");
                    break;
            }
        }
        else{
            cout << "Elige una opcion de la lista" << endl;
            for (int i = 0; i < 4; ++i) {
                Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
                Sleep(166);
            }
        }
    }
    // reinicio de variable flag
    flag = false;
    cin.ignore(); // Limpieza del buffer tras cin>>

    // Datos de la sucursal con verificacion para que ingrese una de las 3 opciones presentadas
    while(flag == false){
        cout << "Seleccione la sucursal (1- Centro  2- Zapopan  3- Tlaquepaque): ";
        cin >> tempInt;
        // verificacion
        if(tempInt==1 || tempInt==2 || tempInt==3){
            flag = true;
            switch(tempInt){
                case 1:
                    // copia al dato sucursal la cadena de caracteres
                    strcpy(apNuevo->sucursal, "Centro");
                    break;
                case 2:
                    strcpy(apNuevo->sucursal, "Zapopan");
                    break;
                case 3:
                    strcpy(apNuevo->sucursal, "Tlaquepaque");
                    break;
            }
        }
        else{
            cout << "Elige una opcion de la lista" << endl;
            for (int i = 0; i < 4; ++i) {
                Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
                Sleep(166);
            }
        }
    }
    // reinicio de variable flag
    flag = false;
    cin.ignore(); // Limpieza del buffer tras cin>>


    // 5) agregarlos a la LSEA
    // Caso A) lista vacia
    if(apLISTA == NULL){
        apLISTA = apNuevo;
        apNuevo -> next = NULL;
        cout << "Miembro agregado exitosamente al final de la lista" << endl;
        return;
    } // if cuando lista esta vacia

    // caso B) lista no vacia
    while(apCopia->next != NULL){
        apCopia = apCopia -> next;
    } // while posiscionarme en el ultimo nodo
    apCopia -> next = apNuevo;
    apNuevo -> next = NULL;
    cout << "Miembro agregado exitosamente al final de la lista" << endl;

    return;
} // agregarFinal()

//! eliminarInicio()
//! ==============================================================
void eliminarInicio(){
    // 1) declarar variables
    membresia *apBorrar;
    int respuesta;

    // caso A) lista vacia
    if(apLISTA == NULL){
        cout << "La lista esta vacia" << endl;
        return;
    }

    // caso B) lista con 1 nodo
    if(apLISTA -> next  == NULL){
        apBorrar = apLISTA;
        cout << "====================================" << endl;
        imprimir(apBorrar);
        cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
        cin >> respuesta;
        if(respuesta == 1){
            // se borra
            free(apLISTA);
            apLISTA = NULL;
            cout << "El unico miembro fue eliminado de la lista" << endl;
        } // if si lo eliminamos
        return;
    }

    // caso C) lista con varios nodos
    if(apLISTA -> next != NULL){
        apBorrar = apLISTA;
        cout << "====================================" << endl;
        imprimir(apBorrar);
        cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
        cin >> respuesta;
        if(respuesta == 1){
            // se borra
            apLISTA = apLISTA -> next;
            free(apBorrar);
            cout << "El primer miembro fue eliminado de la lista" << endl;
        } // if si lo eliminamos
        return;
    }
    return;
} // eliminarInicio()

//! eliminarFinal() 
//! ==============================================================
void eliminarFinal(){
    // 1) declarar  de variables
    membresia *apBorrar, *apPenultimo;
    int respuesta;

    // caso A) lista vacia
    if(apLISTA == NULL){
        cout << "La lista esta vacia" << endl;
        return;
    }
    // caso B) lista con 1 unico nodo
    if(apLISTA -> next  == NULL){
        apBorrar = apLISTA;
        cout << "====================================" << endl;
        imprimir(apBorrar);
        cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
        cin >> respuesta;
    if(respuesta == 1){
        // se borra
        free(apLISTA);
        apLISTA = NULL;
        cout << "El unico miembro fue eliminado de la lista" << endl;
    } // if si lo eliminamos
        return;
    }

    // caso C) lista con 2 o mas nodos
    apPenultimo = apLISTA;
    apBorrar = apLISTA -> next;
    while(apBorrar -> next != NULL){
        apPenultimo = apBorrar;
        apBorrar = apBorrar -> next;
    } // while para moverse al ultimo y penultimo nodo
        cout << "====================================" << endl;
        imprimir(apBorrar);
    cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
    cin >> respuesta;
    if(respuesta == 1){
        // se borra
        free(apBorrar);
        apPenultimo -> next = NULL;
        cout << "El ultimo miembro fue eliminado de la lista" << endl;
    } // if si lo eliminamos
    return;
} // eliminarFinal()

//! consultarLista()
//! ==============================================================
void consultarLista() {
    // Declarar variables
    membresia *apCopia = apLISTA;

    // Validar que esta vacia
    if (apCopia == NULL) {
        cout << "La lista esta vacia" << endl;
        for (int i = 0; i < 4; ++i) {
            Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
            Sleep(166);
        }
        return;
    } // if

    // Mostrar los nodos
    cout << endl << endl;
    cout << "Listado de miembros del Club deportivo Alta Vista" << endl;
    cout << "=================================================" << endl;
    while (apCopia != NULL) {
        // se llama la funcion imprimir y se le envia la direccion del elemento de la lista para imprimirlo
        imprimir(apCopia);
        apCopia = apCopia->next; // Aqui se guarda la direccion del siguiente nodo
    } // while

    return;
} // consultarLista()

//! filtrarEdad()
//! ==============================================================
void filtrarEdad(){
    // declarar variables
    float edadMinima, edadMaximo;
    bool encontrado = false;
    membresia *apCopia = apLISTA;

    // validar que esta vacia
    if (apCopia == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    } // if

    // solicitar el titulo a buscar
    cout << "Ingresa la edad minima a buscar: ";
    cin >> edadMinima;
    cout << "Ingresa la edad maxima a buscar: ";
    cin >> edadMaximo;

    // buscar el videojuego
    cout << endl << endl << "Listado de miembros del Club" << endl;
    cout << "=================================================" << endl;
    while (apCopia != NULL) {
        if (apCopia->edad >= edadMinima && apCopia->edad <= edadMaximo) {
            encontrado = true;
            imprimir(apCopia);
        } // if si lo encontro
        apCopia = apCopia->next; // se guarda la direccion de memoria del siguiente
    } // while
    if(encontrado == true)
        return;
    else
        cout << "Los miembros con edad entre: " << edadMinima << " y " << edadMaximo << " no fueron encontrados" << endl;
    return;
} // filtrarEdad()

//! buscarNombre()
//! ==============================================================
void buscarNombre() {
    // declarar variables
    membresia *apCopia = apLISTA;
    char nombreBuscar[99];

    // validar que esta vacia
    if (apCopia == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }// if

    // solicitar el titulo a buscar
    cout << "Ingresa el nombre a buscar iniciando por apellidos: ";
    cin.ignore();
    cin.getline(nombreBuscar, 99, '\n');

    // buscar el videojuego
    while (apCopia != NULL) {
    if (strcmp(nombreBuscar, apCopia->nombre) == 0) {
        cout << endl << "Resultado de busqueda de miembros" << endl;
        cout << "====================================" << endl;
        imprimir(apCopia);
        return;
    } // if si lo encontro

    apCopia = apCopia->next; //? aqui se guarda la direccion de memoria del siguiente
    }                    // while
    cout << "El miembro con el nombre: " << nombreBuscar << " no fue localizado" << endl;
    for (int i = 0; i < 4; ++i) {
        Beep(500, 200); // Reproduce un sonido de 500 Hz durante 300 ms
        Sleep(166);
    }

    return;
} // buscarNombre()

//! guardarArchivo()
//! ==============================================================
void guardarArchivo(){
    ofstream archivo("textFile.txt", ios::out); // Abrir el archivo en modo escritura

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    membresia *apCopia = apLISTA;
    while (apCopia != NULL) {
        archivo << apCopia->numero << ","
                << apCopia->nombre << ","
                << apCopia->edad << ","
                << apCopia->telefono << ","
                << apCopia->correo << ","
                << apCopia->fechaContrat << ","
                << apCopia->costo << ","
                << apCopia->tipo << ","
                << apCopia->servicios << ","
                << apCopia->sucursal << endl;
        apCopia = apCopia->next;
    }

    archivo.close();
    cout << "Datos guardados en el archivo textFile.txt" << endl;
    return;
} // guardarArchivo()

//! leerArchivo()
//! ==============================================================
void leerArchivo(){
    ifstream archivo("textFile.txt", ios::in); // Abrir el archivo

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    cout << endl << "Listado de miembros del Club deportivo Alta Vista" << endl;
    cout << "=================================================" << endl;
    while (getline(archivo, linea)) {
        // Dividir la linea por comas
        istringstream ss(linea);
        string linea;

        // Imprimir cada campo de la linea
        cout << "Numero de miembro: "; getline(ss, linea, ','); cout << linea << endl;
        // Datos personales
        cout << "Nombre completo: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Edad: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Telefono: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Correo: "; getline(ss, linea, ','); cout << linea << endl;
        // Datos de la membresia
        cout << "Fecha del contrato: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Costo de la mensualidad: $"; getline(ss, linea, ','); cout << linea << endl;
        cout << "Tipo de membresia: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Servicios incluidos: "; getline(ss, linea, ','); cout << linea << endl;
        // Datos de la sucursal
        cout << "Sucursal: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "====================================" << endl;
    }

    archivo.close();
    cout << "Datos leidos del archivo textFile.txt" << endl;
    return;
} // leerArchivo()

//! ordenarElementos()
//! ==============================================================
void ordenarElementos(void) {
    // Declarar apuntadores
    membresia *i = NULL, *j = NULL;
    membresia *paso;
    int vueltas;

    // Caso A - Lista vacia
    if (apLISTA == NULL) {
        system("cls");
        cout << "No existen membresias registradas en la lista. No se puede ordenar la lista." << endl;
        return;
    } // termina if

    // Solicitar memoria para la variable temporal
    paso = (membresia *)malloc(sizeof(membresia));

    // Validar asignacion de memoria
    if (paso == NULL) {
        cout << "No hay memoria suficiente para crear variable de paso." << endl;
        return;
    } // if

    // Calcular el numero de vueltas necesarias para recorrer la lista
    i = apLISTA;
    vueltas = 0;
    while (i->next != NULL) {
        vueltas++;
        i = i->next;
    } // while

    // Lista con dos o mas nodos
    while (vueltas > 0) {
        i = apLISTA;
        // Recorrer toda la lista para colocar un elemento en su lugar
        while (i->next != NULL) {
            j = i->next;
            // Comparar los numeros de membresia, si es necesario intercambiar la informacion de los nodos i y j
            if (i->numero > j->numero) {

                // 1) Copiar i -> paso
                paso->numero = i->numero;
                strcpy(paso->nombre, i->nombre);
                strcpy(paso->fechaContrat, i->fechaContrat);
                paso->costo = i->costo;
                strcpy(paso->tipo, i->tipo);
                strcpy(paso->servicios, i->servicios);
                strcpy(paso->telefono, i->telefono);
                strcpy(paso->sucursal, i->sucursal);
                paso->edad = i->edad;
                strcpy(paso->correo, i->correo);

                // 2) Copiar j -> i
                i->numero = j->numero;
                strcpy(i->nombre, j->nombre);
                strcpy(i->fechaContrat, j->fechaContrat);
                i->costo = j->costo;
                strcpy(i->tipo, j->tipo);
                strcpy(i->servicios, j->servicios);
                strcpy(i->telefono, j->telefono);
                strcpy(i->sucursal, j->sucursal);
                i->edad = j->edad;
                strcpy(i->correo, j->correo);

                // 3) Copiar paso -> j
                j->numero = paso->numero;
                strcpy(j->nombre, paso->nombre);
                strcpy(j->fechaContrat, paso->fechaContrat);
                j->costo = paso->costo;
                strcpy(j->tipo, paso->tipo);
                strcpy(j->servicios, paso->servicios);
                strcpy(j->telefono, paso->telefono);
                strcpy(j->sucursal, paso->sucursal);
                j->edad = paso->edad;
                strcpy(j->correo, paso->correo);

            } // if - intercambia informacion nodos
            i = i->next;
        } // while
        vueltas--;
    } // while

    cout << "Los datos han sido ordenados por numero de membresia." << endl;
    cout << "Ingrese a la OPCION 5 para consultarlos." << endl << endl;
    Sleep(2000);

    return;
} // ordenarLista


//! imprimir()
//! ==============================================================
void imprimir(membresia *apCopia){

    // Numero del miembro
    cout << "Numero de miembro: " << apCopia->numero << endl;
    // Datos personales
    cout << "Nombre completo: " << apCopia->nombre << endl;
    cout << "Edad: " << apCopia->edad << " axos" << endl;
    cout << "Telefono: " << apCopia->telefono << endl;
    cout << "Correo: " << apCopia->correo << endl;
    // Datos de la membresia
    cout << "Fecha del contrato: " << apCopia->fechaContrat << endl;
    cout << "Costo de la mensualidad: $" << apCopia->costo << endl;
    cout << "Tipo de membresia: " << apCopia->tipo << endl;
    cout << "Servicios incluidos: " << apCopia->servicios << endl;
    // Datos de la sucursal
    cout << "Sucursal: " << apCopia->sucursal << endl;
    cout << "====================================" << endl;

    return;
} // imprimir()

//! menu()
//! ==============================================================
void menu(void) {
    cout << endl << endl;
    cout << "Listado de miembros del Club deportivo Alta Vista" << endl;
    cout << "=================================================" << endl;
    cout << "1. Agregar un miembro al inicio de la lista" << endl; //* corregido
    cout << "2. Agregar un miembro al final de la lista" << endl; //* Corregido
    cout << "3. Eliminar al miembro al inicio de la lista" << endl; //* Corregido
    cout << "4. Eliminar al miembro al final de la lista" << endl; //* corregido
    cout << "5. Consultar el listado de miembros" << endl;  //* corregido
    cout << "6. Filtrar Miembros por edad" << endl;        //* Corregido
    cout << "7. Buscar a un miembro por su nombre" << endl; //* corregido
    cout << "8. Guardar los datos en la lista en un archivo" << endl;
    cout << "9. Recuperar los datos del archivo" << endl;
    cout << "10.Odenar los elementos de la lista por un dato especifico" << endl;
    cout << "0. Salir" << endl;

    return;
} // menu()


//================================================================[Arte ASCII y consola]=======================================================

//! logo()
//! ==============================================================
void logo (){

    cout <<"                    Sistema del Club deportivo Alta vista" << endl  << endl <<
         "                                         @%@%                        \n"
         "                                      :@+::*@                        \n"
         "                                     %%-::::+@                       \n"
         "                  =                 @*:::::::=@=  @                  \n"
         "                 @@@              @@=::*@*@+::-#@@@@                 \n"
         "               @%=:*@            @*::=%@   @*::::::*@                \n"
         "              @#::::*@         #@=::*@      =-::::::=@               \n"
         "             @*::::::=@=      @*::-%@       +::::::::=@:             \n"
         "            @+::=%**::-#@   *@+::+@-       @*::=%#@*::-%@            \n"
         "          =@=:::%  @#-::*@+@*::*@@       %@=::+@.  @-:::*@           \n"
         "         @%-::::@   =@-::--+%@@+        @*::-#@    ==::::*@          \n"
         "        @*::::::@     @++%@@          %@=::+@=      +:::::=@+        \n"
         "       @+:::::::@      @@            @*::-#@       @=::::-:-%%       \n"
         "     =@=::#**=::*@           @@@@  =@=::=@+       +#:::%:%=::*@      \n"
         "    %#-:*@@  %:::*:        +@%::=%@#-:-*@         @:::*+ :@#-:+@     \n"
         "   @@@@@@    @#::-#@         @*::::::=@%        +@=::+@    =@@@@@    \n"
         " =@@@         *#:::*@          :::::*@         @%-::+@         *@@@  \n"
         " #             @%=::+@:       %-::=%@         @*:::#@             .  \n"
         "                 @*::-%@    %%=::+@   @@    .@+::=@*                 \n"
         "                  @%=::+@  @*:::#@  -@++@. %%=::*@                   \n"
         "                   -@*::=**=::=%%  *@*::=#%*::+@@                    \n"
         "                     @%=:::::+@.     @*:::::=%@                      \n"
         "                       @*::-*@        @%-:=%@                        \n"
         "                        %@*@*          :@@@                          \n"
         "                          @:                                         \n";
    cout << "Favor de esperar un momento";

    Sleep(1250);
} // logo()

//! consolaBlancoTextoNegro()
//! ==============================================================
void consolaBlancoTextoNegro() {
    // Obtener el manejador de la consola
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Establecer fondo blanco y texto negro
    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

    // Limpiar la consola para aplicar el color atodo el fondo
    system("cls");
} // ConsolaBlancoTextoNegro ()

//! moverVentana()
//! ==============================================================
void moverVentana(int x, int y, int ancho, int alto) {
    HWND consoleWindow = GetConsoleWindow();
    MoveWindow(consoleWindow, x, y, ancho, alto, TRUE);
} // moverVentana()

// Fin de archivo