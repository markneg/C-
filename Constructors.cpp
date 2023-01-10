//Mark Negus
//Submitted 8/2/21
//Programming Assignment 13b

#include <iostream>
#include<string>
using namespace std;

class Student{
    
    public:
    Student();  // Constructor. Must have the same name as the class 
    
    int getSSN() const;
    int getStudID() const;
    string getLSTNM() const;
    string getFSTNM() const;
    
    private:
    int SSN; 
    int StudentID;
    string LastName;
    string FirstName;
};

int Student::getSSN() const     //Gets SSN
{
    return SSN; 
}

int Student::getStudID() const   //Gets student ID
{
    return StudentID; 
}

string Student::getLSTNM() const  // Gets last name
{
    return LastName;
}

string Student::getFSTNM() const  //Gets first name
{
    return FirstName;
}

Student::Student()     //Constructor
{
    SSN = 0;
    StudentID = 0;
    LastName = "";
    FirstName = "";
    
    cout<<"\nPlease update the current student info"<<endl;
    cout<<"\nSSN: "<<endl;
    cin>>SSN; 
    cout<<"\nStudent ID: "<<endl;
    cin>>StudentID;
    cout<<"\nFirst name: "<<endl;
    cin>>FirstName;
    cout<<"\nLast name: "<<endl;
    cin>>LastName;
}

int main()
{
    Student Mark;
    Student Gordon;

    cout<<"\n\n\n\nSSN: ";
    cout<<Mark.getSSN();
    cout<<"\nID: ";
    cout<<Mark.getStudID();
    cout<<"\nFirst name: ";
    cout<<Mark.getFSTNM();
    cout<<"\nLast name: ";
    cout<<Mark.getLSTNM();

       
    cout<<"\n\n\n\nSSN: ";
    cout<<Gordon.getSSN();
    cout<<"\nID: ";
    cout<<Gordon.getStudID();
    cout<<"\nFirst name: ";
    cout<<Gordon.getFSTNM();
    cout<<"\nLast name: ";
    cout<<Gordon.getLSTNM();

    
       return 0;
}
/*Output


Please update the current student info

SSN: 
1234

Student ID: 
1234678

First name: 
Mark

Last name: 
Negus

Please update the current student info

SSN: 
4321

Student ID: 
87654321

First name: 
Gordon

Last name: 
Negus






SSN: 1234
ID: 1234678
First name: Mark
Last name: Negus




SSN: 4321
ID: 87654321
First name: Gordon
Last name: Negus

*/

