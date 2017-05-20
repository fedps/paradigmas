#include <cmath>
#include "circle.hpp"

const double PI = 3.14159;
using namespace std;

Circle::Circle(){
	this->r = 0;
}

Circle::Circle(double r){
	this->r = r;
}

double Circle::area () const{
	return PI*pow(this->r,2);
}

string Circle::getNome(){
	return this->nome;
}

void Circle::setTamanho(string tam){
	this->tamanho = tam;
}

string Circle::getTamanho(){
	return this->tamanho;
}