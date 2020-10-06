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

//Sort by IP
void sortBurbuja(DoubleLinkedList &lista){
    int cont = 0, tam = lista->size();
    string temp;
    bool interruptor = true;
    for (int pas=0; pas<tam-1 && interruptor; ++pas){
        interruptor = false;
        for (int j=0; j<tam -1 - pas; ++j){
            cont++;
            if(ipToLong(lista->getNext()->getData()->getIP()) < ipToLong(lista->getData()->getIP())){  //Si IP de sig es menor que ip actual swap
                temp = lista->getNext()->getData()->getIP();        //Poner temp el sig IP
                lista->getNext()->setIp(lista->getData()->getIP());     //Poner IP de next como actual
                lista->setIp(temp);     //Poner actual como temp
                interruptor = true;     //Indicar que si se cambio algo
            }
        }
    }
}


int main() {



    return 0;
}