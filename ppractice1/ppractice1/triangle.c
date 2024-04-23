#include "triangle.h"
#include <stdio.h>
#include <math.h>

double distance(coord* p1, coord* p2) {
    return sqrt((p2->x - p1->x) * (p2->x - p1->x) + (p2->y - p1->y) * (p2->y - p1->y));
}

double area(Triangle* T)
{
    double a = distance(&(T->A), &(T->B));
    double b = distance(&(T->B), &(T->C));
    double c = distance(&(T->A), &(T->C));
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double perimeter(Triangle* T)
{
    double a = distance(&(T->A), &(T->B));
    double b = distance(&(T->B), &(T->C));
    double c = distance(&(T->A), &(T->C));
    return a + b + c;
}

void high(Triangle* T, double *h1, double *h2, double *h3)
{
    double ar = area(T);
    *h1 = 2.0 * ar / distance(&(T->A), &(T->B));
    *h2 = 2.0 * ar / distance(&(T->B), &(T->C));
    *h3 = 2.0 * ar / distance(&(T->A), &(T->C));
    return h1, h2, h3;
}

TriangleType type(Triangle* T)
{
    double a = distance(&(T->A), &(T->B));
    double b = distance(&(T->B), &(T->C));
    double c = distance(&(T->A), &(T->C));
    if (a == b && b == c) {
        return isosceles;
    }
    if (a == b || b == c || a == c) {
        return equilateral;
    }
    return general;
}

Triangle read(char* filename) 
{
    Triangle T;
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("FILE NOT FOUND");
        exit(1);
    }
    else {
        fscanf(f, "%lf %lf %lf %lf %lf %lf", &T.A.x, &T.A.y, &T.B.x, &T.B.y, &T.C.x, &T.C.y);
        fclose(f);
    }
    return T;
}

void write(const char* filename, double ar, double per,
           double h1, double h2, double h3, TriangleType t)
{
    FILE* f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("File not found");
        return;
    }
    fprintf(f, "area: %.3lf\n", ar);
    fprintf(f, "perimeter: %.3lf\n", per); 
    fprintf(f, "highs: %.3lf %.3lf %.3lf\n", h1, h2, h3);
    fprintf(f, "Triangle Type: ");
    if (t == 0) { fprintf(f, "isosceles"); }
    if (t == 1) { fprintf(f, "equilateral"); }
    if (t == 2) { fprintf(f, "general"); }
    fclose(f);
}
// что делать с  функцией write??? просто оставит как есть???
