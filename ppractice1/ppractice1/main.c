#include "triangle.h"
#include <stdio.h>
#include <math.h>

int main() 
{
    coord A, B, C;
    const char* filename = "coord.txt";
    double h1, h2, h3;
    TriangleType triangle_type;

    read(filename, &A, &B, &C);
    
    double ar  = area(&A, &B, &C);

    double per = perimeter(&A, &B, &C);

    high(&A, &B, &C, &h1, &h2, &h3);
    triangle_type = type(&A, &B, &C);
    write("result.txt", &ar, &per,&h1,&h2,&h3,&triangle_type);
    return 0;
}