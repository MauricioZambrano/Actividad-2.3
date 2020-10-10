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

// Función que guarda los registros de la lista doblemente encadenada en un archivo nuevo
// Complejidad: O(n)
void exportarRegistros(DoubleLinkedList& lista, string nombreArchivo){
    ofstream archivo(nombreArchivo);
    
    archivo << lista;

    archivo.close();
}

int main() {
    DoubleLinkedList lista;
    cargaRegistros(lista);
    

    cout << "Espere un momento mientras se ordena la bitácora" << endl;
    cout << "Cargando..." << endl;
    lista.sortIP();
    
    char opcion;
    string ipInicio, ipFin, nombreArchivo;
    
    do{
        cout << endl << "Bienvenid@ a la Bitacora de Errores! Seleccione la acción que desea ejectuar:" << endl;
        cout << "1) Buscar un rango de datos basado en direcciones IP" << endl;
        cout << "2) Transpasar datos ordenados a nuevo archivo" << endl;
        cout << "0) Salir" << endl;
        cin >> opcion;

        switch(opcion){
            case '1':
                cout << endl << "Dirección IP inicial (ej. 1.6.378.65:6772): ";
                cin >> ipInicio;

                cout << "Dirección IP final: ";
                cin >> ipFin;

                cout << endl << *lista.busqueda(ipInicio, ipFin) << endl << endl;
                
                break;
            
            case '2':
                cout << endl << "Tecléa el nombre del archivo en el que deseas almacenar los registros ordenados (Recuerde de agregar el sufijo \'.txt\'): ";
                cin >> nombreArchivo;
                exportarRegistros(lista, nombreArchivo);
                
                break;   
        }

    } while( opcion != '0');

    cout << endl << "¡Hasta la próxima!" << endl << endl;

    return 0;
}