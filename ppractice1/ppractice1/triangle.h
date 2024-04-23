#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdlib.h>

typedef struct {
    double x;
    double y;
}coord;

typedef struct
{
    coord A;
    coord B;
    coord C;
} Triangle;

typedef enum {
    isosceles = 0,
    equilateral = 1,
    general = 2
} TriangleType;                                                          

double distance(coord* p1, coord* p2); 
double area(Triangle* T); 
double perimeter(Triangle* T); 
void high(Triangle* T, double* h1, double* h2, double* h3);
TriangleType type(Triangle* T); 
Triangle read(char* filename);
void write(const char* filename, double ar, double per,
           double h1, double h2, double h3, TriangleType t);
#endif// !TRIANGLE_H