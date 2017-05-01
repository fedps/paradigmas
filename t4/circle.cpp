#include <iostream>
#include <cmath>

const double PI = 3.14159;

class Point{
    private:
         double x;
         double y;
    public:
    Point (){
         x = y = 0;
    }

    Point (double x, double y){
         this->x = x;
         this->y = y;
    }

    double getX(){
        return this->x;
    }

    double getY(){
        return this->y;
    }
    void setX(double x){
        this->x = x;
    }
    void setY(double y){
        this->y = y;
    }
};

class Circle {
    private:
       Point p;
       double r;

    public:
       Circle() {
          r = 0.0;
          //std::cout << "Construtor defaut" << std::endl;
       }
       Circle(double a, double b, double c){
          p.setX(a);
          p.setY(b);
          r = c;
       }
       double area() {
          return PI * r * r;
       }
       void setRadius(double radius){
          r = radius;
       }
       double distanceTo(Circle c){
             double H = std::sqrt(pow(p.getX()-c.p.getX(),2) + pow(p.getY()-c.p.getY(),2));
             return H -r -c.r;
        }
};

int main() {
   Circle c1;
   Circle* c2 = new Circle();
   Circle* c3 = new Circle(1,2,3);
   Circle* c4 = new Circle(0,0,100);
   Circle* c5 = new Circle(150,-150,50);
   Circle circs[10];
   c1.setRadius(3);
   c2->setRadius(4);
   //std::cout << c1.area() << std::endl;
   //std::cout << c2->area() << std::endl;
   //std::cout << c3->area() << std::endl;
   std::cout << c4->distanceTo(*c5) << std::endl;
   delete c2;
   delete c3;
   delete c4;
   delete c5;
}


