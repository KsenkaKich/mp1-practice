#include "triangle.h"
#include <stdio.h>
#include <math.h>
int main() 
{
    coord A, B, C;
    const char* filename = "C:\\Users\\Ксения\\Downloads\\ppractice1\\coord.txt";

    read(filename, &A, &B, &C);
    
    allocate(&A, A.x, A.y);
    allocate(&B, B.x, B.y);
    allocate(&C, C.x, C.y);

    double ar  = area(&A, &B, &C);
    printf("ar = %f\n", ar);

    double per = perimeter(&A, &B, &C);
    printf("per = %f\n", per);

    high(&A, &B, &C);
    type(&A, &B, &C);
    write("result.txt", &ar, &per);
    return 0;
}