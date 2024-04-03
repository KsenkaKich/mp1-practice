#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdlib.h>

typedef struct {
    double x;
    double y;
}coord;

typedef enum {
    isosceles = 0,
    equilateral = 1,
    general = 2
} TriangleType;

double distance(coord* A, coord* B);
double area(coord* A, coord* B, coord* C);
double perimeter(coord* A, coord* B, coord* C);
void high(coord* A, coord* B, coord* C, double* h1, double* h2, double* h3);
TriangleType type(coord* A, coord* B, coord* C);
void read(const char* filename, coord* A, coord* B, coord* C);
void write(const char* filename, double* ar, double* per, double* h1, double* h2, double* h3, TriangleType* t);
#endif// !TRIANGLE_H