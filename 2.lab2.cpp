#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, opt;
    int n1,n2,k3,n3,a3,max,min,sum,n4,a4,n5,a5,p,n6,m;
    k3=0;
    char cont;
    do{
        // print the menu of options
        cout << "\nSelect an option from [1-8] according to the menu:" <<endl;
        cout << "[1]. Enter a number in the range between 1000 and 999999999"<<endl;
        cout << "[2]. Print the digits of the number"<<endl;
        cout << "[3]. Count how many digits the number has"<<endl;
        cout << "[4]. Return the lowest and highest digits of the number"<<endl;
        cout << "[5]. Return the sum of the digits of the number"<<endl;
        cout << "[6]. Return the product of the odd digits"<<endl;
        cout << "[7]. Calculate the inverted version of the number"<<endl;
        cout << "---------------------------------------------------"<<endl;
        cout << "Enter option: ";
        cin>> opt;
        switch(opt){
            case 1: // OPTION 01: Enter the number
                // write the code here
                cout<<"Enter a number in the range between 1000 and 999999999"<<endl;
                cin>>n;
                while (n<1000 or n>999999999){
                    cout<<"Enter a number in the range between 1000 and 999999999"<<endl;
                    cin>>n;
                }
                break;
            case 2: // OPTION 02: Check if the number has repeated digits
                n1=n;
                while(n1!=0){
                    cout<<n1%10<<" ";
                    n1=n1/10;
                }
                break;
            case 3: // OPTION 03: Count how many digits the number has
                n2=n;
                while (n2!=0){
                    n2=n2/10;
                    k3++;
                }
                cout<<k3<<endl;
                break;
            case 4: // OPTION 04: Return the lowest and highest digits of the number
                n3=n;
                max=0;
                min=100000000;
                while(n3!=0){
                    a3=n3%10;
                    if (max<a3){
                        max=a3;
                    }
                    if (min>a3){
                        min=a3;
                    }
                    n3=n3/10;
                } 
                cout<<"The largest digit of number "<<max<<". The smallest digit of number "<<min<<endl;
                break;
            case 5: // OPTION 05: Return the sum of the digits of the number
                sum=0;
                n4=n;
                while(n4!=0){
                    a4=n4%10;
                    sum=sum+a4;
                    n4=n4/10;
                }
                cout<<"The sum of the digits of the number "<<sum<<endl;
                break;
            case 6: // OPTION 06: Return the product of the odd digits
                n5=n;
                p=1;
                while(n5!=0){
                    a5=n5%10;
                    if (a5%2!=0){
                        p=a5*p;
                    }
                    n5=n5/10;
                }
                cout<<"The product of the odd digits "<<p<<endl;
                break;
            case 7: // OPTION 07: Calculate the inverted version of the number
                n6=n;
                m=0;
                while (n6!=0){
                    m=m*10+n6%10;
                    n6=n6/10;
                }
                cout<<"The inverted version of the number "<<m<<endl;
                break;
            default:
                cout<<"Please,make sure that you have entered the value from 1 to 7"<<endl;
                break;
        }
        // Request to user continue or not
        cout << "\nDo you want continue [Y|N]? "<< endl;
        cin>> cont;
    }while(cont == 'y' || cont == 'Y');
    cout << "\n The program is over!"<< endl;
    return 0;
}