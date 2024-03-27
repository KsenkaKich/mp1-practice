#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <stdlib.h>
typedef struct {
    int x;
    int y;
}coord;

void allocate(coord* A,int x,int y);
float distance(coord* A, coord* B);
double area(coord* A, coord* B, coord* C);
double perimeter(coord* A, coord* B, coord* C);
char high(coord* A, coord* B, coord* C);
char type(coord* A, coord* B, coord* C);
void read(const char* filename, coord* A, coord* B, coord* C);
void write(const char* filename, double* ar, double* per);
#endif// !TRIANGLE_H