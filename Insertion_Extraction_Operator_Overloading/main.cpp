#include <iostream>
#include <stdlib.h>
using namespace std;

class Complex {
    private:
        int a,b;
    public:
        void getData() {
            cout<<"Enter Real part of Complex number : ";
            cin>>a;
            cout<<"Enter Imaginary part of Complex Number : ";
            cin>>b;
            cout<<endl;
        }
        void showData() {
            cout<<"\nComplex Number is "<<a<<"+i"<<b<<".";
        }
        friend istream& operator>>(istream&,Complex&);
        friend ostream& operator<<(ostream&,Complex);
};

istream& operator>>(istream& din,Complex& C) {
    C.getData();
    return din;
}
ostream& operator<<(ostream& dout,Complex C) {
    C.showData();
    return dout;
}
int main()
{
    system("cls");
    Complex C1,C2,C3;
    cin>>C1;
    cin>>C2>>C3;      //   operator>>(cin,C2)
    cout<<C1;
    cout<<C2<<C3;
    return 0;
}
