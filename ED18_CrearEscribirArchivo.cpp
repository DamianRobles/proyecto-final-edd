// ============================================================================
// Fecha: martes 17 de septiembre 2024
// Autor: Rebeca
// Practica No.: 17
// Objetivo: Manipulacion de archivos de texto-Crear y escribir en un archivo
// ============================================================================

// 1) Agregar librería fstream  f- file
#include <fstream>				
#include <iostream>
using namespace std;

int main(void) {
    // 2) Crear un DESCRIPTOR de archivo
    ofstream apArchivo;    
    
    cout << "Hola estamos creando el archivo MisDatos.txt" << endl;
    
    // 3) Crear y Abrir archivo
	apArchivo.open("MisDatos.txt", ios_base::out);    
    
    // 4) Validar el descriptor del archivo
    if ( ! apArchivo ) {        
          cout << "Problema al abrir archivo --> datos.txt" <<endl;
          return(0);
    }
    
    // 5) Guardar los datos en el archivo
    int j=1;
    do {
	    apArchivo << "Soy Alejandro " << j << endl;		
	    apArchivo << "Me gusta la sandia" << endl;
	    apArchivo << "y hoy estoy feliz." << endl;
	    j++;
	} while(j<=10);
	
	// 6) Cerrar el archivo
    apArchivo.close();    
    
    cout << "Terminamos." << endl;
    
    return 0:
}  // main()


