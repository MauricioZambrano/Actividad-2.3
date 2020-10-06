/*
 * Programación de estructuras de datos y algoritmos fundamentales
 * Clase DoubleLinkedList implementada en Actividad 2.3
 * 
 * Equipo 13
 * 
 * Fernando Doddoli Lankenau - A00827038
 * Mauricio Eugenio Zambrano Díaz - A00827055
 * Cristóbal Alberto Escamilla Sada - A00827074
 * 
 * 10 de octubre del 2020
 */

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include "Node.h"
#include "Registro.h"

class DoubleLinkedList{
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        void addFirst(Registro);
        void addLast(Registro);
        int deleteAll();
        
    private:
        Node *head;
        Node *tail;
        int size;
};

DoubleLinkedList::DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}


DoubleLinkedList::~DoubleLinkedList(){
    deleteAll();
}

//deleteAll
//Complejidad: O(n)
int DoubleLinkedList::deleteAll(){
    Node *curr = head;
    while(head != nullptr){
        head = head->getNext(); //Avanzo head una pos
        delete curr; //Libero un nodo
        curr = head; //Pongo a curr alineado con head
    }
    int sizeAux = size;
    size = 0;
    return sizeAux;
}

//addFirst
//Complejidad: O(1)
void DoubleLinkedList::addFirst(Registro data){
    //creamos el node
    Node *aux = new Node(data)
    
    //el next de aux es igual a la dirección de head
    aux->setNext(head);
    
    //el prev de aux es igual a la dirección de tail
    aux->setPrev(tail);
    
    //también se puede hacer Node<T> *aux = new Node<T>(data, tail, head);
    
    //El nuevo nodo es el head de la lista
    head = aux;
    size++;
}

#endif
