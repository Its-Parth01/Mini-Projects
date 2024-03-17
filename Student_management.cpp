#include<iostream>
#include<fstream>
using namespace std;

class temp
{
    string rollno,name,fname,address,search;
    fstream file;
public:
    void addstudent();
    void viewstudent();
    void searchstudent();
}obj;

int main () 
{
    char choice;
    cout<<"---------------------------------------";
    cout<<"\n1 - Add Student Record";
    cout<<"\n2 - Display all Student";
    cout<<"\n3 - Search Student Record";
    cout<<"\n4 - Exit"<<endl;
    cout<<"---------------------------------------";
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch(choice){
        case '1':
            cin.ignore();
            obj.addstudent();
        break;

        case '2':
            cin.ignore();
            obj.viewstudent();
        break;

        case '3':
            cin.ignore();
            obj.searchstudent();
        break;

        case '4':
            return 0;
        break;

        default:
            cout<<"Invalid Choice...!";
    }
    return 0;
}
void temp :: addstudent()
{
    cout<<"Enter Student Roll No : ";
    getline(cin,rollno);
    cout<<"Enter Student Name : ";
    getline(cin,name);
    cout<<"Enter Father's Name : ";
    getline(cin,fname);
    cout<<"Enter Student Address : ";
    getline(cin,address);

    file.open("student.txt",ios :: out|ios :: app);
    file<<rollno<<"*";
    file<<name<<"*";
    file<<fname<<"*";
    file<<address<<endl;
    file.close();
}
void temp :: viewstudent()
{
    file.open("student.txt",ios::in);
    getline(file,rollno,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');

    while(!file.eof()) 
    {
        cout<<"\nStudent Roll no ::"<<rollno;
        cout<<"\nName :: "<<name;
        cout<<"\nFather's Name :: "<<fname;
        cout<<"\nAddress :: "<<address<<endl;

    getline(file,rollno,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');
    }
    file.close();
}
void temp :: searchstudent() 
{
    cout<<"Enter Student Roll No : ";
    getline(cin,search);

    file.open("student.txt",ios::in);
    getline(file,rollno,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');

    while(!file.eof()) {
        if(rollno==search) {
            cout<<"\nStudent Roll no ::"<<rollno;
            cout<<"\nName :: "<<name;
            cout<<"\nFather's Name :: "<<fname;
            cout<<"\nAddress :: "<<address<<endl;
        }
        getline(file,rollno,'*');
        getline(file,name,'*');
        getline(file,fname,'*');
        getline(file,address,'\n');
    }
    file.close();
}