#include <iostream>

using namespace std;
class fruit;
class Orange;

class Apple {
    private:
        int n;
    public:
        void getData() {
            cout<<"How Many Apples? ";
            cin>>n;
        }
        void ShowData() {
            cout<<"\nNumber of Apples : "<<n;
        }
        friend fruit operator+ (Apple,Orange);
};

class Orange {
    private:
        int n;
    public:
        void getData() {
            cout<<"How Many Oranges? ";
            cin>>n;
        }
        void ShowData() {
            cout<<"\nNumber of Oranges : "<<n;
        }
        friend fruit operator+ (Apple,Orange);

};
class fruit {
    private:
        int n;
    public:
        void getData() {
            cout<<"How Many Fruits? ";
            cin>>n;
        }
        void ShowData() {
            cout<<"\nNumber of Fruits : "<<n;
        }
        friend fruit operator+ (Apple,Orange);

};
fruit operator+ (Apple a,Orange o) {
    fruit temp;
    temp.n=a.n+o.n;
    return temp;
}

int main()
{
    Apple A1;
    A1.getData();
    Orange O1;
    O1.getData();
    fruit F1;
    F1=A1+O1;
    F1.ShowData();
}
