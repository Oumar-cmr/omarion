// Your First C++ Program

#include <iostream>
#include <cmath>
#include <math.h>


#define _USE_MATH_DEFINES

using namespace std;

int main() {

    double A,w,fo,T,X=0;
    int k=0;

    cout << "enter the coefficient A" <<endl;
    cin >> A;
    cout << "enter the coefficient w" <<endl;
    cin >> w;
    cout << "enter the coefficient k" <<endl;
    cin >> k;
    //cout << "A est de valeur " << A;
    fo=asin(1.0/k)*(180.0/M_PI); //affectation values of fo, and *180/3.1415 because to work in degree
    //fo=asin(0.23)*180/3.1415;
    //fo=1.0/k;
    T=((M_PI/2.0)-fo)/w;
    //T=M_PI;

    X= A*sin(((w*T)+fo)*M_PI/180.0); //result of X(T) , *m_pi to convert angle in radians

    cout << "the result of X("<< T <<")= " << A <<".sin[(" << T << ") x ("<< w <<") + ("<< fo <<")] est  '" << X <<"'" <<endl;



    //while(1){
        
   // }
    return 0;
}