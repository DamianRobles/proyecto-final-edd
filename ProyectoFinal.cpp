/*
    ! Fecha: miercoles 27 de noviembre de 2024
    ! Autor: Miguel Salvador Calata Rodríguez y Damian Dali Robles de Anda
    ! Practica No.: Proyecto Final
    ! Objetivo: Proyecto Final con LSEA - lista simplemente enlazada abierta
*/

//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
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

//* implementacion de operaciones - funciones
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
    } // if

    // 4) guardar los datos del nuevo miembro
    cout << endl << endl;
    cout << "Ingresa los datos del nuevo miembro" << endl;
    cout << "====================================" << endl;
    
    // Número del miembro
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
        }
    }
    flag = false;

    // Datos de la membresía
    // Datos de la fecha del contrato con verificacion que ingrese la fecha como en el ejemplo
    while(flag == false){
        cout << "Fecha del contrato (ej. 01/12/2024): ";
        cin.getline(tempChar, 30, '\n');
        if(tempChar[2]==47 && tempChar[5]==47){
            flag = true;
            strcpy(apNuevo->fechaContrat, tempChar);
        }
        else{
            cout << "Ingrese la fecha como se indica en el ejemplo" << endl;
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
        // verificación
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
                    cout << "Servicios incluidos: Beneficios de la membresía Plata. Acceso preferencial a las clases y canchas. Asesoramiento personalizado por un entrenador. Descuento en servicios de nutrición y fisioterapia." << endl;
                    strcpy(apNuevo->servicios, "Beneficios de la membresía Plata. Acceso preferencial a las clases y canchas. Asesoramiento personalizado por un entrenador. Descuento en servicios de nutrición y fisioterapia.");
                    strcpy(apNuevo->tipo, "Oro");
                    break;
                case 3:
                    cout << "Servicios incluidos: Beneficios de la membresía Plata y Oro. Entrenador personal exclusivo. Acceso a un área de spa privada. Acceso gratuito a servicios de nutrición y fisioterapia." << endl;
                    strcpy(apNuevo->servicios, "Beneficios de la membresía Plata y Oro. Entrenador personal exclusivo. Acceso a un área de spa privada. Acceso gratuito a servicios de nutrición y fisioterapia.");
                    strcpy(apNuevo->tipo, "Platino");
                    break;
            }
        }
        else{
            cout << "Elige una opcion de la lista" << endl;
        }
    }
    // reinicio de variable flag
    flag = false;
    cin.ignore(); // Limpieza del buffer tras cin>>

    // Datos de la sucursal con verificacion para que ingrese una de las 3 opciones presentadas
    while(flag == false){
        cout << "Seleccione la sucursal (1- Centro  2- Zapopan  3- Tlaquepaque): ";
        cin >> tempInt;
        // verificación
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
    } // if

    // 4) guardar los datos del nuevo miembro
    cout << endl << endl;
    cout << "Ingresa los datos del nuevo miembro" << endl;
    cout << "====================================" << endl;
    
    // Número del miembro
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
        }
    }
    flag = false;

    // Datos de la membresía
    // Datos de la fecha del contrato con verificacion que ingrese la fecha como en el ejemplo
    while(flag == false){
        cout << "Fecha del contrato (ej. 01/12/2024): ";
        cin.getline(tempChar, 30, '\n');
        if(tempChar[2]==47 && tempChar[5]==47){
            flag = true;
            strcpy(apNuevo->fechaContrat, tempChar);
        }
        else{
            cout << "Ingrese la fecha como se indica en el ejemplo" << endl;
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
        // verificación
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
                    cout << "Servicios incluidos: Beneficios de la membresía Plata. Acceso preferencial a las clases y canchas. Asesoramiento personalizado por un entrenador. Descuento en servicios de nutrición y fisioterapia." << endl;
                    strcpy(apNuevo->servicios, "Beneficios de la membresía Plata. Acceso preferencial a las clases y canchas. Asesoramiento personalizado por un entrenador. Descuento en servicios de nutrición y fisioterapia.");
                    strcpy(apNuevo->tipo, "Oro");
                    break;
                case 3:
                    cout << "Servicios incluidos: Beneficios de la membresía Plata y Oro. Entrenador personal exclusivo. Acceso a un área de spa privada. Acceso gratuito a servicios de nutrición y fisioterapia." << endl;
                    strcpy(apNuevo->servicios, "Beneficios de la membresía Plata y Oro. Entrenador personal exclusivo. Acceso a un área de spa privada. Acceso gratuito a servicios de nutrición y fisioterapia.");
                    strcpy(apNuevo->tipo, "Platino");
                    break;
            }
        }
        else{
            cout << "Elige una opcion de la lista" << endl;
        }
    }
    // reinicio de variable flag
    flag = false;
    cin.ignore(); // Limpieza del buffer tras cin>>

    // Datos de la sucursal con verificacion para que ingrese una de las 3 opciones presentadas
    while(flag == false){
        cout << "Seleccione la sucursal (1- Centro  2- Zapopan  3- Tlaquepaque): ";
        cin >> tempInt;
        // verificación
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

    // Validar que esté vacía
    if (apCopia == NULL) {
        cout << "La lista está vacía" << endl;
        return;
    }

    // Mostrar los nodos
    cout << endl << endl;
    cout << "Listado de miembros del Club deportivo Alta Vista" << endl;
    cout << "=================================================" << endl;
    while (apCopia != NULL) {
        // se llama la funcion imprimir y se le envia la direccion del elemento de la lista para imprimirlo
        imprimir(apCopia);
        apCopia = apCopia->next; // Aquí se guarda la dirección del siguiente nodo
    }

    return;
} // consultarLista()

