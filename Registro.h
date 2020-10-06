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
    Registro(string, int, string, string, string);
    string getIP();
};

Registro::Registro(string mes, int dia, string hora, string direccionIP, string razon){
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->direccionIP = direccionIP;
    this->razon = razon;
}

string Registro::getIP(){
    return direccionIP;
}

#endif