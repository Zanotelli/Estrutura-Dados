#include "../include/Fecho.h"

// Construtores

Fecho::Fecho(){
    size = 0;
}

Fecho::~Fecho(){}

// Gets

void Fecho::add(Line* line){
	fecho_convexo[size] = line;
	size++;
}

Line* Fecho::pop(){
    Line* aux = fecho_convexo[size-1];
	size--;
	return aux;
}

void Fecho::print(){
    
	for(int i = 0; i < size; i++){
		fecho_convexo[i]->getInit()->print();
	}
}