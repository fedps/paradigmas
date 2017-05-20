#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>
#include "shape.hpp"

using namespace std;

class Rectangle : public Shape{
    private:
       double b;
       double h;
       string nome = "Retangulo";
       string tamanho;
    public:
        Rectangle();
        Rectangle(double b, double h);
        double area() const;
        string getNome();
        void setTamanho(string tam);
        string getTamanho();
};
#endif
