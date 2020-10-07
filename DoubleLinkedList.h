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
        Node* getHead();
        int getSize();
        Registro get(int);
        void addFirst(Registro);
        void addLast(Registro);
        void sortIP();
        int deleteAll();
        friend ostream& operator<<(ostream&, Node*);
        
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

// Función creada para accesar el atributo head
// Utilizado únicamente en la sobrecarga del operador de inserción
Node* DoubleLinkedList::getHead(){
    return head;
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
    Node *aux = head;
    head = new Node(data, nullptr, head);

    if(size == 0)
        tail = head;
    else
        aux->setPrev(head);

    size++;
}

void DoubleLinkedList::addLast(Registro data){
    if(size == 0)
        addFirst(data);
    else{
        Node *aux = tail;
        tail = new Node(data, tail, nullptr);
        aux->setNext(tail);
    }
    
    size++;
}

//Sort by IP
void DoubleLinkedList::sortIP(){
    Registro temp;
    Node *curr, *pas = tail;
    bool interruptor = true;

    while(pas != head && interruptor){
        curr = head;
        interruptor = false;
        while(curr != pas){
            if(*curr > *curr->getNext()){
                temp = curr->getNext()->getData();
                curr->getNext()->setData(curr->getData());
                curr->setData(temp);
                interruptor = true;  
            }

            curr = curr->getNext();
        }
        pas = pas->getPrev();
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

ostream& operator<<(ostream& os, DoubleLinkedList& lista){
    Node *curr = lista.getHead();

    while(curr != nullptr){
        os << curr->getData();
        curr = curr->getNext();
        if(curr != nullptr)
            os << endl;
    }

    return os;
}

#endif
