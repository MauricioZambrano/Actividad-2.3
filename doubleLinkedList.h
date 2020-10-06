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

#include <iostream>
#include "node.h"
using namespace std;

template <class T>
class doubleLinkedList{
public:
    void addFirst(T data);
    void addLast(T data);
    int deleteAll();
    
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
}

template <class T>
doubleLinkedList<T>::doubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
doubleLinkedList<T>::~doubleLinkedList(){
    deleteAll();
}

//deleteAll
//Complejidad: O(n)
template<class T>
int doubleLinkedList::deleteAll(){
    Node<T> *curr = head;
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
template <class T>
void doubleLinkedList::addFirst(T data){
    //creamos el node
    Node<T> *aux = new Node<T>(data)
    
    //el next de aux es igual a la dirección de head
    aux->setNext(head);
    
    //el prev de aux es igual a la dirección de tail
    aux->setPrev(tail);
    
    //también se puede hacer Node<T> *aux = new Node<T>(data, tail, head);
    
    //El nuevo nodo es el head de la lista
    head = aux;
    size++;
}




