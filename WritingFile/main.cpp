#include <iostream>
#include <fstream>

using namespace std;

int main()
{
 ofstream obj1;
 obj1.open("FILE8.dat");
 obj1<<"Hello! AAr Kay here    ";
 obj1.close();

 return 0;
}
