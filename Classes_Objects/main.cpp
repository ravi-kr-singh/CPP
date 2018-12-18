#include <iostream>
#include <stdlib.h>

using namespace std;

class Complex {
    private:
        int real;
        int img;
    public:
        void input();
        void display();
        Complex add(Complex);
};
void Complex::input() {
    cout<<"\nEnter Real Part of Complex Number : ";
    cin>>real;
    cout<<"Enter Imaginary Part of Complex Number : ";
    cin>>img;
}
void Complex::display() {
    cout<<"\nComplex Number : "<<real<<"+ i"<<img<<endl;
}
Complex Complex::add(Complex A) {
    Complex C;
    C.real=A.real+real;
    C.img=A.img+img;
    cout<<"\nAddition of "<<A.real<<"+ i"<<A.img<<" and "<<real<<"+ i"<<img<<" is "<<C.real<<"+ i"<<C.img<<".";
    return C;
}

int main()
{
    system("cls");
    Complex C1,C2,C3;
    C1.input();
    C1.display();
    C2.input();
    C2.display();
    C3=C2.add(C1);
    cout<<endl;
    system("pause");
    return 0;
}
