#include <iostream>
#include <cmath>
#include "circle.hpp"
#include "point.hpp"
#include "svg.hpp"

int main() {
   Circle* c = new Circle(50,50,40);
   CircleSvg* cs = new CircleSvg(*c,4);
   cs->createSvg(); //Criar 10 círculos com centro (50,50) e raio 40
   delete c;
}
