#include <iostream>
#include <stdlib.h>
using namespace std;

int Area(int l,int b) {
    return (l*b);
}
int Area (int s) {
    return (s*s);
}
float Area (float b,float h) {
    return (0.5*b*h);
}
float Area (float r) {
    return (3.14*r*r);
}


int main()
{   system("cls");
    int length,breadth,rectangle_area,side,square_area;
    float radius,circle_area,base,height,triangle_area;
    cout<<"Enter radius for circle : ";
    cin>>radius;
    circle_area=Area(radius);
    cout<<"Circle's Area : "<<circle_area<<".\n"<<endl;
    cout<<"Enter length of rectangle : ";
    cin>>length;
    cout<<"Enter Breadth of rectangle : ";
    cin>>breadth;
    rectangle_area=Area(length,breadth);
    cout<<"Rectangle's Area : "<<rectangle_area<<".\n"<<endl;
    cout<<"Enter Side of square : ";
    cin>>side;
    square_area=Area(side);
    cout<<"Squares's Area : "<<square_area<<".\n"<<endl;
    cout<<"Enter Base of triangle : ";
    cin>>base;
    cout<<"Enter Height of triangle : ";
    cin>>height;
    triangle_area=Area(base,height);
    cout<<"Triangle's Area : "<<triangle_area<<".\n"<<endl;
    system("pause");
    return 0;

}
