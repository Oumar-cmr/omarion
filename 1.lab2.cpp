#include <iostream>
using namespace std;
int main(){
    int A,B;
    int sa,sb,ka,kb,m;
    int pb,pa;
    sa=0;
    sb=0;
    ka=0;
    kb=0;
    pa=1;
    pb=0;
    int a1,b1,a4,b4;
    cout<<"Enter two nambers (A and B) belonging to the range [10, 1000]"<<endl;
    cin>>A>>B;
    for (a1=1;a1<=A;a1++){
        if (A%a1==0){
            if (a1%2!=0){
                pa=pa*a1;
            }
            sa=a1+sa;
            ka++;
        }
    }
    for (b1=1;b1<=B;b1++){
        if (B%b1==0){
            if (b1%2==0){
                pb=pb+b1;
            }
            sb=b1+sb;
            kb++;
        }
    }
    cout<<"The sum of the divisors of A and B = "<<sb+sa<<endl;
    cout<<"The poduct of the number of divisors of numbers A and B = "<<ka*kb<<endl;
    cout<<"The sum of the products of the odd divisors of A and the even divisors of B = "<<pa+pb<<endl;
    for (a4=1;a4<=A;a4++){
        if (A%a4==0){
            for (b4=1;b4<=B;b4++){
                if (B%b4==0){
                    if (a4==b4){
                        m=a4;
                    }
                }
            }
        }
    }
    if (m==1){
        cout<<"The numbers are simple together"<<endl;
    } else{
        cout<<"The greatest common divisors of A and B = "<<m<<endl;
    }
    return 0;
}