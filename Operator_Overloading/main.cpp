#include <iostream>

using namespace std;

class Student {
    private:
        int a;

    public:
        Student();
        Student(int);
        void getData();
        void showData();
        Student operator+(Student);
        Student operator++();               //PreIncrement
        Student operator++(int);            //PostIncrement

};
Student::Student() {
    a=0;
}
Student::Student(int b) {
    a=b;
}


void Student::getData() {
    cout<<"Enter A : ";
    cin>>a;
}

void Student::showData() {
    cout<<"\nA : "<<a;
}
Student Student::operator+(Student S) {
    Student temp;
    temp.a=a+S.a;
    return temp;
}
Student Student::operator++() {
    Student temp;
    temp.a=++a;
    return temp;
}
Student Student::operator++(int) {
    a++;
    return *this;
}



int main()
{
    Student S1,S2,S3,S4;
    S1.getData();
    S2.getData();
    S4.getData();
    S3=S1+S2;
    ++S4;
    Student S6,S5;
    S6=S4++;
    S5=++S4;
    S6=S1;
    Student S7(29);
    S1.showData();
    S2.showData();
    S3.showData();
    S4.showData();
    S5.showData();
    S6.showData();
    S7.showData();
    return 0;
}
