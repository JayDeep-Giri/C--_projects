
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;
double addition (int checkin)

 {
	string cancel,pay;
	double bed,breakfast;


	cout<<"\nNo. of extra bed(1 bed = RS 50/night): ";
	cin>>bed;
	cout<<endl;
	cout<<"No. of pacs for breakfast(RS 15/pacs): ";
	cin>>breakfast;
	cout<<endl;
	cout<<"Do you want free cancellation policy? (RS 50) (yes/no): " ;
	cin>>cancel;
	cout<<endl;
	cout<<"Do you want to pay now or anytime between the current date and 3 days before the check in date? "<<endl;
	cout<<"If you pay 3 days before check in date , you will be charged a total of RS 30 (yes/no)"<<endl;
	cin>>pay;
	double total=0;
	bed=bed*50*checkin;
	breakfast=breakfast*15*checkin;
	if(cancel=="yes")
    {total+=50;}//price one night??
    else if ( cancel=="no")
    {total+=0;}

    if (pay == "yes")
    {total+=0;}
    else if (pay == "no")
    {total+=30;}

	total=total+bed+breakfast;
	return total;
}


void payment(double sum,double addf,string name,string address,string hpnum,int room,int people,int day1,int month1,int year1,int day2,int month2,int year2,int days)
{

  double tax = 0;
  double total = 0;
  tax=(sum+addf)*0.1;
  total=tax+sum+addf;

  string room_type;
  if (room==1)
  {
      room_type="Standard";
  }
  else if (room==2)
  {
      room_type="Deluxe";
  }

   cout <<"\t\t\t\t*************************\n"<<endl;
   cout <<"\t\t\t\t   Hotel Baby Sangnam"<<endl;
   cout <<"\n\t\t\t\t*************************"<<endl<<endl;
   cout << "Name :"<<name<<endl;
   cout << "Address :"<<address<<endl;
   cout << "Handphone Number :"<<hpnum<<endl<<endl;
   cout << "Room \t\t\t: "<<room_type<<endl;
   cout << "Tenants \t\t: "<<people<<" people"<<endl;
   cout << "Check in \t\t: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
   cout << "Check out \t\t: "<<day2<<"/"<<month2<<"/"<<year2<<endl;
   cout << "Duration Stayed \t: "<<days<<endl<<endl;
   cout << "Room Price\t\t: Rs "<<sum<<endl;
   cout << "Additional fees \t: RS "<<addf<<endl;
   cout << "Service tax (10%)\t: RS "<<tax<<endl;
   cout << "Final Total \t\t: RS "<<total<<endl<<endl;
   cout << "Thank you for booking with us! Enjoy your stay!"<<endl;
   cout << "For more information, contact us at 03-6557889 or visit our instagram @hotelbabysangnam"<<endl;

  fstream myfile;
   myfile.open ("receipt.txt");
   myfile <<"\t\t\t\t*************************\n"<<endl;
   myfile <<"\t\t\t\t   Hotel Baby Sangnam"<<endl;
   myfile<<"\n\t\t\t\t*************************"<<endl<<endl;
   myfile << "Name :"<<name<<endl;
   myfile << "Address :"<<address<<endl;
   myfile << "Handphone Number :"<<hpnum<<endl<<endl;
   myfile << "Room \t\t\t: "<<room_type<<endl;
   myfile << "Tenants \t\t: "<<people<<" people"<<endl;
   myfile << "Check in \t\t: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
   myfile << "Check out \t\t: "<<day2<<"/"<<month2<<"/"<<year2<<endl;
   myfile << "Duration Stayed \t: "<<days<<endl<<endl;
   myfile << "Room Price\t\t: RS "<<sum<<endl;
   myfile << "Additional fees \t: RS "<<addf<<endl;
   myfile << "Service tax (10%)\t: RS "<<tax<<endl;
   myfile << "Final Total \t\t: RS "<<total<<endl<<endl;
   myfile << "Thank you for booking with us! Enjoy your stay!"<<endl;
   myfile << "For more information, contact us at 03-6557889 or visit our instagram @hotelbabysangnam"<<endl;

  myfile.close();

}


