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
public:
    Registro();
    Registro(string, int, string, string, string);
    long ipToLong();
    friend ostream& operator<<(ostream&, Registro);
};

Registro::Registro(){
    mes = "";
    dia = 0;
    hora = "";
    direccionIP = "";
    razon = "";
}

Registro::Registro(string mes, int dia, string hora, string direccionIP, string razon){
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->direccionIP = direccionIP;
    this->razon = razon;
}

// Convierte la dirección ip (string) a long para facilitar la comparación entre los datos
// Complejidad: O(n)
long Registro::ipToLong(){
	int idx = 0;
	long datoFinal= 0, dato = 0;
	while (idx < direccionIP.size()){
		if (direccionIP[idx]!= '.' && direccionIP[idx]!=':'){
			dato = dato*10 + direccionIP[idx]-'0';
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

ostream& operator<<(ostream& os, Registro r){
    os  << r.mes << ' ' << r.dia << ' ' << r.hora << ' ' << r.direccionIP << r.razon;

    return os;
}

#endif