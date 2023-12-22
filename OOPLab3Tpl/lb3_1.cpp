#include <iostream>
#include <math.h>

class Circle{
    double r;
    unsigned int color;

    public:
    
    Circle() : r(1.0), color(0) {}
    
    Circle(double ri) : r(ri), color(0) {}

    Circle(int ic) : r(1.0) {if (ic >= 0) color = ic; else color = 0;}

    Circle(double r, int c){
        this -> r = r;
        if(c >= 0) color = c;
        else color = 0;
    }

    double getR()const{ return r;}

    void setR(double r){
        if(r < 0 || r > 1.e+100){
            std::cout << "Error set r" << std::endl;
            return;
        }   
        this -> r = r;
    }

    double getColor() const{
        return color;
    }

    void setColor(int c){
        if(c < 0 || c > 10000){
            std::cout << "Error set color" << std::endl;
            return;
        }
        this -> color = c;
    }

    double S(){
        return 3.14 * r * r;
    }

    double C(){
        return 2 * r * 3.14;
    }

    void printInfo(){
        std::cout << "r = " << r << std::endl << "color = " << color;
        std::cout << "S = " << S() << std::endl << "C = " << C();
    }

};


int main(){

    Circle obj;
    obj.printInfo();

    double in_r;
    int in_color;
    std::cout << std::endl;
    std::cin >> in_r >> in_color;

    Circle obj1(in_r), obj2(in_color), obj3(in_r, in_color);
    obj1.printInfo();
    obj2.printInfo();
    obj3.printInfo();
    obj.setR(-5);
    obj.printInfo();
    obj.setR(5);
    obj.printInfo();
    obj.setR(2.e100);
    obj.printInfo();
    obj.setColor(-10);
    obj.printInfo();
    obj.setColor(10);
    obj.printInfo();
    obj.setColor(10001);
    obj.printInfo();

    std::cout<<" End testing";

    return 0;
}   