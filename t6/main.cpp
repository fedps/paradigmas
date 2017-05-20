#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

using namespace std;

double fRand(double fMin, double fMax){
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

bool cmpTam(const Shape* s1, const Shape* s2){
	return s1->area() > s2->area();
}

/*
Pequeno:14 a 15 cm2 Valor: R$ 0,30
Medio:15 a 16 cm2 Valor: R$ 0,40
Grande:16 a 17 cm2 Valor: R$ 0,50
*/

int main(){
	double r; //raio
	double h; //altura
	double b; //base
	int pequeno = 0, medio = 0, grande = 0;
	srand (time(0)); //seed para função random
	int N; //número total de biscoitos
	int aux = 0, aux1 = 0, aux2 = 0; //auxiliar para definir a quantidade de cada tipo de biscoito
	vector<Shape*> v;
	
	cout<<"Digite o numero total de biscoitos: "<<endl;
	cin>>N;

	/*
	Aqui faz a separação de quantos formas de acordo com o total N, como são programadores podem ter feito círculos e esquecido
	de deixar massa para fazer retângulos e triângulos :)
	*/
	if (N!=0)
		aux = rand() % N + 1;
	if (N - aux != 0)
		aux1 = rand()%(N-aux)+1;
	if (N-aux-aux1 !=0)
		aux2 = N-aux-aux1;

	for(int i=0; i<aux;i++){
		r = fRand(2.11101,2.32621); //valores mínimos e máximos de raio para o círculo ter entre 14 e 17 cm2
		v.push_back(new Circle(r));
	}

	for(int i=0; i<aux1;i++){
		h = fRand(3.742,4.123); //valores mínimos e máximos de altura para o círculo ter entre 14 e 17 cm2
		b = fRand(3.742,4.123); //valores mínimos e máximos de base para o círculo ter entre 14 e 17 cm2
		v.push_back(new Rectangle(b,h));
	}
	
	for(int i=0; i<aux2;i++){
		h = fRand(3.742,4.123); //valores mínimos e máximos de altura para o círculo ter entre 14 e 17 cm2
		b = fRand(7.484,8.246); //valores mínimos e máximos de base para o círculo ter entre 14 e 17 cm2
		v.push_back(new Triangle(b,h));
	}

	sort(v.begin(),v.end(),cmpTam);

	/*
	Se a area for menor que 15 o tamanho é pequeno, se for maior que 16 é grande, o que sobra são de tamanho médio
	*/
	vector<Shape*>::iterator it;
	for(it = v.begin(); it != v.end(); it++){
		if((*it)->area()<=15){
			(*it)->setTamanho("Pequeno");
			pequeno++;
		}
		else if((*it)->area()>16){
			(*it)->setTamanho("Grande");
			grande++;
		}
		else{
			(*it)->setTamanho("Medio");
			medio++;
		}
		cout<<setprecision(4)<<(*it)->getNome()<<": "<<(*it)->area()<<" "<<(*it)->getTamanho()<<endl;		
	}
	cout<<"Número de biscoito por tamanho:\n"<<"Grande: "<<grande<<"\nMedio: "<< medio<< "\nPequeno: "<<pequeno<<endl;
	cout<<"Valor total arrecadado: R$ "<<(grande*0.5+medio*0.4+pequeno*0.3)<<endl;
}