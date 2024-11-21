/*
  ! Fecha: jueves 19 de septiembre de 2024
          martes 24 de septiembre de 2024
          jueves 26 de septiembre de 2024
          jueves 3 de octubre de 2024
  ! Autor: Dali
  ! Practica No.: 21
  ! Objetivo: LSEA - lista simplemente enlazada abierta
*/

//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//* tda's
struct videojuego {
  // 1. parte informacion
  char titulo[30];
  char genero[20];
  char clasificacion[20];
  float precio;
  // 2. apuntador al siguiente elemento
  videojuego *next;
};

//* operaciones de LSEA
void agregarInicio();
void consultarLista();
void buscarTitulo();
void agregarFinal();
void eliminarFinal();
void agregarSegundo();
void eliminarSegundo();
void filtrarPrecio(); // TAREA 1
void eliminarInicio(); // TAREA 2
void menu();

//* variables globales
// apuntador a mi lista
videojuego *apLISTA = NULL;

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
  videojuego *apNuevo = NULL;

  // 2) solicitar memoria dinamica
  apNuevo = (videojuego *)malloc(sizeof(videojuego));

  // 3) validar el apuntador
  if (apNuevo == NULL) {
    cout << "No se tiene memoria suficiente" << endl;
  } // if

  // 4) guardar los datos del nuevo videojuego
  cout << endl << endl;
  cout << "Ingresa los datos del nuevo videojuego" << endl;
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
  // declarar variables
  videojuego *apCopia = apLISTA;

  // validar que este vacia
  if (apCopia == NULL) {
    cout << "La lista esta vacia" << endl;
    return;
  }
  // mostrar los nodos
  cout << "Listado de videojuegos" << endl;
  cout << "La lista inicia en la direccion: " << apLISTA << endl;
  while (apCopia != NULL) {
    cout << endl << endl;
    cout << "Direccion de memoria de este nodo: " << apCopia << endl;
    cout << "Listado de videojuegos" << endl;
    cout << "======================" << endl;
    cout << "Titulo: " << apCopia->titulo << endl;
    cout << "Genero: " << apCopia->genero << endl;
    cout << "Clasificacion: " << apCopia->clasificacion << endl;
    cout << "Precio: " << apCopia->precio << endl;
    cout << "Direccion de memoria del siguiente nodo: " << apCopia->next;
    apCopia =
        apCopia->next; //? aqui se guarda la direccion de memoria del siguiente
  }                    // while

  return;
} // consultarLista()

//! buscarTitulo()
//! ==============================================================
void buscarTitulo() {
  // declarar variables
  videojuego *apCopia = apLISTA;
  char titBuscar[30];

  // validar que este vacia
  if (apCopia == NULL) {
    cout << "La lista esta vacia" << endl;
    return;
  }

  // solicitar el titulo a buscar
  cout << "Ingresa el titulo a buscar: ";
  cin.ignore();
  cin.getline(titBuscar, 30, '\n');

  // buscar el videojuego
  cout << "Listado de videojuegos" << endl;
  while (apCopia != NULL) {
    if (strcmp(titBuscar, apCopia->titulo) == 0) {
      cout << "Listado de videojuegos" << endl;
      cout << "======================" << endl;
      cout << "Titulo: " << apCopia->titulo << endl;
      cout << "Genero: " << apCopia->genero << endl;
      cout << "Clasificacion: " << apCopia->clasificacion << endl;
      cout << "Precio: " << apCopia->precio;
      return;
    } // if si lo encontro

    apCopia = apCopia->next; //? aqui se guarda la direccion de memoria del siguiente
  }                    // while
  cout << "El videojuego con el titulo: " << titBuscar << " no fue localizado"
      << endl;

  return;
} // buscarTitulo()


//! agregarFinal()
//! ==============================================================
void agregarFinal(){
  // 1) declarar un apuntador
  videojuego *apNuevo = NULL;
  videojuego *apCopia = apLISTA;

  // 2) solicitar memoria dinamica
  apNuevo = (videojuego *)malloc(sizeof(videojuego));

  // 3) validar el apuntador
  if (apNuevo == NULL) {
    cout << "No se tiene memoria suficiente" << endl;
  } // if

  // 4) guardar los datos del nuevo videojuego
  cout << endl << endl;
  cout << "Ingresa los datos del nuevo videojuego" << endl;
  cout << "Titulo: ";
  cin.ignore();
  cin.getline(apNuevo->titulo, 30, '\n');
  cout << "Genero: ";
  cin.getline(apNuevo->genero, 20, '\n');
  cout << "Clasificacion: ";
  cin.getline(apNuevo->clasificacion, 20, '\n');
  cout << "Precio: ";
  cin >> apNuevo->precio;

  // 5) agregarlos a la LSEA
  // Caso A) lista vacia
  if(apLISTA == NULL){
    apLISTA = apNuevo;
    apNuevo -> next = NULL;
    cout << "Videojuego agregado correctamente al final de la lista" << endl;
    return;
  } // if cuando lista esta vacia

  // caso B) lista no vacia
  while(apCopia->next != NULL){
    apCopia = apCopia -> next;    
  } // while posiscionarme en el ultimo nodo
  apCopia -> next = apNuevo;
  apNuevo -> next = NULL;
  cout << "Videojuego agregado correctamente al final de la lista" << endl;

} // agregarFinal()

