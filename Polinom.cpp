#include<iostream>
#include<math.h>
#include"Polinom.h"
using namespace std;

int coeficient(Element el1,Element el2){ // calcul suma coeficient
    int suma=0;
    if(el1.getSemn()==1){
        suma+=el1.getCoeficient();
    }else{
        suma-=el1.getCoeficient();
    }
    if(el2.getSemn()==1){
        suma+=el2.getCoeficient();
    }else{
        suma-=el2.getCoeficient();
    }
    return suma;
}

int prodCoeficient(Element el1,Element el2){ // calcul produs coeficient
    int prod=1;
    if(el1.getSemn()==1){
        prod*=el1.getCoeficient();
    }else{
        prod*=-el1.getCoeficient();
    }
    if(el2.getSemn()==1){
        prod*=el2.getCoeficient();
    }else{
        prod*=-el2.getCoeficient();
    }
    return prod;
}


Polinom::Polinom(int initialLength){ // constructor pentru polinom cu lungime intiala  reprezentand nr de termeni
    this->prim = NULL;
    this->ultim= NULL;
    this->length = 0;
    this->initialLength = initialLength;
}

Polinom::Polinom (const Polinom& pol){
    this->initialLength = pol.initialLength;
    this->prim = NULL;
    this->ultim = NULL;
    this->length = 0;
    Element *el = pol.prim;
    for(int i = 0; i < pol.length ; i++){
        this->addElement(el->getGrad(),el->getCoeficient(),el->getSemn());
        if(el->getNext());
            el = el->getNext();
    }
}

void Polinom::addElement(int grad, int coeficient, int semn) // functia pentru adaugare elemnet in polinom
{
   Element *el = new Element(grad,coeficient,semn);
   if(prim==NULL){
        prim = ultim = el;
        length++;
   }else if(prim == ultim){
        prim->setNext(el);
        el->setPrev(prim);
        ultim = el;
        length++;
   }else{
        ultim->setNext(el);
        el->setPrev(ultim);
        ultim = el;
        length++;
   }
}
void Polinom::removeElement(int grad){ // functia pentru scoatere element dintr-un polinom
    Element *el = prim;
    if (prim == NULL){
        throw out_of_range("Nu sunt elemente");
    }
    else if(prim == ultim){
        prim = ultim = NULL;
        delete el;
    }
    else if(prim->getGrad()==grad){

        el->getNext()->setPrev(NULL);
        prim = el->getNext();
        delete el;
        length--;
    }
    else if(ultim->getGrad()==grad){
        el = ultim;
        ultim= ultim->getPrev();
        ultim->setNext(NULL);
        delete el;

        length--;
    }
    for (int i=0 ; i< length; i++){
        if (el->getGrad() == grad){
            el->getPrev()->setNext(el->getNext());
            el->getNext()->setPrev(el->getPrev());
            delete el;
            length--;
            break;
        }
        el = el->getNext();
    }
}

int Polinom::gradPolinom(){ // functie pentru gasirea gradului polinomului

    Element *el = prim;
    int maxim = 0;
    for (int i=0; i<this->length; i++ ){
        if( el->getGrad() >maxim)
            maxim = el->getGrad();
        el = el ->getNext();
    }

 return maxim;
}

int Polinom::getValue(int x){   // calculul polinomului intr un punct oarecare
    Element *el = prim;
    int suma=0;

    for(int i=0 ; i < length; i++){
        suma += (el->getCoeficient() * pow(x,el->getGrad()))*el->getSemn();
        el = el->getNext();
    }
    return suma;
}

Element& Polinom::operator[](int grad){ // supraincarea operatorului []
    Element *el = this->prim;
    for(int i = 0; i < this->length ; i++){
        if(el->getGrad() == grad){
            return *el;
        }
        if (el->getNext())
            el = el->getNext();
    }
}



