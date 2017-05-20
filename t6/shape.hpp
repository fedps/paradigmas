#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;

class Shape {
	private:
		string nome;
		string tamanho;
    public:
        Shape();
        virtual double area() const;
        virtual string getNome();
        virtual void setTamanho(string tam);
        virtual string getTamanho();
};
#endif
