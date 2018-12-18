#include <iostream>
#include <stdlib.h>
using namespace std;
class Random1 {
    public:
        void f1() {
            cout<<"f1\n";
        }
        virtual void f2() {
            cout<<"f2\n";
        }
        virtual void f3() {
            cout<<"f3\n";
        }
        virtual void f4() {
            cout<<"f4\n";
        }
        virtual void f5() {
            cout<<"f5\n";
        }
        virtual void f6() {
            cout<<"f6\n";
        }
        void f7() {
            cout<<"f7\n";
        }
        void f2 (int x) {
            cout<<x<<" f2\n";
        }
};

class Random2:public Random1{
    public:
        void f1() {
            cout<<"2f1\n";
        }
        void f2() {
            cout<<"2f2\n";
        }
        void f3() {
            cout<<"2f3\n";
        }
        void f4() {
            cout<<"2f4\n";
        }
        void f5() {
            cout<<"2f5\n";
        }
        void f6() {
            cout<<"2f6\n";
        }
        void f7(int x) {
            cout<<x<<" 2f7\n";
        }
        void f2 (int x) {
            cout<<x<<" 2f2\n";
        }
};


int main()
{
    system("cls");
    Random1 *p,Obj1;
    p=&Obj1;
    p->f1();                    //EB  RANDOM1---f1()
    p->f2();                    //LB  RANDOM1---f2()
    p->f3();                    //LB  RANDOM1---f3()
    p->f4();                    //LB  RANDOM1---f4()
    p->f5();                    //LB  RANDOM1---f5()
    p->f6();                    //LB  RANDOM1---f6()
    p->f7();                    //EB  RANDOM1---f7()
 //   p->f7(16);                  //EB  ERROR
    p->f2(15);                  //EB  RANDOM1---f2(int x)
    cout<<endl<<endl<<endl;
    Random2 Obj2;
    p=&Obj2;
    p->f1();                    //EB   RANDOM1---f1()
    p->f2();                    //LB   RANDOM2---f2()
    p->f3();                    //LB   RANDOM2---f3()
    p->f4();                    //LB   RANDOM2---f4()
    p->f5();                    //LB   RANDOM2---f5()
    p->f6();                    //LB   RANDOM2---f6()
    p->f7();                    //EB   RANDOM1---f7()
  //  p->f7(16);                  //EB   ERROR
    p->f2(15);                  //EB   RANDOM1---f2()
    return 0;
}
