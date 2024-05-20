#pragma once

#include <iostream>
#include <fstream>
using namespace std;

enum TriangleType {
    isosceles = 0,
    equilateral = 1,
    general = 2
};

class coord {
public:
    double x;
    double y;

    coord() { };
    coord(double _x, double _y) : x(_x), y(_y) {};
};

class Triangle {
private:
    coord A;
    coord B;
    coord C;

    double distance(coord p1, coord p2) const{
        return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    }
public:
    friend ifstream& operator >> (ifstream& in, Triangle& t) {
        in >> t.A.x >> t.A.y >> t.B.x >> t.B.y >> t.C.x >> t.C.y;
        return in;
    }
    Triangle() { }
    Triangle(coord _A, coord _B, coord _C) : A(_A), B(_B), C(_C) {
        double a = distance(A, B);
        double b = distance(B, C);
        double c = distance(A, C);
        if ((a + b <= c) || (b + c <= a) || (c + a <= b)) {
            throw invalid_argument("It's not a triangle");
        }
    } // 1. check existence I have a problem here
    double area() const;
    double perimeter() const;
    void high(double& h1, double& h2, double& h3) const;
    TriangleType type() const;
    
    friend ofstream& operator << (ofstream & file,const Triangle& t)
    {
        double h1, h2, h3;
        t.high(h1, h2, h3);
        file << "Area: " << t.area() << endl;
        file << "Perimeter: " << t.perimeter() << endl;
        file << "Heights: " << endl;
        file << "h1 = " << h1 << endl;
        file << "h2 = " << h2 << endl;
        file << "h3 = " << h3 << endl;
        file << "Type: ";
        if (t.type() == 0) {
            file << "isosceles" << endl;
        }
        if (t.type() == 1) {
            file << "equilateral" << endl;
        }
        if (t.type() == 2) {
            file << "general" << endl;
        }
        return file;
    } 
};