Polinom& Polinom::operator+(const Polinom &pol){ // supraincararea operatorului +
    Element *el1 = this->prim;
    Element *el2 = pol.prim;
    Element *el3 = this->prim;
    Element *elFin = new Element();
    Polinom *toReturn = new Polinom(1);
    bool found = false;
    bool secondElFound = false;
    for (int i = 0; i < this->length ; i++){ //algoritm folosit pentru a aduna doua polinoame

        for (int j = 0; j < pol.length; j++){
            if(el1->getGrad() == el2->getGrad()){
                elFin->setCoeficient(coeficient(*el1,*el2) );//(el1->getSemn()==1?el1->getCoeficient():-el1->getCoeficient() + el2->getSemn()==1?el2->getCoeficient():-el2->getCoeficient())>0?(el1->getSemn()==1?el1->getCoeficient():-el1->getCoeficient() + el2->getSemn()==1?el2->getCoeficient():-el2->getCoeficient()) : -(el1->getSemn()==1?el1->getCoeficient():-el1->getCoeficient() + el2->getSemn()==1?el2->getCoeficient():-el2->getCoeficient()) );
                elFin->setGrad(el1->getGrad());
                elFin->setSemn( (el1->getSemn()?el1->getCoeficient():-el1->getCoeficient() + el2->getSemn()?el2->getCoeficient():-el2->getCoeficient())>0 ? 1 : 0 );
                found = true;
            }

            if(i == this->length-1){
                for(int k = 0; k < this->length ; k++){
                    if(el2->getGrad() == el3->getGrad()){
                        secondElFound = true;
                    }
                    if(el3 ->getNext())
                            el3 = el3 ->getNext();
                }

                if(secondElFound == false)
                {
                    toReturn ->addElement(el2->getGrad(),el2->getCoeficient(),el2->getSemn());

                }
                secondElFound = false;
                el3 = pol.prim;
            }

            if(el2->getNext()){
                el2 = el2->getNext();
            }
        }
        if(found == false){
            elFin ->setCoeficient(el1->getCoeficient());
            elFin ->setGrad(el1->getGrad());
            elFin ->setSemn(el1->getSemn());
        }
        found = false;
        toReturn->addElement(elFin->getGrad(),elFin->getCoeficient(),elFin->getSemn());

        if(el1->getNext()){
                el1 = el1->getNext();
            }
    }

    return *toReturn;
}

Polinom& Polinom::operator*(const Polinom& pol){ // supraincararea operatorului * pentru inmultirea a 2 polinoame
    Element *el1 = this->prim;
    Element *el2 = pol.prim;
    Polinom *polinom = new Polinom(1);

    for(int i=0 ; i < this->length ; i++){
            el2 = pol.prim;
        for(int j = 0; j < pol.length; j++){
            polinom ->addElement( el1->getGrad()+el2->getGrad() , prodCoeficient(*el1,*el2), el1->getSemn()==el2->getSemn()?1:0);
            if(el2->getNext()){
                el2= el2->getNext();
            }
        }

        if(el1->getNext()){
                el1= el1->getNext();
            }
    }
    return *polinom;
}
Polinom& Polinom::operator*(int scalar){ //supraincarcarea operatorului * pentru inmultirea unui polinom cu un scalar;
    Element *el1 = this->prim;
    Polinom *polinom = new Polinom(1);
    for(int i=0; i < this->length ; i++){
        polinom ->addElement(el1->getGrad(), el1->getCoeficient()* scalar, ((scalar<0 && el1->getSemn()==1) || (scalar>0 && el1->getSemn()!=1))?0:1);
        if(el1->getNext()){
            el1 = el1->getNext();
        }
    }
    return *polinom;
}

ostream& operator<<(ostream& out, const Polinom& pol){ // supraincarcarea operatorului << pentru afisare
    Element *el = pol.prim;
    for(int i=0;i<pol.length;i++){
        out<<((el->getSemn()==1)?"+":"-")<<el->getCoeficient()<<"X^"<<el->getGrad()<<" ";
        el = el ->getNext();
    }
    out<<endl;
}

istream& operator>>(istream& in, Polinom &pol){ // supraincarcarea operatorului >> pentru citire
    int grad,coeficient,semn;
    for (int i = 0; i < pol.initialLength ; i++){
        in >> grad ;
        in >> coeficient;
        in >> semn;
        pol.addElement(grad,coeficient,semn);

    }
}
