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
        lista.addLast(new Registro(mes, dia, hora, direccionIP, razon));
    }
    
    archivo.close();  
}

// Reescribe la dirección ip (string) a long para facilitar la comparación entre los datos
// Complejidad: O(n)
long ipToLong(string ip){
	int idx = 0;
	long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
		if (ip[idx]!= '.' && ip[idx]!=':'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*10000 + dato;
	return datoFinal;
}


int main() {



    return 0;
}