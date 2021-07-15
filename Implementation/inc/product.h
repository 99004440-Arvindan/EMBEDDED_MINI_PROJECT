#ifndef __FUN_H__
#define __FUN_H__
//**********************************************************//
#include <iostream>
#include <fstream>
#include <cstring>
#include "user.h"
fstream file;
//**************Class User**************//
/*class user
{
  private:
    char username[20];
    char password[20];
public:
    void add_user()
    {
        std::cout<<"\n\n\t\t\tADD USER\n\n";
        std::cout<<"\n\t\tEnter the username and password\n";
        std::cout<<"\tUsername  :  ";
        std::cin>>username;
        std::cout<<"\tPassword  :  ";
        std::cin>>password;
        std::fstream file;
        file.open("user.txt",std::ios::app|std::ios::out);
        file.write(reinterpret_cast<char*>(this),sizeof(*this));
        file.close();
    }

    int verify()
    {
        //display_nce();
        char u[20];
        char pw[20];
        int count;
        std::cout<<"\n\t\tPlease Enter the username and password\n";
        std::cout<<"\tUsername  :  ";
        std::cin>>u;
        std::cout<<"\tPassword  :  ";
        std::cin>>pw;
        std::fstream file;
        file.open("user.txt",std::ios::in);
        file.seekg(0);
                                
        while(!file.eof())
        {
            if(strcmp(username,u)==0)
            {
                if(strcmp(password,pw)==0)
                {
                    count=1;
                }
            }
            file.read(reinterpret_cast<char*>(this),sizeof(*this));

        }
        file.close();
    return(count);
    }
};*/

//*************************************************************************//

//****************Class Product***********************//

class product : public user
{
protected:
    unsigned int product_id;
    std::string product_name;
    float product_rate;
    float product_discount;
 public:
	bool create_product(int);
    void show_product();
    void display_all();
    bool display_specific_product(int);
    void price_list();
    void modify_product();
    void delete_product();
    void admin_menu();
        void fread()
    {
        file.read(reinterpret_cast<char*>(this),sizeof(*this));
    }
    ~product();
};
#endif  