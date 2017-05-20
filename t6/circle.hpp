#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>
#include "shape.hpp"

using namespace std;

class Circle : public Shape{
    private:
       double r;
       string nome = "Circulo";
       string tamanho;
    public:
        Circle();
        Circle(double r);
        double area() const;
        string getNome();
        void setTamanho(string tam);
        string getTamanho();
};
#endif
