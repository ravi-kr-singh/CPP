#include<iostream>

using namespace std;

namespace RK_Space {
    int a;
    char ch;
    int f1();
    class Ravi{
    public:
    int c;
    void func();
    };
}
int RK_Space::f1() {
    cout<<"This function has been declared in the namespace:RK_Space";
    return 0;
}
void RK_Space::Ravi::func(){
    cout<<"Enjoy";
}

using namespace RK_Space;

int main()
{
    a=5;
    cout<<a;
    ch='a';
    cout<<"\n"<<ch<<"\n";
    f1();
    cout<<"\n";
    Ravi aarkay;
    aarkay.func();


    return 0;
}
