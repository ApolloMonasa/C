/*************************************************************************
	> File Name: 5-1-24050612.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 15 May 2025 01:36:36 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
//1
class Circle {
protected:
    double radius;
public:
    Circle(double r) : radius(r) {}
};

class Sphere : public Circle {
public:
    Sphere(double r) : Circle(r) {}
    double surfaceArea() {
        return 4 * M_PI * radius * radius;
    }
    double volume() {
        return (4.0/3)*M_PI*radius*radius*radius;
    }
    void output() {
        cout << "Sphere - SurfaceArea : " << surfaceArea() << ", Volume : " << volume() << '\n';
    }
};

class Cylinder : public Circle {
    double height;
public:
    Cylinder(double r, double h) : Circle(r), height(h) {}
    double surfaceArea() {
        return 2*M_PI*radius*(radius+height);
    }
    double volume() {
        return M_PI*radius*radius*height;
    }
    void output() {
        cout << "Cylinder - SurfaceArea : " << surfaceArea() << ", Volume : " << volume() << '\n';
    }
};

class Cone : public Circle {
    double height;
public:
    Cone(double r, double h) : Circle(r), height(h) {}
    double surfaceArea() {
        return M_PI*radius*(radius+sqrt(height*height+radius*radius));
    }
    double volume() {
        return M_PI*radius*radius*height/3.0;
    }
    void output() {
        cout << "Cone - SurfaceArea : " << surfaceArea() << ", Volume : " << volume() << '\n';
    }
};
//2
class Mammal {
protected:
    string color;
    double weight;
    static int cnt;
public:
    Mammal(const string& c, double w) : color(c), weight(w) {
        cnt++;
    }
    virtual ~Mammal() {cnt--;}
    virtual void print() {
        cout << "Mammal - Color : " << color << ", Weight : " << weight << '\n';
    }
    static int getCount() {
        return cnt;
    }           
};
int Mammal::cnt = 0;
//dog
class Dog : public Mammal {
public:
    Dog(const string& c, double w) : Mammal(c, w) {}
    ~Dog() {
        cout << "Dog destructor called\n";
    }
    void print() override {
        cout << "Dog - Color : " << color << ", Weight : " << weight << '\n';
    }
};
//cat
class Cat : public Mammal {
public:
    Cat(const string& c, double w) : Mammal(c, w) {}
    ~Cat() {
        cout << "Cat destructor called\n";
    }
    void print() override {
        cout << "Cat - Color : " << color << ", Weight : " << weight << '\n';
    }
};
int main() {
    //exper1
    Sphere s(5);
    Cylinder c(3, 4);
    Cone co(4, 5);

    s.output();
    c.output();
    co.output();
    //exper2
    Mammal* m1 = new Dog("Brown", 10);
    Mammal* m2 = new Cat("White", 3);
    cout << "Dog count : " << Dog::getCount() << '\n';
    cout << "Cat count : " << Cat::getCount() << '\n';
    m1->print();
    m2->print();
    delete m1;
    delete m2;
    
    cout << "Dog count after delete: " << Dog:: getCount() << '\n';
    cout << "Cat count after delete: " << Cat::getCount() << '\n';
    cout << "Main function ends\n";
}
