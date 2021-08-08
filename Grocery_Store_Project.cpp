#include<stdio.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<iomanip>
#include<time.h>
#include<unistd.h>
#include<cstdlib>
#define num_of_stock 200
using namespace std;
int password();
void menu();
void show();
class stock
{
	public:
    string staff_name,profession,aadhar,mobile_number;
    int id,price,age;
    string product_name,address;
    string manu_date,exp_date;
    char gender;

    public:
    void setdata();
    void search_data();
    void add_new();
    void view_stock();
    void search_by_product_name();
    void search_by_ID();
    void search_by_list();
    void staff_detail();
    void add_staff_detail();
    void show_staff_detail();
    void staff_search();
    void staff_searching();
    void search_by_aadhar();
    void search_by_age();
    void search_by_gender();
    void search_by_profession();
    void show_list();
    void showdata();
    void view_data();
};
void show()
 {
   cout<<setw(20)<<setiosflags(ios::left)<<"product_name"<<endl;
    cout<<setw(20)<<"ID"<<endl;
    cout<<setw(18)<<"Price"<<endl;
    cout<<setw(15)<<"Manufaturing_date"<<endl;
    cout<<"Expiry_date"<<endl;
}
void stock::view_stock()
{
    ifstream ind;
    int i=0;
    ind.open("stock.txt");
    ind.seekg(0,ios::beg);
    while (ind.read((char*)this,sizeof(stock)))
    {
        i++;
    }
    ind.close();
    int ch;
    int s=num_of_stock +i;
    cout<<"\n\t\t\t\t                 Grocery Management                       "<<endl;
    cout<<"\n                         Powered by:-   RITUL GUPTA               "<<endl;
    cout<<"                 *******"<<endl;
    cout<<"                            Grocery statistics"<<endl;
    cout<<endl;
    cout<<"                *******"<<endl;
    cout<<"1. Add More Data            2. View data               3.Back"<<endl;
    cout<<endl;
    cin>>ch;
    int f_var=0;
    fstream file("count.txt");
    file>>f_var;
    switch(ch)
    {
        case 1:
             int m;
             cout<<"Enter No of stock you want to add "<<endl;
             cin>>m;
             f_var=f_var + m;
             file.seekg(0);
             file<<f_var;
             cout<<"Now Total No of Stock are: "<<f_var + s;
             break;

        case 2:
             cout<<"Available no of stock "<<s + f_var;
             break;

        case 3:
             system("cls");
             menu();

       default:
            system("cls");
            cout<<"\n Enter vaild option "<<endl;
            menu();
    }
    file.close();
    getch();
}
void stock:: show_list()
{
    cout<<"\n";
    cout<<setw(20)<<setiosflags(ios::left)<<product_name<<endl;
    cout<<setw(20)<<id<<endl;
    cout<<setw(18)<<price<<endl;
    cout<<setw(15)<<manu_date<<endl;
    cout<<exp_date<<endl;
    cout<<endl;

}
void stock::search_data()
{
    stock item;
    cout<<"                          Grocery Management                    "<<endl;
    cout<<"                          Powered by:- RITUL GUPTA              "<<endl;
    cout<<"                    ******"<<endl;
    cout<<"                         Searching Statistics\n\n\n"<<endl;
    cout<<"\n\n\nFrom Which Option You want to perform searching \n\n\n"<<endl;
    cout<<"1.By Product_Name\n";
    cout<<"2.By Id \n\n"<<endl;
    cout<<"Enter Your Choice  ";
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
             system("cls");
             item.search_by_product_name();
             getch();
             break;

       case 2:
            system("cls");
            item.search_by_ID();
            getch();
            break;

       default:
              system("cls");
              cout<<"Enter Valid Option "<<endl;
              menu();
    }
}
void stock:: search_by_product_name()
{
    ifstream in("stock.txt");
    int flag=0;
    string pro_num;
    cout<<"                                Grocery Management"<<endl;
    cout<<"                                Powered Management"<<endl;
    cout<<"                          *****"<<endl;
    cout<<"\n                             Product searching"<<endl;
    cout<<"                         ***"<<endl;
    cout<<"Enter your Product Name "<<endl;
    fflush(stdin);
    getline(cin,pro_num);
    show();
    in.read((char*)this,sizeof(stock));
    while(!in.eof())
    {
        if(pro_num.compare(product_name)==0)
        {
            show_list();
            flag=1;
            break;
        }
        in.read((char*)this,sizeof(stock));
    }
    if(flag==0)
    {
        cout<<"Product Name not found "<<endl;
    }
    in.close();
}
void stock::search_by_ID()
{
    ifstream in("stock.txt");
    int flag=0;
    int a;
    cout<<"                        Grocery Management"<<endl;
    cout<<"                       Powered by:-RITUL GUPTA"<<endl;
    cout<<"                   ****"<<endl;
    cout<<"Enter Id "<<endl;
    cin>>a;
    show();
    in.read((char*)this,sizeof(stock));
    while(!in.eof())
    {
        if(a==id)
        {
            show_list();
            flag=1;
            break;
        }
        in.read((char*)this,sizeof(stock));
    }
    if(flag==0)
    {
        cout<<"Id you enterd is not found"<<endl;
    }
    in.close();
}
void stock::setdata()
{
    string name;
    cout<<"                              Grocery Management"<<endl;
    cout<<"\n                            Powered by:-RITUL GUPTA"<<endl;
    cout<<"                         *****"<<endl;
    fflush(stdin);
    cout<<"\n Enter Product Name "<<endl;
    getline(cin,product_name);
    cout<<"Enter Product Price "<<endl;
    cin>>price;
    cout<<"Enter Product ID "<<endl;
    cin>>id;
    cout<<"Product Manufacturing Date "<<endl;
    fflush(stdin);
    getline(cin,manu_date);
    cout<<"Product Expiry Date"<<endl;
    getline(cin,exp_date);

}
void stock:: showdata()
{
    cout<<"                         Grocery Management"<<endl;
    cout<<"                        Powered by:-RITUL GUPTA"<<endl;
    cout<<"                   ****"<<endl;
    cout<<"\n\n         Detail\n"<<endl;
    cout<<"Product Name is: "<<product_name<<endl;
    cout<<"Product Price is: "<<price<<endl;
    cout<<"Product ID is: "<<id<<endl;
    cout<<"Product Manufacturing date: "<<manu_date<<endl;
    cout<<"Product Expiry date: "<<exp_date<<endl;
}
void stock::add_new()
{
    fstream outline;
    outline.open("stock.txt",ios::app|ios::in);
    setdata();
    outline.write((char*)this,sizeof(stock));
    cout<<"Your Data Has Been Successfully"<<endl;
    getch();
    outline.close();
}
void stock::staff_detail()
{
    cout<<"                               Grocery Management"<<endl;
    cout<<"                               Powered by:-RITUL GUPTA"<<endl;
    cout<<"                         *****"<<endl;
    cout<<"                Staff Detail"<<endl;
    cout<<"          *****"<<endl;
    fflush(stdin);
    cout<<"Enter Staff Name"<<endl;
    getline(cin,staff_name);
    cout<<"Enter Aadhar Number"<<endl;
    getline(cin,aadhar);
    cout<<"Enter Staff Gender(m|f)"<<endl;
    cin>>gender;
    cout<<"Enter Staff age"<<endl;
    cin>>age;
    fflush(stdin);
    cout<<"Enter your Profession"<<endl;
    getline(cin,profession);
    fflush(stdin);
    cout<<"Enter Staff Permanent Address"<<endl;
    getline(cin,address);
    cout<<"Enter Staff Mobile Number"<<endl;
    getline(cin,mobile_number);
}
void stock::add_staff_detail()
{
    fstream outline;
    outline.open("stock.txt",ios::app|ios::in);
    staff_detail();
    outline.write((char*)this,sizeof(stock));
    cout<<"Your Staff Detail Has Been Successfully Inserted"<<endl;
    getch();
    outline.close();
}
void stock::show_staff_detail()
{
    cout<<"                          Grocery Management"<<endl;
    cout<<"                          Powered by:-RITUL GUPTA"<<endl;
    cout<<"                      *****"<<endl;
    cout<<"                 Staff Detail"<<endl;
    cout<<"             ****"<<endl;
    cout<<" Name is :"<<staff_name<<endl;
    cout<<" Aadhar Number is:"<<aadhar<<endl;
    cout<<" Gender is:"<<gender<<endl;
    cout<<" Age is:"<<age<<endl;
    cout<<" Profession is:"<<profession<<endl;
    cout<<" Address is:"<<address<<endl;
    cout<<" Mobile Number is:"<<mobile_number<<endl;
}
void stock::search_by_aadhar()
{
    ifstream in("stock.txt");
    int flag=0;
    string adh_num;
    cout<<"                          Grocery Management"<<endl;
    cout<<"                          Powered by:-RITUL GUPTA"<<endl;
    cout<<"                       *****"<<endl;
    cout<<"       Aadhar Searching"<<endl;
    cout<<"Enter your Aadhar number"<<endl;
    fflush(stdin);
    getline(cin,adh_num);
    in.read((char*)this,sizeof(stock));
    while(!in.eof())
    {
        if(adh_num.compare(aadhar)==0)
        {
            show_staff_detail();
            flag=1;
            break;
        }
        in.read((char*)this,sizeof(stock));
    }
    if(flag==0)
    {
        cout<<"Aadhar number not found"<<endl;
    }
    in.close();
}
void stock::search_by_age()
{
    ifstream in("stock.txt");
    int flag=0;
    int a,p=0;
    cout<<"                          Grocery Management"<<endl;
    cout<<"                          Powered by:-RITUL GUPTA"<<endl;
    cout<<"                   ******"<<endl;
    cout<<"           Age Searching"<<endl;
    cout<<"        ***"<<endl;
    cout<<"Enter Age by which you want to search"<<endl;
    cin>>a;
    in.read((char*)this,sizeof(stock));
    while(!in.eof())
    {
        if(a==age)
        {
            show_staff_detail();
            flag=1;
        }
        in.read((char*)this,sizeof(stock));
    }
    if(flag==0)
    {
        cout<<"Age you entered is not found"<<endl;
    }
    in.close();
}
void stock::search_by_profession()
{
    ifstream in("stock.txt");
    int flag=0;
    string prof;
    cout<<"                          Grocery Management"<<endl;
    cout<<"                          Powered by:-RITUL GUPTA"<<endl;
    cout<<"                       *****"<<endl;
    cout<<"       Profession Searching"<<endl;
    cout<<"Enter your profession"<<endl;
    fflush(stdin);
    getline(cin,prof);
    in.read((char*)this,sizeof(stock));
    while(!in.eof())
    {
        if(prof.compare(profession)==0)
        {
            show_staff_detail();
            flag=1;
            break;
        }
        in.read((char*)this,sizeof(stock));
    }
    if(flag==0)
    {
        cout<<" The Profession does not exist"<<endl;
    }
    in.close();
}
void stock::search_by_gender()
{
    ifstream in("stock.txt");
    int flag=0;
    char g;
    cout<<"                          Grocery Management"<<endl;
    cout<<"                          Powered by:-RITUL GUPTA"<<endl;
    cout<<"                   ******"<<endl;
    cout<<"                       Gender Searching"<<endl;
    cout<<"                  ***"<<endl;
    cout<<"Enter gender by which you want to search"<<endl;
    cin>>g;
    in.read((char*)this,sizeof(stock));
    while(!in.eof())
    {
        if(toupper(g)==toupper(gender))
        {
            show_staff_detail();
            flag=1;
            break;
        }
        in.read((char*)this,sizeof(stock));
    }
    if(flag==0)
    {
        cout<<"Gender you entered is not found"<<endl;
    }
    in.close();
}
void stock::staff_searching()
{
    stock item;
    cout<<"                        Grocery Management"<<endl;
    cout<<"                        Powered by:-RITUL GUPTA"<<endl;
    cout<<"                    ******"<<endl;
    cout<<"          Staff Seraching"<<endl;
    cout<<"      ****"<<endl;
    cout<<"Enter which you want to perform searching "<<endl;
    cout<<"1: By addhar                         2: By age "<<endl;
    cout<<"3: By profession                     4: By gender"<<endl;
    cout<<"Enter your choice ";
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
             system("cls");
             item.search_by_aadhar();
             getch();
             break;

       case 2:
            system("cls");
            item.search_by_age();
            getch();
            break;

        case 3:
            system("cls");
            item.search_by_profession();
            getch();
            break;

        case 4:
            system("cls");
            item.search_by_gender();
            getch();
            break;

       default:
           system("cls");
           cout<<"Enter valid Option "<<endl;
           menu();
    }
}
/*void stock::staff_search()
{
    ifstream in("stock.txt");
    int flag=0;
    in.read((char*)this,sizeof(stock));
    while(!in.eof())
    {
      staff_searching();
      flag=1;
      break;
    }
    getch();
    in.close();
}*/
void menu()
{
    system("cls");
    cout<<"                           Grocery Management"<<endl;
    cout<<"                         Powered by:-RITUL GUPTA"<<endl;
    cout<<"                 ******\n\n"<<endl;
    cout<<"                                 MENU"<<endl;
    cout<<"                         **"<<endl;
    cout<<"1. Add new Product            2.view stock"<<endl;
    cout<<"3. Product Search             4.Add staff detail"<<endl;
    cout<<"5. staff search               6.Exit"<<endl;
}
int password()
{
    char cname[30],pass[20];
    int ch,i=0,cap=0,capt=0,p;
    cout<<"\nUser Name ";
    fflush(stdin);
    gets(cname);
    cout<<"\nPassword ";
    while((ch=getch())!=13)
    {
        cout<<"@";
        pass[i]=ch;
        i++;
    }
    pass[i]='\0';
    srand(time(0));
    cap=rand();
    cout<<"\nCAPTURE : "<<cap<<endl;
    cout<<"Please enter the valid Capture: ";
    cin>>capt;
    if((strcmp(cname,"guru")==0)&&(strcmp(pass,"9079")==0)&&cap==capt)
    return 1;
    else
    return 0;
}
int main()
{
    stock obj;
    int k=3;
    int num_sto;
    cout<<"                                 Grocery Management"<<endl;
    cout<<"                                 Powered by:-RITUL GUPTA"<<endl;
    cout<<"                          *****\n\n"<<endl;
    cout<<"Press any key to continue..............\n\n";
    getch();
    B:
    system("cls");
    cout<<"\n**********"<<endl;
    cout<<"                           Enter user name and password\n";
    cout<<"***********"<<endl;
    while(k>=1)
    {
        int c=password();
        if(c==1)
        break;
        else
        cout<<"\n Wrong Password or user Name"<<endl;
        cout<<"\n You can try only "<<k-1<<"times more"<<endl;
        k--;
        if(k<1)
        {
            for(int i=59;i>=0;i--)
            {
                system("cls");
                cout<<"You are blocked for 1 minute"<<endl;
                cout<<"Try After "<<i<<"seconds"<<endl;
                sleep(1000);
            }
            k==3;
            goto B;
        }
    }
    int ch;
    do
    {
      cout<<"                                       Grocery Management"<<endl;
      cout<<"                                       Powered by:-RITUL GUPTA"<<endl;
      cout<<"                               ******"<<endl;
      menu();
      cout<<"Choose according to your need"<<endl;
      cin>>ch;
      stock s1;
      switch(ch)
      {
          case 1:
               system("cls");
               obj.add_new();
               break;

        case 2:
             system("cls");
             obj.view_stock();
             break;

        case 3:
            system("cls");
            obj.search_data();
            break;
        
        case 4:
            system("cls");
            obj.add_staff_detail();
            break;
        
        case 5:
        	system("cls");
        	obj.staff_searching();
        	break;
        	
        case 6:
            system("cls");
            exit(0);

        default:
             cout<<"\n THANK YOU";
             cout<<"\nHave a Nice Day";
             sleep(3000);
             exit(0);

      }
    } while(ch!=0);
    
}
