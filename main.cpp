#include <iostream>
#include "Polinom.h"
using namespace std;

int main()
{
    Polinom p1(2),p2(2);// parametrii reprezinta numarul de  termeni pe care ii are polinomul initial.



    cin>>p1; //citire polinoamnelor folosiung supraincarcarea de operator ( citirea se face sub forma a 3 numere pentru fiecare element, reprezentand gradul,coeficientul si semnul(1 pozitiv, 0 negativ)
             // exemplu: pentru datele de intrare  2 3 1  \n   1 2 0 polinomul va fi de forma  3 * x^2 - 2 *x ^1;
    cin>>p2; // citirea polinoamelor folosind supraincarcarea de operator
    // initial adaugam 4 elemente in total, cate 2 pentru fiecare polinom.
 //  p1.addElement(2, 3, 1); adaugarea unui element oarecare in polinom ( +3 * x^2) primul parametru reprezint puterea, al doilea coeficientul si al 3-lea semnul.



    cout<<"Polinom1: ";
    cout<<p1;  // supraincarcarea operatorului  "<<" pentru afisarea polinomului
    cout<<endl;
    cout<<"Polinom2: ";
    cout<<p2;
    cout<<endl;
    cout<<"Calcul valoare in punctul x(in cazul de fata1 este 1) pentru polinomul 1: ";
    cout<<p1.getValue(1); //calcul valoare intr-un punct
    cout<<endl;
    cout<<"Termenuld e grad i: ";
    cout<<p1[2]; // supraincarcarea operatorului [] pentru afisarea  termenului de grad i
    cout<<endl;
    cout<<"Adunare polinoame: "; //supraincarcare operator + pentru adunare
    cout<<p1+p2;
    cout<<endl;
    cout<<"Inmultire polinoame: "; // supraincarcareoperator * pentru inmultire
    cout<<p1*p2;
    cout<<endl;
    cout<<"Inmultire polinom cu scalar: "; // supraincarcare operator * pentru inmultire cu scalar
    cout<<p1*2;
    cout<<endl;
    cout<<"Scoatere element de grad i din polinom:"; // scoaterea elemntului de gradul ales
    p2.removeElement(2);cout<<p2;
    cout<<endl;
    cout<<"Afisare grad polinom:"; // afisarea gradului polinomului
    cout<<p1.gradPolinom();

    return 0;
}
