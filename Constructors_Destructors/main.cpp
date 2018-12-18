#include <iostream>
#include <stdlib.h>
using namespace std;

class check {
    private:
        int a,b;
    public:
        check() {
        cout<<"I am default Constructor ";
        a=0;
        b=0;
        }
        check(int q,int w) {
            a=q;
            b=w;
        }
        check (check& C) {
        a=C.a;
        b=C.b;
        }
        ~check () {
        cout<<"I am destructor , I releases memory. ";
        }

};
void fun() {
    check Q;
}

int main()
{
    system("cls");
    fun();
    check A;
    return 0;
}
