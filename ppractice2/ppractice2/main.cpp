#include <iostream>
#include <fstream>
#include "triangle.h"
using namespace std; 

int main() {
    ifstream in_file("coord.txt");
    if (!in_file.is_open())
    {
        throw "Can't open file";
    }    
    Triangle t;
    in_file >> t;
    ofstream out_file("result.txt");
    out_file << t;
    return 0;
}
