#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include <iostream>
using namespace std;

class Validation
{
public:
    Validation();
    string validateCard(string,bool);
    string validateISBN13(string);
    string validateISBN10(string);
    string validateUPC(string);
};

#endif // VALIDATION_H
