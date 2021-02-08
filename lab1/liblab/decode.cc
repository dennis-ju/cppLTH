#include <fstream>
#include <iostream>
#include "coding.h"
#include <string>

int main() {
    std::cout << "Input file:\n";
    std::string infile;
    std::cin >> infile;

    std::ifstream f1(infile);
    std::ofstream f2("decoded_output");
    char c;
    while(f1.get(c)) {
        f2 << decode(c);
    }
    f1.close();
    f2.close();

}