#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "DoubleLinkedList.h"
#include "Registro.h"


// Cargar los registros de el archivo .txt a un vector de apuntadores de tipo Registro con sus respectivos atributos
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

int main() {



    return 0;
}