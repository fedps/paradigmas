#include <iostream>
#include <cmath>
#include "circle.hpp"
#include "point.hpp"

const double PI = 3.14159;

Circle::Circle() {
  r = 0.0;
}
Circle::Circle(double a, double b, double c){
  p.setX(a);
  p.setY(b);
  r = c;
}
double Circle::area() {
  return PI * r * r;
}
void Circle::setRadius(double radius){
  r = radius;
}
double Circle::distanceTo(Circle c){
     double H = std::sqrt(pow(p.getX()-c.p.getX(),2) + pow(p.getY()-c.p.getY(),2));
     return H -r -c.r;
}

double Circle::getX(){
    return p.getX();
}

double Circle::getY(){
    return p.getY();
}

double Circle::getR(){
    return r;
}
