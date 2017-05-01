#include <iostream>
#include <cmath>
#include "svg.hpp"
#include "circle.hpp"
#include "point.hpp"

CircleSvg::CircleSvg(){
    Circle();
    n = 0;
}

CircleSvg::CircleSvg(Circle c, int n){
    this->c = c;
    this->n = n;
}

/*Gera linha em svg de um círculo*/
void CircleSvg::createCircleSvg(double x, double y, double r){
    std::cout << "<circle cx=\""<<x<<"\" cy=\""<<y<<"\" r=\""<<r<<
                    "\" stroke=\"black\""<< " stroke-width=\"3\" fill=\"red\" />"<<std::endl;
}

/*Gera linha em svg de uma linha*/
void CircleSvg::createLineSvg(double x, double y, double r,double x2){
    std::cout << "<line x1=\""<<x<<"\" y1=\""<<y<<"\" x2=\""<<x2<<"\" y2=\""<<y<<
                    "\" style=\"stroke:rgb(255,255,0);stroke-width:2\" />"<<std::endl;
}

/*Produz o código completo para um arquivo svg com círculos conectados por linhas*/
void CircleSvg::createSvg(){
    double aux = c.getX();
    aux = 2*aux+c.getR();
    std::cout << "<svg height=\""<<2*c.getY()<<"\" width=\""<<n*2*c.getX()<<"\">"<<std::endl; //Tamanho da imagem depende do centro e do número de círculos
    createCircleSvg(c.getX(),c.getY(),c.getR());
    for(int i=1;i<n;i++){
        createCircleSvg(aux,c.getY(),c.getR());
        createLineSvg(c.getX(),c.getY(),c.getR(),aux);
        aux = aux+c.getX()+c.getR(); //variável auxiliar para dar espaçamento entreos círculos
    }
    std::cout<<"</svg>"<<std::endl;
}
