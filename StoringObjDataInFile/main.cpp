#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
int i;

class Book {
 public:
     string bName;
     int Book_ID;
     string Book_Author;
     float Book_Price;
     Book();
     void getData();
     void displayData();
     void StoreDataInFile();
     void ReadingRecordsfromFile();


};
Book::Book() {

    bName ="No name Entered";
    Book_ID=0;
    Book_Author ="Not Known";
    Book_Price=0;
}

void Book::getData() {

    cout<<setw(20)<<"Enter Book Name"<<": ";
    getline(cin,bName);
    cout<<setw(20)<<"Enter Book's Author"<<": ";
    getline(cin,Book_Author);
    cout<<setw(20)<<"Enter Book ID"<<": ";
    cin>>Book_ID;
    cin.ignore();
    cout<<setw(20)<<"Enter Book Price"<<": ";
    cin>>Book_Price;
    cin.ignore();
}

void Book::displayData() {
    cout<<"\n"<<setw(32)<<"Data Entered by User is :- \n";
    cout<<setw(20)<<"Book Name"<<": "<<bName<<endl;
    cout<<setw(20)<<"Book's Author"<<": "<<Book_Author<<endl;
    cout<<setw(20)<<"Book ID"<<": "<<Book_ID<<endl;
    cout<<setw(20)<<"Book Price"<<": "<<Book_Price<<endl;
}

void Book::StoreDataInFile() {
    ofstream Myfile11;
    Myfile11.open("Ravik.dat",ios::app);
    /*Myfile11<<setw(20)<<"Book Name"<<": "<<bName<<endl
            <<setw(20)<<"Book's Author"<<": "<<Book_Author<<endl
            <<setw(20)<<"Book's ID"<<": "<<Book_ID<<endl
            <<setw(20)<<"Book's Price"<<": "<<Book_Price<<endl;
    Myfile11<<endl;
    */

   /* if (i==0) {
            Myfile11<<setw(30)<<"Books Name"<<setw(30)<<"Author Name"<<setw(30)<<"Book ID"<<setw(30)<<"Price(in Rs)\n"<<endl;
    }
    Myfile11<<setw(30)<<bName<<setw(30)<<setw(30)<<Book_Author<<setw(30)<<Book_ID<<setw(30)<<Book_Price<<endl;
*/
    Myfile11.write((char*)this,sizeof(*this));




    Myfile11.close();
}

void Book::ReadingRecordsfromFile() {
    ifstream fread;
    fread.open("Ravik.dat",ios::in);
    while(!fread.eof()) {
        fread.read((char*)this,sizeof(*this));
        displayData();
        cout<<endl;
    }
    fread.close();

}


int main()
{
    Book B[3];
    int n;
    cout<<"For How many Books you want to enter details :";
    cin>>n;
    cout<<endl;
    cin.ignore();
    for(i=0;i<n;i++)
    {
       B[i].getData();
       B[i].StoreDataInFile();
       cout<<endl;

    }

    B[i].ReadingRecordsfromFile();



/*    cout<<endl;
   for(int i=0;i<3;i++)
    {
       B[i].displayData();
       cout<<endl;
    }
   */

    return 0;
}
