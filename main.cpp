/*
 * Programación de estructuras de datos y algoritmos fundamentales
 * Actividad 2.3 - Actividad Integral estructura de datos lineales
 * 
 * Equipo 13
 * 
 * Fernando Doddoli Lankenau - A00827038
 * Mauricio Eugenio Zambrano Díaz - A00827055
 * Cristóbal Alberto Escamilla Sada - A00827074
 * 
 * 10 de octubre del 2020
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "DoubleLinkedList.h"
#include "Registro.h"


// Carga los registros del archivo .txt a una double linked list almacenando objetos de tipo Registro
// Complejidad: O(n)
void cargaRegistros(DoubleLinkedList &lista){
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razon;
    
    ifstream archivo("bitacora.txt");
    
    while(archivo >> mes >> dia >> hora >> direccionIP){
        getline(archivo, razon);
        lista.addLast(Registro(mes, dia, hora, direccionIP, razon));
    }
    
    archivo.close();  
}

// Descripción: Función que guarda los registros ordenados en un archivo nuevo
// Complejidad: O(n)
void exportarRegistros(DoubleLinkedList& lista, string nombreArchivo){
    ofstream archivo(nombreArchivo);
    
    archivo << lista;

    archivo.close();
}

int main() {


    return 0;
}