//! agregarSegundo()  TAREA
//! ==============================================================
void agregarSegundo(){
  // 1) declarar un apuntador
  videojuego *apNuevo = NULL;

  // 2) solicitar memoria dinamica
  apNuevo = (videojuego *)malloc(sizeof(videojuego));

  // 3) validar el apuntador
  if (apNuevo == NULL) {
    cout << "No se tiene memoria suficiente" << endl;
  } // if

  // 4) guardar los datos del nuevo videojuego
  cout << endl << endl;
  cout << "Ingresa los datos del nuevo videojuego" << endl;
  cout << "Titulo: ";
  cin.ignore();
  cin.getline(apNuevo->titulo, 30, '\n');
  cout << "Genero: ";
  cin.getline(apNuevo->genero, 20, '\n');
  cout << "Clasificacion: ";
  cin.getline(apNuevo->clasificacion, 20, '\n');
  cout << "Precio: ";
  cin >> apNuevo->precio;

  // 5) agregarlos a la LSEA
  // caso A) lista vacia
  if(apLISTA == NULL){
    apLISTA = apNuevo;
    apLISTA -> next = NULL;
    cout << "La lista estaba vacia. El videojuego quedo agregado al inicio de la lista" << endl;
    return;
  } // if - lista vacia

  // caso B) lista con un unico nodo
  if(apLISTA->next == NULL){
    apLISTA->next = apNuevo;
    apNuevo->next = NULL;
    cout << "El videojuego se agrego en la 2da posicion de la lista" << endl;
    return;
  } // if - lista con 1 nodo

  // caso C) lista con 2 o mas nodos
  apNuevo -> next = apLISTA -> next;
  apLISTA -> next = apNuevo;
  cout << "El videojuego se agrego en la 2da posicion de la lista" << endl;
  
  return;
} // agrearSegundo()

//! eliminarSegundo()  TAREA
//! ==============================================================
void eliminarSegundo(){
  // 1) declarar  de variables
  videojuego *apBorrar;
  int respuesta;

  // caso A) lista vacia
  if(apLISTA == NULL){
    cout << "La lista esta vacia" << endl;
    return;
  }
  // caso B) lista con 1 unico nodo
  if(apLISTA -> next  == NULL){
    cout << "La lista solo tiene un videojuego y es el sigueinte:" << endl;
    cout << "======================" << endl;
    cout << "Titulo: " << apLISTA->titulo << endl;
    cout << "Genero: " << apLISTA->genero << endl;
    cout << "Clasificacion: " << apLISTA->clasificacion << endl;
    cout << "Precio: " << apLISTA->precio;
    cout << endl << "======================" << endl;
    cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
    cin >> respuesta;
    if(respuesta == 1){
      // se borra
      free(apLISTA);
      apLISTA = NULL;
      cout << "El videojuego fue eliminado de la lista" << endl;
    } // if si lo eliminamos
    return;
  }

  // caso C) lista con 2 o mas nodos
  apBorrar = apLISTA -> next;
  cout << "======================" << endl;
  cout << "Titulo: " << apBorrar->titulo << endl;
  cout << "Genero: " << apBorrar->genero << endl;
  cout << "Clasificacion: " << apBorrar->clasificacion << endl;
  cout << "Precio: " << apBorrar->precio;
  cout << endl << "======================" << endl;
  cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
  cin >> respuesta;
  if(respuesta == 1){
    // se borra
    apLISTA -> next = apBorrar -> next;
    free(apBorrar);
    cout << "El videojuego fue eliminado de la lista" << endl;
  } // if si lo eliminamos
  
  return;
} // eliminarSegundo()

