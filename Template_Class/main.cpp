#include <iostream>
#include <stdlib.h>
using namespace std;

template <class X> class My_Array {
    private:
        struct Arr_Worker {
            int capacity;
            X* arr_ptr;
        };
        Arr_Worker* s;

    public:
        My_Array (int capacity) {
            s=new Arr_Worker;
            s->capacity=capacity;
            s->arr_ptr=new X[s->capacity];
        }
        void Add_Element (int index,X data) {
            if(index>=0 && index<=((s->capacity)-1) ) {
                *((s->arr_ptr)+index)=data;
            }
            else {
                cout<<"Not a valid Index!";
            }
        }
        void View_Element (int index) {
            if(index>=0 && index<=((s->capacity)-1) ) {
                cout<<*((s->arr_ptr)+index);
            }
            else {
                cout<<"Not a valid Index!";
            }
        }
        void View_Whole_Array() {
            for (int i=0;i<(s->capacity);i++) {
                cout<<*((s->arr_ptr)+i)<<" ";
            }
        }
};


int main()
{
    system("cls");
    My_Array <string> Testing(3);
    Testing.Add_Element(0,"I am RK0");
    Testing.Add_Element(1,"I am RK1");
    Testing.Add_Element(2,"I am RK2");
    //Testing.View_Element(1);
    cout<<endl;
    Testing.View_Whole_Array();
    return 0;
}
