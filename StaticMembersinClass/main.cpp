#include <iostream>
#include <stdlib.h>
using namespace std;

class Book {
    private:
        static int Book_Section;
        int BookID;
    public:
        void getData();
        static void GetSection();
};

void Book::getData() {
    cout<<"Enter BookID : ";
    cin>>BookID;
}

void Book::GetSection() {
    cout<<"\nEnter Section number : ";
    cin>>Book_Section;
    cout<<"Book Section entered is "<<Book_Section<<".";
}

int Book::Book_Section;
int main()
{
    system("cls");
    Book B;
    B.getData();
    Book::GetSection();
//    Book::Book_Section=8; //Agar public hota toh aise access ho jata Book_Section

    return 0;
}
