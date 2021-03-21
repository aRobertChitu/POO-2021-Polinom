#include<iostream>
using namespace std;

class Element{
    int coeficient;
    int grad;
    int semn;
    Element* next;
    Element* prev;
public:
    Element();
    Element(int,int,int);

    int getCoeficient();
    int getGrad();
    int getSemn();

    void setCoeficient(int);
    void setGrad(int);
    void setSemn(int);

    void setNext(Element*);
    void setPrev(Element*);

    Element* getNext();
    Element* getPrev();

     friend ostream& operator<<(ostream& out,const Element& el);

};
