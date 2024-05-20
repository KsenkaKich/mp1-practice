#include "triangle.h"

double Triangle::area() const
{
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(A, C);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
double Triangle::perimeter() const
{
    return distance(A, B) + distance(B, C) + distance(A, C);
}
void Triangle::high(double& h1, double& h2, double& h3) const
{
    double ar = area();
    h1 = 2.0 * ar / distance(A, B);
    h2 = 2.0 * ar / distance(B, C);
    h3 = 2.0 * ar / distance(A, C);
}
TriangleType Triangle::type() const
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
