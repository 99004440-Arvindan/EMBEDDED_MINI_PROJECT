#include<iomanip>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include "../src/product.cpp"
using namespace std;


class customer
{
    private:
        char fname[20],lname[20];
        char add[25];
        char cn[10];

    public:
        void c_read();
        void c_display();

};

void customer::c_read()
        {
            display_nce();
            cout<<"Enter full name of the customer   :    ";
            cin>>fname;
            cin>>lname;
            cout<<"Enter address of the customer     :    ";
            cin>>add;
            cout<<"Enter contact no. of the customer :    ";
            cin>>cn;
        }

void customer::c_display()
        {
            cout<<"Customer Name     :  "<<fname<<" "<<lname<<endl;
            cout<<"Customer Address  :  "<<add<<endl;
            cout<<"Contact no.       :  "<<cn<<endl;

        }


        class bill : public product , public customer
{
  private :
    int  order_arr[50],quan[50];
    float amt,damt,total;
  public :
    void place_order()
    {
        int n,count=0;
        system("cls");
        customer::c_read();
        system("cls");
        display_nce();
        cout<<"\n\tHow many items are there?   ";
        cin>>n;
        printstars();
        total=0;
        for(int i=0;i<n;i++)
        {
            cout<<"\n\nEnter the Product ID of the Product "<<i+1<<"  :  ";
            cin>>order_arr[i];
            cout<<"\nEnter the quantity of Product "<<i+1<<"  :  ";
            cin>>quan[i];
        }
        //system("cls");
        display_nce();
        cout<<"\n\n***********************************INVOICE**************************************\n\n";
        customer::c_display();
        cout<<"\n\n\n";
        cout<<"\nPr ID\tPr Name\t\tQuantity \tPrice \tAmount \tAmount after discount\n";
        for(int x=0;x<n;x++)
        {
            file.open("product.dat",ios::in);
            file.seekg(0);
            product::fread();
            while(!file.eof())
            {
                if(product_id==order_arr[x])
                {
                    amt=product_rate*quan[x];
                    damt=amt-((amt*product_discount)/100);
                    cout<<"\n"<<order_arr[x]<<"\t"<<product_name<<"\t"<<quan[x]<<"\t\t"<<product_rate<<"\t"<<amt<<"\t\t"<<damt;
                    total+=damt;
                }
                product::fread();

            }
            file.close();
        }
        cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
        getchar();
        }




};
