#ifndef B_NODE_H
#define B_NODE_H
#include <iostream>
#include "kid.h"
using namespace std;
///AUTOR: MARIO GOMEZ PHAYNER
///IMPLEMENTACION DE EL NODO DEL ARBOL B CON EL USO DE TEMPLATES.
template <class Type, int order> class Btree;

template <class Type, int order> class B_node {
// data members:
	friend class Btree< Type, order>;
private:
	int count;
    Kid* data[order-1];
	B_node<Type, order> *childs[order];
// constructor:
public:
	B_node();
    B_node(Kid*);
	bool NodeEmpty() const;
	bool NodeFull() const;
	void mostrarNodo();

//    Kid *kid;
};

template <class Type, int order> B_node< Type,order >::B_node(){

//    kid = NULL;
	this->count = 0;
	for(int i=0;i < order;i++) 
		this->childs[i] = NULL;
}

template <class Type, int order> B_node< Type,order >::B_node(Kid *k){

//    kid = k;
    this->count = 0;
    for(int i=0;i < order;i++)
        this->childs[i] = NULL;
}

template< class Type, int order > bool B_node< Type,order>::NodeFull() const{
	return (count== order-1);
} 
template<  class Type, int order > bool B_node< Type, order>::NodeEmpty() const {
	return (count < (order-1)/2);
}

template< class Type, int order > void B_node< Type,order>::mostrarNodo() { 
	
	for(int i=0; i< this->count ;i++) 
        cout <<"\t"<< data[i]->nombre<<", ";
	
	cout <<"\n"; 
	
}

#endif
