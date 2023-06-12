#include "../include/Fecho.h"

// Construtores

Fecho::Fecho(){
    size = 0;
    back = 0;
    front = 0;
}

Fecho::~Fecho(){}

// Gets

void Fecho::add(Line* line){
	fecho_convexo[back] = line;
	back = (back + 1) % MAX_DATA_LENGTH;
	size++;
}

Line* Fecho::pop(){
    Line* aux;
	aux = fecho_convexo[front];
	front = (front + 1) % MAX_DATA_LENGTH;
	size--;
	return aux;
}

void Fecho::print(){
    
}