#include "shape.hpp"
#include <string>

using namespace std;

Shape::Shape(){

}

double Shape::area() const{

}

string Shape::getNome(){
	return this->nome;
}

void Shape::setTamanho(string tam){
	this->tamanho = tam;
}

string Shape::getTamanho(){
	return this->tamanho;
}