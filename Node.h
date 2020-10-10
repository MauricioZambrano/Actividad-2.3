/*
 * Programación de estructuras de datos y algoritmos fundamentales
 * Clase Node implementada en Actividad 2.3
 * 
 * Equipo 13
 * 
 * Fernando Doddoli Lankenau - A00827038
 * Mauricio Eugenio Zambrano Díaz - A00827055
 * Cristóbal Alberto Escamilla Sada - A00827074
 * 
 * 10 de octubre del 2020
 */

#ifndef Node_h
#define Node_h

#include "Registro.h"

class Node{
    private:
        Registro data;
        Node *prev;
        Node *next;
    public:
        Node(Registro, Node*, Node*);
        Registro getData();
        Node* getPrev();
        Node* getNext();
        void setData(Registro);
        void setPrev(Node*);
        void setNext(Node*);
        bool operator>(Node);
};

// Constructor
Node::Node(Registro data, Node *prev, Node *next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}

// Regresa el Registro almacenado en el nodo
// Complejidad: O(1)
Registro Node::getData(){
    return data;
}

// Regresa el apuntador conteniendo la ubicación del nodo anterior en la lista
// Complejidad: O(1)
Node* Node::getPrev(){
    return prev;
}

// Regresa el apuntador conteniendo la ubicación del siguiente en la lista
// Complejidad: O(1)
Node* Node::getNext(){
    return next;
}

// Regresa el registro almacenado en el nodo
// Complejidad: O(1)
void Node::setData(Registro data){
    this->data = data;
}

// Actualiza el valor del apuntador conteniendo la ubicación del nodo anterior en la lista,
// a una nueva dirección en memoria
// Complejidad: O(1)
void Node::setPrev(Node *prev){
    this->prev = prev;
}

// Actualiza el valor del apuntador conteniendo la ubicación del siguiente nodo en la lista,
// a una nueva dirección en memoria
// Complejidad: O(1)
void Node::setNext(Node *next){
    this->next = next;
}

// Sobrecarga del operador "mayor que"
// Utilizado en la función sortIP de DoubleLinkedList
// para comparar las direcciones IP en los registros almacenados dentro de los nodos
// Complejidad: O(n)
bool Node::operator>(Node n){
    return data.convertIP() > n.data.convertIP();
}

#endif
