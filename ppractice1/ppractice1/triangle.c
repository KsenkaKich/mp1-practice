#include "triangle.h"
#include <stdio.h>
#include <math.h>

double distance(coord* A, coord* B) {
    return sqrt((B->x - A->x) * (B->x - A->x) + (B->y - A->y) * (B->y - A->y));
}

double area(coord* A, coord* B, coord* C)
{
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(A, C);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double perimeter(coord* A, coord* B, coord* C)
{
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(A, C);
    return a + b + c;
}

void high(coord* A, coord* B, coord* C, double *h1, double *h2, double *h3)
{
    double ar = area(A, B, C);
    *h1 = 2.0 * ar / distance(A, B);
    *h2 = 2.0 * ar / distance(B, C);
    *h3 = 2.0 * ar / distance(A, C);
    return h1, h2, h3;
}

TriangleType type(coord* A, coord* B, coord* C)
{
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(A, C);
    if (a == b && b == c) {
        return isosceles;
    }
    if (a == b || b == c || a == c) {
        return equilateral;
    }
    return general;
}

void read(const char* filename, coord* A, coord* B, coord* C)
{
    int i = 0;
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("FILE NOT FOUND");
        exit(1);
    }
    if (fscanf(f, "%lf %lf", &A->x, &A->y) != 2) {
        printf("Error reading point A\n");
        return;
    }

    if (fscanf(f, "%lf %lf", &B->x, &B->y) != 2) {
        printf("Error reading point B\n");
        return;
    }

    if (fscanf(f, "%lf %lf", &C->x, &C->y) != 2) {
        printf("Error reading point C\n");
        return;
    }
    fclose(f);
}
//last point, everthing is right
void write(const char* filename, double* ar, double* per, double* h1, double* h2, double* h3, TriangleType* t)
{
    int i = 0;
    FILE* f = fopen(filename, "w+");
    if (f == NULL)
    {
        printf("File not found");
        return;
    }
    fprintf(f, "area: %.3lf\n", *ar);
    fprintf(f, "perimeter: %.3lf\n", *per); 
    fprintf(f, "highs: %.3lf %.3lf %.3lf\n", *h1,*h2,*h3);
    fprintf(f, "Triangle Type: ");
    if (*t == 0) { fprintf(f, "isosceles"); }
    if (*t == 1) { fprintf(f, "equilateral"); }
    if (*t == 2) { fprintf(f, "general"); }
    fclose(f);
}