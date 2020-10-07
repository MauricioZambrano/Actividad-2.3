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

// Constructor por default
DoubleLinkedList::DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Destructor
DoubleLinkedList::~DoubleLinkedList(){
    deleteAll();
}

// Función creada para accesar el atributo head
// Utilizado únicamente en la sobrecarga del operador de inserción
// Complejidad: O(1)
Node* DoubleLinkedList::getHead(){
    return head;
}

// Regresa el número de nodos en la lista doblemente encadenada
// Complejidad: O(1)
int DoubleLinkedList::getSize(){
    return size;
}

// Agrega un nodo al principio de la lista encadenada, conteniendo el Registro data
// Complejidad: O(1)
void DoubleLinkedList::addFirst(Registro data){
    Node *aux = head;
    head = new Node(data, nullptr, head);

    if(size == 0)
        tail = head;
    else
        aux->setPrev(head);

    size++;
}

// Agrega un nodo al final de la lista encadenada, conteniendo el Registro data
// Complejidad: O(1)
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

// Ordena los nodos en la lista en orden ascendiente de acuerdo a las direcciones IP en sus Registros
// Complejidad: O(n^3)
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

// Borra todos los datos de la lista encadenada
// Complejidad: O(n)
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

// Sobrecarga del operador de inserción, utilizado para desplegar los datos en cada uno de los nodos de la lista
// Complejidad: O(n)
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
