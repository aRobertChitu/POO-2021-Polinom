#include<iostream>
#include"Element.h"
using namespace std;

Element::Element(){ //constructor fara parametrii
    this->coeficient = 0;
    this->grad = 0;
    this->semn = false;
    this->next = NULL;
    this->prev = NULL;
}

Element::Element(int grad, int coeficient, int semn){ //constructor cu parametrii
    this->coeficient = coeficient;
    this->grad = grad;
    this->semn = semn;
    this->next = NULL;
    this->prev = NULL;
}


void Element::setCoeficient(int coeficient){ // setteri si getteri
    this->coeficient = coeficient;
}

void Element::setGrad(int grad){
    this->grad = grad;
}

void Element::setSemn(int semn){
    this->semn = semn;
}

int Element::getCoeficient(){
    return coeficient;
}

int Element::getGrad(){
    return grad;
}

int Element::getSemn(){
    return semn;
}

void Element::setNext(Element* next){
    this->next = next;
}

void Element::setPrev(Element* prev){
    this->prev = prev;
}

Element* Element::getNext(){
    return next;
}

Element* Element::getPrev(){
    return prev;
}

ostream& operator<<(ostream& out, const Element& el){ // supraincare operator pentru afisare element
    out<<((el.semn==1)?"+":"-")<<el.coeficient<<"X^"<<el.grad<<" ";
}
