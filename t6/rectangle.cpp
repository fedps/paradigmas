#include "rectangle.hpp"

using namespace std;

Rectangle::Rectangle(){
	this->b = 0;
	this->h = 0;
}

Rectangle::Rectangle(double b, double h){
	this->b = b;
	this->h = h;
}

double Rectangle::area () const{
	return b*h;
}

string Rectangle::getNome(){
	return this->nome;
}


void Rectangle::setTamanho(string tam){
	this->tamanho = tam;
}

string Rectangle::getTamanho(){
	return this->tamanho;
}