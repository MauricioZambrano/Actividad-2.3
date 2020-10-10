/*
 * Programación de estructuras de datos y algoritmos fundamentales
 * Clase Registro implementada en Actividad 2.3
 * 
 * Equipo 13
 * 
 * Fernando Doddoli Lankenau - A00827038
 * Mauricio Eugenio Zambrano Díaz - A00827055
 * Cristóbal Alberto Escamilla Sada - A00827074
 * 
 * 10 de octubre del 2020
 */

#ifndef Registro_h
#define Registro_h

class Registro{
private:
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razon;
	long ipToLong(string);
public:
    Registro();
    Registro(string, int, string, string, string);
	long convertIP();
    bool operator>=(string);
    bool operator<=(string);
    friend ostream& operator<<(ostream&, Registro);
};

// Constructor por default
Registro::Registro(){
    mes = "";
    dia = 0;
    hora = "";
    direccionIP = "";
    razon = "";
}

// Constructor con parámetros
Registro::Registro(string mes, int dia, string hora, string direccionIP, string razon){
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->direccionIP = direccionIP;
    this->razon = razon;
}

// Convierte la dirección ip (string) a long para facilitar la comparación entre los datos
// Declarado como privado para poder ser implementado en diversas funciones dentro de la clase
// Complejidad: O(n)
long Registro::ipToLong(string ip){
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

// Convierte la dirección IP del registro a tipo long
// Complejidad: O(n)
long Registro::convertIP(){
	return ipToLong(direccionIP);
}

// Sobrecarga del operador "mayor o igual que"
// Utilizado en la función sortIP de DoubleLinkedList para comparar las direcciones
// IP en los registros
// Complejidad: O(n)
bool Registro::operator>=(string ip){
    return convertIP() >= ipToLong(ip);
}

// Sobrecarga del operador "menor o igual que"
// Utilizado en la función sortIP de DoubleLinkedList para comparar las direcciones
// IP en los registros
// Complejidad: O(n)
bool Registro::operator<=(string ip){
    return convertIP() <= ipToLong(ip);
}

// Sobrecarga del operador de inserción para desplegar el Registro completo
// Complejidad: O(1)
ostream& operator<<(ostream& os, Registro r){
    os  << r.mes << ' ' << r.dia << ' ' << r.hora << ' ' << r.direccionIP << r.razon;

    return os;
}

#endif