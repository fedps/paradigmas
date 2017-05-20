#include "triangle.hpp"

using namespace std;

Triangle::Triangle(){
	this->b = 0;
	this->h = 0;
}

Triangle::Triangle(double b, double h){
	this->b = b;
	this->h = h;
}

double Triangle::area () const{
	return b*h/2;
}

string Triangle::getNome(){
	return this->nome;
}

void Triangle::setTamanho(string tam){
	this->tamanho = tam;
}

string Triangle::getTamanho(){
	return this->tamanho;
}