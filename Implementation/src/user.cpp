#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

#include "../inc/user.h"
using namespace std;
user::user():uname(0),ulen(0),pass(0),plen(0)
{

}

user::user(const char* s1,const char* s2)
{
  size_t len=strlen(s1);
  ulen=len;
  uname=new char[len+1];
  strncpy(uname,s1,ulen);
  
  size_t len1=strlen(s2);
  plen=len1;
  pass=new char[len1+1];
  strncpy(pass,s2,plen);
  
}

user::user(const user& ref)
{
    this->ulen=ref.ulen;
    this->uname=new char[this->ulen];
    strncpy(this->uname,ref.uname,this->ulen);

    this->plen=ref.plen;
    this->pass=new char[this->plen];
    strncpy(this->pass,ref.pass,this->plen);

    //strcpy(this->m_str,ref.m_str);
    //this->m_len=ref.m_len;

}


int user::operator==(const user& ref)
{   
    return (strcmp(this->uname,ref.uname) && strcmp(this->pass,ref.pass));
}
int usermain()
{
        user u1;
        int choice;
        int l=0;
        if(l==1){
                return 0;
        }
        cout<<"***********************************************************************\n\n\n";
        cout<<"                      Welcome to login page                               \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<"1.LOGIN"<<endl;
        cout<<"2.REGISTER"<<endl;
        cout<<"3.FORGOT PASSWORD (or) USERNAME"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        l=u1.login();
                        break;
                case 2:
                        u1.registr();
                        break;
                case 3:
                       u1.forgot();
                        break;

                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl; 
                        usermain();
        }
        return 0;
}

int user::login() 
{
        int count;
        string username,password,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>username;
        cout<<"PASSWORD :";
        cin>>password;
        const char* un=username.c_str();
        const char* pd=password.c_str();
        user u1(un,pd);
        
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                const char* un1=u.c_str();
                const char* pd1=p.c_str();
                user u2(un1,pd1);
                if((u1==u2)==0)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<u1.uname<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in"<<endl;
                //cin.get();
                //cin.get();
                //usermain();
                return 1;
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                usermain();
        }
        return 0;
}

void user::registr() const
{
        
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        usermain();
        
        
}

void user::forgot() const
{
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;
                        
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                usermain();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                usermain();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;
                        
                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                usermain();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                usermain();
                        }
                
                        break;
                }
                
                case 3:
                {
                        cin.get();
                        usermain();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
}
 char* user::get_uname()
 {
         return uname;

 }

 char*user::get_pass(){
         return pass;
 }
 user::~user()
 {

 }


 
