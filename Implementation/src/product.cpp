#include "../inc/product.h"

void printstars() //for printing the stars as shown
{
    std::cout<<"\n********************************************************************************\n"<<std::endl;

}
void display_nce()
{
    std::cout<<"\n|--------------------------------------------------------------------------|"<<std::endl;
    std::cout<<"|******************************SUPERMARKET*********************************|"<<std::endl;
    std::cout<<"|--------------------------------------------------------------------------|"<<std::endl;
    printstars();
}
bool product::create_product(int id)
{
    if(id>0)
    {
    product_id=id;
    std::cout<<"\nEnter the name of the product : ";
    std::cin>>product_name;
    std::cout<<"\nEnter the Rate of the product : ";
    std::cin>>product_rate;
    std::cout<<"\nEnter the Discount (%) : ";
    std::cin>>product_discount;
    std::fstream file;
    file.open("product.dat",std::ios::app|std::ios::out);
    file.write(reinterpret_cast<char*>(this),sizeof(*this));
    file.close();
    return true;
    }
    else
        return false;
}
void product::show_product()
{
    std::cout<<"*****************************";
    std::cout<<"\nProduct ID : "<<product_id;
    std::cout<<"\nName       : "<<product_name;
    std::cout<<"\nRate       : "<<"Rs. "<<product_rate;
    std::cout<<"\nDiscount   : "<<product_discount<<"%";
    std::cout<<"\n*****************************";
}
void product::display_all()
{
    std::cout<<"\n\n\n\t\t DISPLAYING ALL RECORDS \n\n";
    std::fstream file;
    file.open("product.dat",std::ios::in);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(this),sizeof(*this));
    while(!file.eof())
    {
    
    show_product();
    file.read(reinterpret_cast<char*>(this),sizeof(*this));
    std::cout<<"\n\n====================================\n\n";
    }
    file.close();
    getchar();
}

bool product::display_specific_product(int n)
{
    int flag=0;
    std::fstream file;
    file.open("product.dat",std::ios::in);
    file.seekg(0);
    while(!file.eof())
	{
	    file.read(reinterpret_cast<char*>(this),sizeof(*this));
	    if(product_id==n)
		{
		 show_product();
		 flag=1;
		}
	}
	file.close();
    return flag;
}

void product::price_list()
{
    std::fstream file;
    file.open("product.dat",std::ios::in);
    std::cout<<"====================================================\n";
    std::cout<<"\t\t\t\tProduct MENU\n";
    std::cout<<"====================================================\n";
    std::cout<<"Product ID\t\tNAME\t\tPRICE\n";
    file.seekg(0);
    file.read(reinterpret_cast<char*>(this),sizeof(*this));
    while(!file.eof())
    {
        std::cout<<product_id<<"\t\t\t"<<product_name<<"\t\t"<<product_rate<<std::endl;
        file.read(reinterpret_cast<char*>(this),sizeof(*this));
    }
    file.close();
    getchar();
}

void product::modify_product()
{
    int n,pos,flag=0;
    std::cout<<"\n\nEnter the product ID of the product to modify : ";
    std::cin>>n;
    std::fstream file;
    file.open("product.dat",std::ios::in|std::ios::out);
    while(!file.eof())
	{
        file.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(product_id==n)
        {
            show_product();
            pos=-1*sizeof(*this);
            file.seekp(pos,std::ios::cur);
            std::cout<<"\nEnter the product ID of the product : ";
            std::cin>>product_id;
            std::cout<<"\nEnter the Name of the product       : ";
            std::cin>>product_name;
            std::cout<<"\nEnter the Rate of the product      : ";
            std::cin>>product_rate;
            std::cout<<"\nEnter the Discount (%)              : ";
            std::cin>>product_discount;
            file.write(reinterpret_cast<char*>(this),sizeof(*this));
            std::cout<<"\n\n\t Record Updated";
            flag=1;
         }
    }
    file.close();
    if(flag==0)
    std::cout<<"\n\nSorry!!! Record Not Found ";
    getchar();
}

void product::admin_menu()
{
  char ch;
  int id,product_id;
  bool valid,flag;
  while(1)
  {
    std::cout<<"\n\n\t1.CREATE PRODUCT";
    std::cout<<"\n\t2.DISPLAY ALL PRODUCTS";
    std::cout<<"\n\t3.DISPLAY SPECIFIC PRODUCT";
    std::cout<<"\n\t4.MODIFY PRODUCT";
    std::cout<<"\n\t5.DELETE PRODUCT";
    std::cout<<"\n\t6.DISPLAY PRICE LIST";
    std::cout<<"\n\t7.ADD USER";
    std::cout<<"\n\t8.BACK TO MAIN MENU";
    std::cout<<"\n\n\n\tEnter Your Choice :\t ";
    std::cin>>ch;
    switch(ch)
    {
        case '1':
            display_nce();
            std::cout<<"\nEnter the product ID of the product : ";
            std::cin>>product_id;
            valid=create_product(product_id);
            if(valid)
                std::cout<<"\n\nThe Product Has Been Created."<<std::endl;
            else
                std::cout<<"Incorrect Product ID"<<std::endl;
            break;
        case '2':
            display_nce();
            display_all();
            break;
        case '3':
            display_nce();
            std::cout<<"Enter the product id of the product to be displayed : "<<std::endl;
            std::cin>>id;
            flag=display_specific_product(id);
            if(flag)
                std::cout<<"\n\n Product found successfully"<<std::endl;
            else
                std::cout<<"Product doesn't exist"<<std::endl;
            break;
        case '4':
            display_nce();
            modify_product();
            break;
        case '5':
            display_nce();
            delete_product();
            break;
        case '6':
            display_nce();
            price_list();
            break;
        /*case '7':
            system("cls");
            display_nce();
            user::add_user();
            break;
        case '8':
            goto leave;
            break;*/
        default:std::cout<<"Invalid Choice";
       }
  }
  leave:
  std::cout<<" ";
}

void product::delete_product()
{
    int n,flag=0;
    std::fstream file;
    std::fstream file2;
    std::cout<<"\n\n\n\tDelete Record";
    std::cout<<"\n\nEnter the Product id of the Product to Delete  :  ";
    std::cin>>n;
    file.open("product.dat",std::ios::in);
    file2.open("Temp.dat",std::ios::out);
    file.seekg(0);
    while(!file.eof())
	{
	    file.read(reinterpret_cast<char*>(this),sizeof(*this));
	    if(product_id!=n)
		{
		 file2.write(reinterpret_cast<char*>(this),sizeof(*this));
		 flag++;
		 }
	 }
    file2.close();
    file2.open("Temp.dat",std::ios::in);
    file2.seekg(0);
    file.open("product.dat",std::ios::out|std::ios::trunc);
    while(!file2.eof())
	{
		 file2.read(reinterpret_cast<char*>(this),sizeof(*this));
		 file.write(reinterpret_cast<char*>(this),sizeof(*this));

	 }
	 file.close();
	 file2.close();
	 if(flag==0)
	 std::cout<<"\n\nSorry!!! Record Not Found ";
    getchar();
}
product::~product()
{
    std::cout<<" in dtor"<<std::endl;
}
