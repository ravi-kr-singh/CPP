#include <iostream>

using namespace std;

template <class X,class Y> X bigger(X a,Y b) {
    if(a>b)
        return a;
    else
        return b;
}

int main()
{   float x=3.01;
    system("cls");
    cout<<bigger(4,5);          //5
    cout<<endl<<bigger(5.6,4); //5.6
    cout<<endl<<bigger(4,5.6); //5
    cout<<endl<<bigger(1.2,3); //3.0
    cout<<endl<<bigger(3,1.2); //3
    cout<<endl<<x;
    return 0;
}
