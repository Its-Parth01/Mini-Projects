/* 
1. Create account; for multiple users & save data into file 
2. Account info; of a particular user who are signed in according to account number
3. Deposit amount; add amount to previous ones
4. Check previous amount; check amount in account
5. Withdraw amount; withdraw amount from the previos if the not show an error
6. Delete account
*/


#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class temp {
    int acc_no;
    char name[25];
    char fname[25];
    char cnic[25];
    char p_no[25];
    char email[25];
    float amount;
    int new_ammount;
    fstream file,file1;
public:
    int search;
    void create_account();
    void search_data();
    void Deposit();
    void Withdraw();

}obj;

int main () 
{
    char choice;
    cout<<"---------------------------------------";
    cout<<"\n1 - Create Account";
    cout<<"\n2 - Login Account";
    cout<<"\n3 - Exit"<<endl;
    cout<<"---------------------------------------";
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch(choice){
        case '1':
            cin.ignore();
            obj.create_account();
    
        break;

        case '2':
            cout<<"Enter your account no :: ";
            cin>>obj.search;

            while(1){

            cout<<"\n\n\n\t\t.......:::Bahram's Bank:::.......";
            cout<<"\n\t\t:: press 1 to Deposit  Amount  :: ";
            cout<<"\n\t\t:: press 2 to Withdraw Amount  ::";
            cout<<"\n\t\t:: press 3 to Check    Info    ::";
            cout<<"\n\t\t:: press 0 to Exit     Menu    ::";
            cout<<"\n\t\t:: ........................... ::\n\t\t\t\t";
            cin>>choice;

            switch (choice)
            {
            case '1':
                obj.Deposit();
            break;
            case '2':
                obj.Withdraw();
            break;
            case '3':
                obj.search_data();
            break;
            case '0':
                return 0;
            break;
            default:
                cout<<"Invalid Choice...!";
            break;
            }
            system("pause");
            system("cls");
        }
        break;

        case '3':
            return 0;   
        break;

        default:
            cout<<"Invalid Choice...!";
    }  
    return 0;
}
void temp :: create_account() 
{
    srand(time(0)); // To generate random numbers
    acc_no = rand()*rand()+rand()*rand(); // Generating unique account no.

    cout<<"Enter Your Name :: ";
    cin>>name;
    cout<<"Enter Your father Name :: ";
    cin>>fname;
    cout<<"Enter Your cnic :: ";
    cin>>cnic;
    cout<<"Enter Your phone no :: ";
    cin>>p_no;
    cout<<"Enter Your email :: ";
    cin>>email;
    cout<<"Enter amount :: ";
    cin>>amount;

    cout<<acc_no<< " This is Your Account number... \n";
    cout<<"Please save it \n";

    file.open("data.txt", ios::out | ios::app);
    file<<acc_no<<"\t"<<name<<"\t"<<fname<<"\t"<<cnic<<"\t"<<p_no<<"\t"<<email<<"\t"<<amount<<endl;
    file.close();
}
void temp :: search_data() 
{
    fstream file;
    file.open("data.txt",ios::in);
    if(!file) {
        cout << "File not found.";
        return ;
    }
    file>>acc_no>>name>>fname>>cnic>>p_no>>email>>amount; // collect data from file
    while(!file.eof()) {
        if (search == acc_no) {
            cout<<"Account Number  : "<<acc_no<<endl;
            cout<<"Name            : "<<name<<endl;
            cout<<"Father's Name   : "<<fname<<endl;
            cout<<"CNIC No         : "<<cnic<<endl;
            cout<<"Phone No        : "<<p_no<<endl;
            cout<<"Email ID        : "<<email<<endl;
        }
        file >> acc_no >> name >> fname >> cnic >> p_no >> email >> amount; // collect next data
    }
    file.close();
}
void temp :: Deposit()
{
    cout<<"enter your new amount ::";
    cin>>new_ammount;

    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    file>>acc_no>>name>>fname>>cnic>>p_no>>email>>amount;

while(!file.eof()) {
    if(search == acc_no ) {
        cout<<"\ncurrent amount :: "<<amount;
        amount += new_ammount;
        cout<<"\nupdating amount :: "<<amount<<endl;
        file1<<acc_no<<"\t"<<name<<"\t"<<fname<<"\t"<<cnic<<"\t"<<p_no<<"\t"<<email<<"\t"<<amount<<endl;
    } else {
        file1<<acc_no<<"\t"<<name<<"\t"<<fname<<"\t"<<cnic<<"\t"<<p_no<<"\t"<<email<<"\t"<<amount<<endl;
}
file >> acc_no >> name >> fname >> cnic >> p_no >> email >> amount;
    
}
file.close();
file1.close();
remove("data.txt");
rename("data1.txt","data.txt");
} 
void temp :: Withdraw()
{
    cout<<"enter your new amount ::";
    cin>>new_ammount;

    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    file>>acc_no>>name>>fname>>cnic>>p_no>>email>>amount;

while(!file.eof()) {
    if(search == acc_no ) {
        cout<<"\ncurrent amount :: "<<amount;
        amount -= new_ammount;
        cout<<"\nupdating amount :: "<<amount<<endl;
        file1<<acc_no<<"\t"<<name<<"\t"<<fname<<"\t"<<cnic<<"\t"<<p_no<<"\t"<<email<<"\t"<<amount<<endl;
    } else {
        file1<<acc_no<<"\t"<<name<<"\t"<<fname<<"\t"<<cnic<<"\t"<<p_no<<"\t"<<email<<"\t"<<amount<<endl;
}
file >> acc_no >> name >> fname >> cnic >> p_no >> email >> amount;
    
}
file.close();
file1.close();
remove("data.txt");
rename("data1.txt","data.txt");
} 