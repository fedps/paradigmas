#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>
#include "shape.hpp"

using namespace std;

class Triangle : public Shape{
    private:
       double b;
       double h;
       string nome = "Triangulo";
       string tamanho;
    public:
        Triangle();
        Triangle(double b, double h);
        double area() const;
        string getNome();
        void setTamanho(string tam);
        string getTamanho();
};
#endif
