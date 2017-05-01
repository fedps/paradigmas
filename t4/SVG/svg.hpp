#ifndef SVG_H
#define SVG_H
#include "circle.hpp"
#include "point.hpp"

class CircleSvg{
    private:
        Circle c;
        int n; //Número de circulos a serem gerados
    public:
        CircleSvg();
        CircleSvg(Circle c,int n);
        void createCircleSvg(double x, double y, double r);
        void createLineSvg(double x, double y, double r,double x2);
        void createSvg();
};

#endif // SVG_H
