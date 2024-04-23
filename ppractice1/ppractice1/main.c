#include "triangle.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
    /*if (argc != 3) {
        printf("Exactly one argument expected, got %d\n ", argc); //почему у меня при запуске это выскакивает, я не вижу ошибок =(
        return 1;
    } */   
    Triangle T;
    double h1, h2, h3;
    TriangleType triangle_type;
    double ar, per;

    T = read(argv[1]);

    ar  = area(&T);
    per = perimeter(&T);
    high(&T, &h1, &h2, &h3);
    triangle_type = type(&T);

    write(argv[2], ar, per, h1, h2, h3, triangle_type);
    return 0;
}