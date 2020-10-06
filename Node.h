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
        Node(Registro);
        Node(Registro, Node*, Node*);
        Registro getData();
        Node* getPrev();
        Node* getNext();
        void setData(Registro);
        void setPrev(Node*);
        void setNext(Node*);
};

Node::Node(Registro data){
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
}

Node::Node(Registro data, Node *prev, Node *next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}

Registro Node::getData(){
    return data;
}

Node* Node::getPrev(){
    return prev;
}

Node* Node::getNext(){
    return next;
}

void Node::setData(Registro data){
    this->data = data;
}

void Node::setPrev(Node *prev){
    this->prev = prev;
}

void Node::setNext(Node *next){
    this->next = next;
}

#endif