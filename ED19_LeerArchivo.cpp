// ============================================================================
// Fecha: martes 17 de septiembre 2024
// Autor: Rebeca
// Práctica No.: 18
// Objetivo: Manipulacion de archivos de texto-Leer desde un archivo
// ============================================================================

// 1) Incluir librería fstream
#include <fstream>
#include <iostream>
using namespace std;

int main( ) {
    // 2) Declarar el descriptor del archivo para Lectura
	ifstream apArchivo;     
	string linea;      
	
	// 3) Abrir el archivo 
	apArchivo.open("MisDatos.txt");
	if ( ! apArchivo.is_open( )  )   {
       	cout << "Problema al abrir archivo --> MisDatos.txt" <<endl;
     	return(0);
  	} // if
  	
  	// 4) Leer el contenido del archivo y mostrarlo en pantalla
    while ( ! apArchivo.eof( ) )  {
   	    getline(apArchivo,linea);
   	    cout << linea << endl;
	} // while
	  
	// 5) Cerrar el archivo
    apArchivo.close();
    
    return 0;
}  // main()

