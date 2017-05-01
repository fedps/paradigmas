#include <iostream>
#include <cmath>


class Point {

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

    void move(double dx, double dy){
         x = x + dx;
         y = y + dy;
    }
    double distanceTo(Point p){
         return std::sqrt(pow(x-p.x,2) + pow(y-p.y,2));
    }
};

int main(){
    Point p(1,2);
    /*Aloca pontos*/
    Point **pArray = new Point *[5];
    /*Adiciona valores aos pontos*/
    for (int i=0;i<5;i++)
        pArray[i] = new Point(i,i+1);
    /*Calcula a distância entre os pontos*/
    for (int i=0;i<5;i++)
        std::cout << "A distancia entre o ponto (1,2) e o ponto ("<< i<<","<<i+1<<") é:"<<p.distanceTo(*pArray[i])<< std::endl;

    /*Destrói os pontos criados dinamicamente*/
    for (int i=0;i<5;i++)
        delete pArray[i];
    delete[] pArray;
}
