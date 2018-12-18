#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class College_Person {
    private:
        string Name;
        string Address;
        string CollegeID;
    public:
        void getData();
        void ShowData();
        void checkID_Validation();
        virtual void checkAge()=0;
        void checkingInput();
        College_Person();
};

class Student:public College_Person {
    private:
        int age;
        string branch;
        int num_of_Subjects=0;
        float* marks= new float[num_of_Subjects];
        float percentage;
    public:
        void getStudentData();
        void ShowStudentData();
        void checkAge();
        void checkBranch();
        void CheckMarks(int);
        Student();
};

class Faculty:public College_Person {
    private:
        int age;
        string teachingSubj;
        int TotalNumberOfClasses;
        string* teachingClasses=new string[TotalNumberOfClasses];

    public:
        void getFacultyData();
        void ShowFacultyData();
        void checkAge();
        void checker_TeachingSub();
        void checking_Classes(int);
        Faculty();
};

void College_Person::getData() {
    cout<<"Enter Name : ";
    getline(cin,Name);
    checkingInput();
    cout<<"Enter Address : ";
    getline(cin,Address);
    checkingInput();
    cout<<"Enter ID Number : ";
    getline(cin,CollegeID);
    checkID_Validation();
}

void College_Person::ShowData() {
    cout<<"\nName : "<<Name;
    cout<<"\nAddress : "<<Address;
    cout<<"\nID Number : "<<CollegeID;
}

void Student::getStudentData() {
    getData();
    cout<<"Enter Age : ";
    cin>>age;
    checkAge();
    cin.ignore();
    percentage=0;
    cout<<"Enter Branch : ";
    getline(cin,branch);
    checkBranch();
    cout<<"Enter Total number of Subjects : ";
    cin>>num_of_Subjects;
    for(int i=0;i<num_of_Subjects;i++) {
        cout<<"Enter Marks in Subject "<<i+1<<" : ";
        cin>>(*(marks+i));
        CheckMarks(i);
        percentage=percentage+(*(marks+i));
    }
    cin.ignore();
    percentage=percentage/num_of_Subjects;
}

void Student::ShowStudentData() {
    ShowData();
    cout<<"\nAge : "<<age;
    cout<<"\nBranch : "<<branch;
    if(num_of_Subjects>0) {
        cout<<"\nMarks in Subject ";
        for(int i=1;i<num_of_Subjects-1;i++){
            cout<<i<<" ,";
        }
        cout<<num_of_Subjects-1<<" & "<<num_of_Subjects<<" respectively are : ";
        for(int i=0;i<(num_of_Subjects-1);i++) {
            cout<<(*(marks+i))<<" , ";
        }
        cout<<(*(marks+num_of_Subjects-1))<<".\n";
    }
    else {
        cout<<"\nTotal Number Of Subjects : "<<num_of_Subjects<<endl;
    }
    cout<<"Percentage : "<<percentage<<endl;
}

void Faculty::getFacultyData() {
    getData();
    cout<<"Enter Age : ";
    cin>>age;
    checkAge();
    cin.ignore();
    cout<<"Enter Teaching Subject : ";
    getline(cin,teachingSubj);
    checker_TeachingSub();
    cout<<"Total classes faculty teaches : ";
    cin>>TotalNumberOfClasses;
    cin.ignore();
    for(int i=0;i<TotalNumberOfClasses;i++) {
        cout<<"Enter the Class "<<i+1<<" Faculty teaches : ";
        getline(cin,(*(teachingClasses+i)));
        checking_Classes(i);
    }
}

void Faculty::ShowFacultyData() {
    ShowData();
    cout<<"\nAge : "<<age;
    cout<<"\nTeaching Subject : "<<teachingSubj;
    cout<<"\nTotal classes Faculty teaches : "<<TotalNumberOfClasses;
    cout<<"\nTeaching Classes respectively are : ";
    for(int i=0;i<TotalNumberOfClasses-1;i++) {
        cout<<(*(teachingClasses+i))<<" , ";
    }
    cout<<(*(teachingClasses+TotalNumberOfClasses-1))<<".\n";
}

void College_Person::checkID_Validation() {
    if((CollegeID.size())!=11) {
        cout<<setw(20)<<" Not a valid ID! \n";
        cout<<"Enter College ID again : ";
        getline(cin,CollegeID);
        checkID_Validation();                              //Recursion
    }
}

void Student::checkAge() {
    if(age>22 || age<17) {
        cout<<setw(20)<<"Not a valid age \n";
        cout<<"Enter Correct Age : ";
        cin>>age;
        checkAge();                                         //Recursion
    }
}
void Faculty::checkAge() {
    if(age>65 || age<24) {
        cout<<setw(20)<<"Not a valid age \n";
        cout<<"Enter Correct Age : ";
        cin>>age;
        checkAge();                                         //Recursion
    }
}

