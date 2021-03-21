#include <iostream>
#include "Element.h"
using namespace std;

class Polinom
{
    Element* prim;
    Element* ultim;
    int length;
    int initialLength;
public:
    Polinom(int);
    Polinom(const Polinom&);
    void addElement(int, int, int );
    void removeElement(int);
    int gradPolinom();
    int getValue(int);

    Element& operator[](int);
    Polinom& operator+(const Polinom&);
    Polinom& operator*(const Polinom&);
    Polinom& operator*(int);
    friend ostream& operator<<(ostream& out,const Polinom& pol);
    friend istream& operator>>(istream& ,Polinom&);


};
