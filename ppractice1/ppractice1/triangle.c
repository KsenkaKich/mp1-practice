#include "triangle.h"
#include <stdio.h>
#include <math.h>
void allocate(coord* A,int x,int y) 
{
    A->x = x;
    A->y = y;
}

float distance(coord* A, coord* B) {
    return sqrt(pow(B->x - A->x,2) + pow(B->y - A->y, 2)); 
}

double area(coord* A, coord* B, coord* C)
{
    float a = distance(A, B);
    float b = distance(B, C);
    float c = distance(A, C);
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double perimeter(coord* A, coord* B, coord* C)
{
    float a = distance(A, B);
    float b = distance(B, C);
    float c = distance(A, C);
    return a + b + c;
}

char high(coord* A, coord* B, coord* C)
{
    double ar = area(A, B, C);
    printf("H1 = %f\n ", (2 * ar) / distance(A, B));
    printf("H2 = %f\n", (2 * ar) / distance(B, C));
    printf("H3 = %f\n", (2 * ar) / distance(A, C));
}

char type(coord* A, coord* B, coord* C)
{
    float a = distance(A, B);
    float b = distance(B, C);
    float c = distance(A, C);
    if (a == b && b == c) {
        printf("Equilateral Triangle\n");
    }
    else if (a == b || b == c || a == c) {
        printf("Isosceles Triangle\n");
    }
    else {
        printf("Scalene Triangle\n");
    }
}

void read(const char* filename, coord* A, coord* B, coord* C)
{
    int i = 0;
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("FILE NOT FOUND");
        abort();
    }
    if (fscanf(f, "%d %d", &A->x, &A->y) != 2) {
        printf("Error reading point A\n");
        return;
    }

    if (fscanf(f, "%d %d", &B->x, &B->y) != 2) {
        printf("Error reading point B\n");
        return;
    }

    if (fscanf(f, "%d %d", &C->x, &C->y) != 2) {
        printf("Error reading point C\n");
        return;
    }

    fclose(f);
}

void write(const char* filename, double* ar,double* per)
{
    int i = 0;
    FILE* f = fopen(filename, "w+");
    if (f == NULL)
    {
        printf("File not found");
        abort();
    }
    fprintf(f, "area: %.3lf", *ar);
    fprintf(f, "perimeter: %.3lf", *per); //without high and type, I don't know what doing with them       
}