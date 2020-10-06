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
        int getSize();
        Registro get(int);
        void addFirst(Registro);
        void addLast(Registro);
        void sortIP();
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

int DoubleLinkedList::getSize(){
    return size;
}

Registro DoubleLinkedList::get(int pos){
    Node *curr = head;

    for(int i = 1; i <= pos; i++)
        curr = curr->getNext();
    
    return curr->getData();
}

//addFirst
//Complejidad: O(1)
void DoubleLinkedList::addFirst(Registro data){
    head = new Node(data, nullptr, head);
    size++;
}

void DoubleLinkedList::addLast(Registro data){
    tail = new Node(data, tail, nullptr);
    size++;
}

//Sort by IP
void DoubleLinkedList::sortIP(){
    Registro temp;
    Node *curr = head;
    bool interruptor = true;

    for(int pas = 0; pas < size - 1 && interruptor; ++pas){
        interruptor = false;
        for(int j = 0; j < size - 1 - pas; ++j){
            if(vec[j] > vec[j + 1]){
                temp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = temp;
                interruptor = true;
                
            }
        }
    }
}

//deleteAll
//Complejidad: O(n)
int DoubleLinkedList::deleteAll(){
    Node *curr = head;
    while(head != nullptr){
        head = head->getNext();
        delete curr;
        curr = head;
    }
    int sizeAux = size;
    size = 0;
    return sizeAux;
}

#endif
