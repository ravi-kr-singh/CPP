#include <iostream>

using namespace std;
 class Random {
    int a,b;
    public:
        void setData(int a,int b) {
            this->a=a;
            this->b=b;
        }
        void showData() {
            cout<<a<<"  "<<b;
        }
 };

int main()
{
    Random R;
    Random* p=&R;
    p->setData(4,5);
    p->showData();
    return 0;
}
