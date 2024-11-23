// ============================================================================
// Fecha: martes 17 de septiembre 2024
// Autor: Rebeca
// Practica No.: 19
// Objetivo: Manipulacion de archivos de texto-Agregar al final de un archivo
// ============================================================================

// 1) Incluir librería fstream
#include <fstream>
#include <iostream>
using namespace std;

int main(void) {
    // 2) Declarar descriptor de archivo
    ofstream apArchivo;
    
    // 3) Abrir el archivo
    apArchivo.open("MisDatos.txt", ios_base::app);  // append
    if ( ! apArchivo ) {
          cout << "Problema al abrir archivo --> datos.txt" <<endl;
          return(0);
    } // if

    // 4) Escribir al final del archivo
    apArchivo << "Ahora soy una nueva linea" << endl;
    apArchivo << "Estoy al final del archivo" << endl;
    apArchivo << "Esto se queda al final final" << endl;

    // Imprime en pantalla
	cout << "Se han agregado 3 lineas al final del archivo." << endl;
	
	// 5) Cerrar el archivo
    apArchivo.close();
    
    return 0;
}  // main()

