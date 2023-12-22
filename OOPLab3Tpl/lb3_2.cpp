#include <iostream>
#include <vector>

class Vector{
    double* d;
    int num;
    int state = 0;

    public:

    Vector();
    Vector(int n);
    Vector(int n, double value);
    Vector(int n, Vector*);
    Vector(const Vector& other);

    Vector& operator=(const Vector& other);

    ~Vector(){
        std::cout << "del";
        if(d) delete[] d;
    }

    void setElement(int index, double value = 0.0);
    double getElement(int index);

    Vector add(const Vector& other) const; 
    Vector subtract(const Vector& other) const; 
    Vector multiply(double scalar) const; 
    Vector divide(double scalar);

    bool isEqual(const Vector& other) const;
    bool isGreaterThan(const Vector& other) const;
    bool isLessThan(const Vector& other) const;

    void print() const;
    void input();
};

Vector::Vector() : Vector(1) {}

Vector::Vector(int n){
    if (n <= 0) n = 1; 
    num = n;
    d = new double[num];
    for (int i = 0; i < n; i++){
        d[i] = 0.0;
    }
}

Vector::Vector(int n, double value) : Vector(n){
    for (int i = 0; i < num; i++){
        d[i] = value;
    }
}

Vector::Vector(int n, Vector* p) : Vector(n){
    if (p != nullptr) {
        for (int i = 0; i < num; i++){
            d[i] = p->getElement(i);
        }
    }
}

Vector::Vector(const Vector& other) {
    num = other.num;
    d = new double[num];
    state = 0;
    for (int i = 0; i < num; i++){
        d[i] = other.d[i];
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (num != other.num){
        if (d) delete[] d;
        num = other.num;
        d = new double[num];
        state = 0;
    }
    for (int i = 0; i < num; i++){
        d[i] = other.d[i];
    }
    return *this;
}


void Vector::setElement(int index, double value){
    if (index >= 0 && index < num){
        d[index] = value;
    }
    else{
        state = 1; 
    }
}

double Vector::getElement(int index){
    if (index >= 0 && index < num){
        return d[index];
    }
    else{
        state = 1;
        return 0.0;
    }
}


Vector Vector::add(const Vector& other) const{
    int tnum = num < other.num ? num : other.num;
    Vector tmp(tnum);
    for (int i = 0; i < tnum; i++) tmp.d[i] = d[i] + other.d[i];
    return tmp;
}

Vector Vector::subtract(const Vector& other) const{
    int tnum = num < other.num ? num : other.num;
    Vector tmp(tnum);
    for (int i = 0; i < tnum; i++) tmp.d[i] = d[i] - other.d[i];
    return tmp;
}


Vector Vector::multiply(double scalar) const{
    Vector tmp(num);
    for (int i = 0; i < num; i++) tmp.d[i] = d[i] * scalar;
    return tmp;
}


Vector Vector::divide(double scalar){
    if (scalar != 0) {
        Vector tmp(num);
        for (int i = 0; i < num; i++) tmp.d[i] = d[i];
        return tmp;
    }
    else {
        state = 2; 
        return Vector(1);
    }
}


void Vector::print() const{
    for (int i = 0; i < num; i++) {
        std::cout << "d[" << i << "] = " << d[i] << '\t';
    }
    std::cout << std::endl;
}


bool Vector::isEqual(const Vector& other) const{
    if (num != other.num) return false;
    for (int i = 0; i < num; i++) {
        if (d[i] != other.d[i]) return false;
    }
    return true;
}


bool Vector::isGreaterThan(const Vector& other) const {
    int tnum = num < other.num ? num : other.num;
    for (int i = 0; i < tnum; i++) {
        if (d[i] > other.d[i]) return true;
        else if (d[i] < other.d[i]) return false;
    }
    return num > other.num;
}


bool Vector::isLessThan(const Vector& other) const {
    int tnum = num < other.num ? num : other.num;
    for (int i = 0; i < tnum; i++) {
        if (d[i] < other.d[i]) return true;
        else if (d[i] > other.d[i]) return false;
    }
    return num < other.num;
}


void Vector::input() {
    int in_num = 0;
    do {
        std::cout << "Input size Vec\n";
        std::cin >> in_num;
    } while (in_num <= 0);

    if (num != in_num) {
        num = in_num;
        if (d) delete[] d;
        d = new double[num];
    }

    for (int i = 0; i < num; i++) {
        std::cout << "v[" << i << "] = ";
        std::cin >> d[i];
    }
}


int main() {
    Vector v1(3, 2.0);
    Vector v2(3, 1.5);

    Vector resultAdd = v1.add(v2);
    Vector resultSubtract = v1.subtract(v2);
    Vector resultMultiply = v1.multiply(2.0);
    Vector resultDivide = v1.divide(2.0);

    std::cout << "v1: ";
    v1.print();

    std::cout << "v2: ";
    v2.print();

    std::cout << "v1 + v2: ";
    resultAdd.print();

    std::cout << "v1 - v2: ";
    resultSubtract.print();

    std::cout << "v1 * 2.0: ";
    resultMultiply.print();

    std::cout << "v1 / 2.0: ";
    resultDivide.print();

    if (v1.isEqual(v2))
        std::cout << "v1 і v2 рівні\n";
    else if (v1.isGreaterThan(v2))
        std::cout << "v1 більший за v2\n";
    else if (v1.isLessThan(v2))
        std::cout << "v1 менший за v2\n";

    Vector v3;
    v3.input();

    std::cout << "v3: ";
    v3.print();

    return 0;
}