double date (int day1,int month1, int year, int day2, int month2, int year4,int room )
{   int i;
    double difference;
    month1-=1;
    month2-=1;
    struct tm a = {0,0,0,day1,month1,year};
    struct tm b = {0,0,0,day2,month2,year4}; //104 = 2004
    time_t x = mktime(&a);
    time_t y = mktime(&b);
    double days;
    if ( x != (std::time_t)(-1) && y != (time_t)(-1) )
    {
        double difference = difftime(y, x) / (60 * 60 * 24);
        cout << ctime(&x);
        cout << ctime(&y);
        cout << "difference = " << difference << " days" << endl;
        days=difference;
    }

    cout<<days<<endl;
    return days;

}
int main()
{

    string name;
    string address;
    string hpnum;
    string add;
    int room;
    int people;
    int day1,month1,year1;
    int day2,month2,year2;
    int i,year,year4;
    start:
    cout<<"\n\t\t\t\t*************************";
    cout<<"\n\t\t\t\t HOTEL BOOKING SERVICE ";
    cout<<"\n\t\t\t\t      * MAIN MENU *";
    cout<<"\n\t\t\t\t*************************";

    cout<<"\n\nEnter the check in date:\n\n"<<endl;;
    cin>>day1>>month1>>year1;
    year=year1-1900;
    system("cls");

    cout<<day1<<"/"<<month1<<"/"<<year1<<endl;
    cout<<"Enter your name"<<endl;
    getline(cin, name);
    cout<<"Enter your address"<<endl;
    cin.ignore();
    getline(cin, address);
    cout<<"Enter your Handphone Number"<<endl;
    cin>>hpnum;
    cout<<"Enter the number of tenants"<<endl;
    cin>>people;
    cout<<"Choose your preferred room"<<endl;
    cout<<"Press '1' for standard room"<<endl;
    cout<<"Press '2' for deluxe room"<<endl;
    cin>>room;
    cout<<"Enter your check out date"<<endl;
    cin>>day2>>month2>>year2;
    year4=year2-1900;
    double days = date (day1,month1, year, day2, month2, year4,room);//dcalc(int day1,int month1,int year1,int day2,int month2,int year2)
    //system("cls");
    double sum=0;
    double addf=0;

    if (people<=2&&people>0)
    {
        if (room==1)
        {
            sum+=100;
            for(i=2;i<=days;i++)
            {
                sum+=70;
            }
        }

        else if (room==2)
        {
             sum+=200;
            for(i=2;i<=days;i++)
            {
                sum+=150;
            }
        }

    }
    else if (people<=4&&people>2)
    {
        if (room==1)
        {
            sum+=150;
            for(i=2;i<=days;i++)
            {
                sum+=120;
            }
        }

        else if (room==2)
        {
             sum+=300;
            for(i=2;i<=days;i++)
            {
                sum+=200;
            }
        }

    }
    else if (people<=6&&people>4)
    {
        if (room==1)
        {
            sum+=250;
            for(i=2;i<=days;i++)
            {
                sum+=150;
            }
        }

        else if (room==2)
        {
             sum+=400;
            for(i=2;i<=days;i++)
            {
                sum+=250;
            }
        }

    }
    cout<<sum<<endl;
    system("cls");
    cout<<"Do you want an addition of extra bed or any other services ? Type yes or no"<<endl;
    cin>>add;
   if (add=="yes")
    {
     addf=addition (days);
    }
    cout<<addf<<endl;
    system("cls");
    payment(sum,addf,name,address,hpnum,room,people,day1,month1,year1,day2,month2,year2,days);
    string choice;
    cout<<"Do you want to book another room.. (yes/no)?"<<endl;
    cin>> choice;
    if (choice=="yes")
    {
        goto start;
    }
    else if (choice=="no")
    {
        return 0;
    }


}

