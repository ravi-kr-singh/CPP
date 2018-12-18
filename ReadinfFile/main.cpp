#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream obj;
    obj.open("aarkay.dat");
    char ch;
    while(!obj.eof())
    {
        ch=obj.get();
        cout<<ch;
    }


    return 0;
}
