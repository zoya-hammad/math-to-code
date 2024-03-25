#ifndef MISSINGNUM_H
#define MISSINGNUM_H

#include <string>
#include <iostream>
using namespace std;

class MissingNum
{
public:
    MissingNum();
    string missingCard(string, bool);
    string missingISBN13(string);
    string missingISBN10(string);
    string missingUPC(string);
};

#endif // MISSINGNUM_H
