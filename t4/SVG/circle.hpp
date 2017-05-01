#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.hpp"

class Circle {
    private:
       Point p;
       double r;
    public:
        Circle();
        Circle(double a, double b, double c);
        double area();
        void setRadius(double radius);
        double distanceTo(Circle c);
        double getX();
        double getY();
        double getR();
};
#endif