College_Person::College_Person() {
    Name="Not Entered";
    Address="Not Entered";
    CollegeID="NULL";
}

Student::Student() {
    age=0;
    branch="NULL";
    for(int i=0;i<num_of_Subjects;i++) {
        (*(marks+i))=0;
    }
    percentage=0;
}

Faculty::Faculty() {
    age=0;
    teachingSubj="NULL";
    for(int i=0;i<4;i++) {
        teachingClasses[i]="NULL";
    }
}

void College_Person::checkingInput() {
    if(Name==" " || Address==" " || Name=="" || Address=="") {
        cout<<"Can't be left unfilled. Pls enter it again : ";
        if(Name==" " || Name=="") {
            getline(cin,Name);
            checkingInput();
        }
        else if (Address==" " || Address=="") {
            getline(cin,Address);
            checkingInput();
        }
    }
}

void Student::checkBranch() {
    if(branch=="" || branch==" " || branch=="  ") {
        cout<<"Branch can't be left unfilled. Pls enter correct branch again : ";
        getline(cin,branch);
        checkBranch();
    }
}

void Student::CheckMarks(int a) {
    if((*(marks+a))>100) {
        cout<<"Marks can't be greater than 100. Pls enter correct Mark for subject "<<a+1<<" again : ";
        cin>>(*(marks+a));
        CheckMarks(a);
    }
    else if((*(marks+a))<0) {
        cout<<"Marks can't be negative. Pls enter correct Mark for subject "<<a+1<<" again : ";
        cin>>(*(marks+a));
        CheckMarks(a);
    }
}

void Faculty::checker_TeachingSub() {
    if(teachingSubj==" " || teachingSubj=="" ) {
        cout<<"Teaching Subject of Faculty can't be left unfilled. Pls enter it again : ";
        getline(cin,teachingSubj);
        checker_TeachingSub();
    }
}

void Faculty::checking_Classes(int a) {
    if((*(teachingClasses+a))=="" || (*(teachingClasses+a))==" "){
        cout<<"Teaching class "<<a+1<<" can't be left unfilled. Pls enter it again : ";
        getline(cin,(*(teachingClasses+a)));
        checking_Classes(a);
    }
}


int main()
{
    system("cls");
    string abc;
    cout<<"\"Student\" or \"Faculty\" or \"Both\"? ";
    jump:
    getline(cin,abc);
    system("cls");
    if(abc=="Student" || abc=="student" || abc=="STUDENT") {
        int a;
        cout<<"For How many Students you want to feed the data : ";
        cin>>a;
        cin.ignore();
        system("cls");
        Student B[a];
        for(int i=0;i<a;i++) {
            cout<<"Enter Details of Student "<<i+1<<" :-\n";
            B[i].getStudentData();
            system("cls");
        }
        for(int i=0;i<a;i++) {
            cout<<"Details of Student "<<i+1<<" are as following :-";
            B[i].ShowStudentData();
            cout<<endl;
        }
    }
    else if(abc=="Faculty" || abc=="faculty" || abc=="FACULTY") {
        int a;
        cout<<"For How many Faculties you want to feed the data : ";
        cin>>a;
        cin.ignore();
        system("cls");
        Faculty B[a];
        for(int i=0;i<a;i++) {
            cout<<"Enter Details of Faculty "<<i+1<<" :-\n";
            B[i].getFacultyData();
            system("cls");
        }
        for(int i=0;i<a;i++) {
            cout<<"Details of Faculty "<<i+1<<" are as following :-";
            B[i].ShowFacultyData();
            cout<<endl;
        }
    }
    else if(abc=="Both" || abc=="both" || abc=="BOTH") {
        int a,b;
        cout<<"For How many Students you want to feed the data : ";
        cin>>a;
        cin.ignore();
        cout<<"For How many Faculties you want to feed the data : ";
        cin>>b;
        cin.ignore();
        system("cls");
        Student B[a];
        for(int i=0;i<a;i++) {
            cout<<"Enter Details of Student "<<i+1<<" :-\n";
            B[i].getStudentData();
            system("cls");
        }
        Faculty C[b];
        for(int i=0;i<b;i++) {
            cout<<"Enter Details of Faculty "<<i+1<<" :-\n";
            C[i].getFacultyData();
            system("cls");
        }
        for(int i=0;i<a;i++) {
            cout<<"Details of Student "<<i+1<<" are as following :-";
            B[i].ShowStudentData();
            cout<<endl;
        }
        for(int i=0;i<b;i++) {
            cout<<"Details of Faculty "<<i+1<<" are as following :-";
            C[i].ShowFacultyData();
            cout<<endl;
        }
    }
    else {
        cout<<"We does not verify your input ! Either Enter \"Student\" or \"Faculty\" or \"Both\" : ";
        goto jump;
    }
    cout<<endl;
    system("pause");
    return 0;
}
