#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Book {
    int BookID;
    string Book_Name;
    float Price;

};
Book input() {
    Book b;
    cout<<"Enter Book ID : ";
    cin>>b.BookID;
    cin.ignore();
    cout<<"Enter Book Name : ";
    getline(cin,b.Book_Name);
    cout<<"Enter Price : ";
    cin>>b.Price;
    cin.ignore();
    return b;

}
void output(Book b) {
    cout<<"\nBook ID : "<<b.BookID;
    cout<<"\nBook Name : "<<b.Book_Name;
    cout<<"\nBook Price : "<<b.Price;

}
int main()
{
    system("cls");
    Book B1;
    B1=input();
    output(B1);
    system("pause");
    return 0;
}
