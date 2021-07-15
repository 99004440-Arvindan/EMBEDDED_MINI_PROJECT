#include "inc/user.h"
//#include "src/user.cpp"
#include "inc/product.h"
#include "src/bill.cpp"

void display_main()
{
    display_nce();
    cout<<"\t\t _______________________________"<<endl;
    cout<<"\t\t|**********MAIN   MENU**********|"<<endl;
    cout<<"\t\t|_______________________________|"<<endl;
    cout<<"\n\n\n";
    cout<<"\n\t\t<1>Place Order"<<
          "\n\t\t<2>Admin Panel"<<
          "\n\t\t<3>Log out"<<
          "\n\t\t<4>Exit"<<endl;
}

int main()
{

usermain();
int choice,ch,v;
user ur;
product pr;
bill bi;
main:
    while(1)
        {
            //system("cls");
            display_main();
            cout<<"\n\t\tEnter your choice  :  ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    system("cls");
                    bi.place_order();
                    break;

                case 2:
                    system("cls");
                    display_nce();
                    pr.admin_menu();
                    break;

                case 3:
                    system("cls");
                    goto main;
                    break;
                case 4:
                    exit(0);
                    break;

                default :
                    cout<<"Invalid choice";
                }
            }

cout<<"done"<<endl;
return 0;
}