//! eliminarFinal() 
//! ==============================================================
void eliminarFinal(){
  // 1) declarar  de variables
  videojuego *apBorrar, *apPenultimo;
  int respuesta;

  // caso A) lista vacia
  if(apLISTA == NULL){
    cout << "La lista esta vacia" << endl;
    return;
  }
  // caso B) lista con 1 unico nodo
  if(apLISTA -> next  == NULL){
      cout << "======================" << endl;
      cout << "Titulo: " << apLISTA->titulo << endl;
      cout << "Genero: " << apLISTA->genero << endl;
      cout << "Clasificacion: " << apLISTA->clasificacion << endl;
      cout << "Precio: " << apLISTA->precio;
      cout << endl << "======================" << endl;
      cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
      cin >> respuesta;
      if(respuesta == 1){
        // se borra
        free(apLISTA);
        apLISTA = NULL;
        cout << "El videojuego fue eliminado de la lista" << endl;
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
  cout << "======================" << endl;
  cout << "Titulo: " << apBorrar->titulo << endl;
  cout << "Genero: " << apBorrar->genero << endl;
  cout << "Clasificacion: " << apBorrar->clasificacion << endl;
  cout << "Precio: " << apBorrar->precio;
  cout << endl << "======================" << endl;
  cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
  cin >> respuesta;
  if(respuesta == 1){
    // se borra
    free(apBorrar);
    apPenultimo -> next = NULL;
    cout << "El videojuego fue eliminado de la lista" << endl;
  } // if si lo eliminamos
  return;
} // eliminarFinal()

//! filtrarPrecio()  TAREA
//! ==============================================================
void filtrarPrecio(){
//? se debe den de mostrar todos los juegos que esten en el rango del precio con un if min && max
//? declarar var bool para indicar si encontro algun dato o no
//? if encontrado == false, mostrar que no se encontro nada
// declarar variables
float precioMinimo, precioMaximo;
bool encontrado = false;
videojuego *apCopia = apLISTA;

// validar que este vacia
if (apCopia == NULL) {
  cout << "La lista esta vacia" << endl;
  return;
}

// solicitar el titulo a buscar
cout << "Ingresa el precio minimo del videojuego a buscar: ";
cin >> precioMinimo;
cout << "Ingresa el precio maximo del videojuego a buscar: ";
cin >> precioMaximo;

// buscar el videojuego
while (apCopia != NULL) {
  if (apCopia->precio >= precioMinimo && apCopia->precio <= precioMaximo) {
    encontrado = true;
    cout << endl << endl << "Listado de videojuegos" << endl;
    cout << "======================" << endl;
    cout << "Titulo: " << apCopia->titulo << endl;
    cout << "Genero: " << apCopia->genero << endl;
    cout << "Clasificacion: " << apCopia->clasificacion << endl;
    cout << "Precio: " << apCopia->precio;
  } // if si lo encontro
  apCopia = apCopia->next; //? aqui se guarda la direccion de memoria del siguiente
} // while
if(encontrado == true)
  return;
else
  cout << "Los videojuegos con precios entre: " << precioMinimo << " y " << precioMaximo << " no fue encontrado" << endl;
return;
} // filtrarPrecio()

//! eliminarInicio()  TAREA
//! ==============================================================
void eliminarInicio(){
// 1) declarar variables
videojuego *apBorrar;
int respuesta;

// caso A) lista vacia
  if(apLISTA == NULL){
    cout << "La lista esta vacia" << endl;
    return;
  }

  // caso B) lista con 1 nodo
  if(apLISTA -> next  == NULL){
      cout << "======================" << endl;
      cout << "Titulo: " << apLISTA->titulo << endl;
      cout << "Genero: " << apLISTA->genero << endl;
      cout << "Clasificacion: " << apLISTA->clasificacion << endl;
      cout << "Precio: " << apLISTA->precio;
      cout << endl << "======================" << endl;
      cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
      cin >> respuesta;
      if(respuesta == 1){
        // se borra
        free(apLISTA);
        apLISTA = NULL;
        cout << "El unico videojuego fue eliminado de la lista" << endl;
      } // if si lo eliminamos
      return;
  }

  // caso C) lista con varios nodos
  if(apLISTA -> next != NULL){
    apBorrar = apLISTA;
    cout << "======================" << endl;
    cout << "Titulo: " << apBorrar->titulo << endl;
    cout << "Genero: " << apBorrar->genero << endl;
    cout << "Clasificacion: " << apBorrar->clasificacion << endl;
    cout << "Precio: " << apBorrar->precio;
    cout << endl << "======================" << endl;
    cout << "Estas seguro de que quieres eliminarlo? (1 - Si, 2 - No): ";
    cin >> respuesta;
    if(respuesta == 1){
      // se borra
      apLISTA = apLISTA -> next;
      free(apBorrar);
      cout << "El videojuego fue eliminado de la lista" << endl;
    } // if si lo eliminamos
    return;
  }


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