//! filtrarEdad()
//! ==============================================================
void filtrarEdad(){
    // declarar variables
    float edadMinima, edadMaximo;
    bool encontrado = false;
    membresia *apCopia = apLISTA;

    // validar que este vacia
    if (apCopia == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }

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

    // validar que este vacia
    if (apCopia == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }

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
        // Dividir la línea por comas
        istringstream ss(linea);
        string linea;

        // Imprimir cada campo de la línea
        cout << "Numero de miembro: "; getline(ss, linea, ','); cout << linea << endl;
        // Datos personales
        cout << "Nombre completo: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Edad: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Telefono: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Correo: "; getline(ss, linea, ','); cout << linea << endl;
        // Datos de la membresía
        cout << "Fecha del contrato: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Costo de la mensualidad: $"; getline(ss, linea, ','); cout << linea << endl;
        cout << "Tipo de membresia: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "Servicios incluidos: "; getline(ss, linea, ','); cout << linea << endl;
        // Datos de la sucursal
        cout << "Sucursal: "; getline(ss, linea, ','); cout << linea << endl;
        cout << "====================================" << endl;
    }

    archivo.close();
    cout << "Datos leídos del archivo textFile.txt" << endl;
    return;
} // leerArchivo()

//! ordenarElementos()
//! ==============================================================
void ordenarElementos(){

    return;
} // ordenarElementos()

//! imprimir()
//! ==============================================================
void imprimir(membresia *apCopia){

    // Número del miembro
    cout << "Numero de miembro: " << apCopia->numero << endl;
    // Datos personales
    cout << "Nombre completo: " << apCopia->nombre << endl;
    cout << "Edad: " << apCopia->edad << " años" << endl;
    cout << "Telefono: " << apCopia->telefono << endl;
    cout << "Correo: " << apCopia->correo << endl;
    // Datos de la membresía
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
    cout << "2. Agregar un videojuego al final de la lista" << endl;
    cout << "3. Eliminar el videojuego al inicio de la lista" << endl;
    cout << "4. Eliminar el videojuego al final de la lista" << endl;    
    cout << "5. Consultar el listado de miembros" << endl;  //* corregido
    cout << "6. Filtrar videojuegos por precio" << endl;
    cout << "7. Buscar a un miembro por su nombre" << endl; //* corregido
    cout << "8. Guardar los datos en la lista en un archivo (respaldo)" << endl;
    cout << "9. Recuperar los datos del archivo (mostrar en pantalla lo almacenado en el archivo)" << endl;
    cout << "10.Ordenar los elementos de la lista por un dato específico (método ordenamiento)" << endl;
    cout << "0. Salir" << endl;

    return;
} // menu() 
