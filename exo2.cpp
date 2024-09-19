// Your First C++ Program

#include <iostream>
#include <cmath>
#include <math.h>

#define _USE_MATH_DEFINES

using namespace std;
//


int main() {

    double H,V,ang,T,X,Y=0;
    double g=9.8;

    cout << "enter the coefficient of height (meter)" <<endl;
    cin >> H;
    cout << "enter the coefficient of celerity (v/s)" <<endl;
    cin >> V;
    cout << "enter the coefficient of angle in degree (°)" <<endl;
    cin >> ang; 
    T=(V*sin(ang*M_PI/180.0)/g)*(1+sqrt(1+((2*g*H)/V*V*pow(sin(ang*M_PI/180.0),2))));
    
    //calcul de la valeur de X

    X= V*T*cos(ang*M_PI/180.0);

    //calcul de la valeur de Y

    Y= H + (V*T*sin(ang*M_PI/180.0))-(0.5*g*pow(T,2));
    

    cout << "the result of position and time in format: [(X(t),Y(t),t)] ==> [( "<< X <<"m, "<< Y <<"m, "<< T <<"s )]" <<endl;



    //while(1){
        
   // }
    return 0;
}