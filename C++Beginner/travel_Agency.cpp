// ***************** Travel Management System ***************
#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;
void menu();

class ManageMenu
{
    protected:
        string username; //hide admin name
    public:
        ManageMenu()
        {
            system("color 0A"); //change terminal color
            cout << "\n\n\n\n\n\n\n\n\n\t Enter your Name as Admin: ";
            cin >> username;
            system("CLS");
            menu();
        }
        ~ManageMenu(){}
};

class customers
{
    public:
        string name, gender, address;
        int age, mobileNo;
        static int cusID;
        char all[999];
    
    void detDetails()
    {
        ofstream out("old-customers.txt", ios::app);
        {
            cout << "Enter customerID: ";
            cin >> cusID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter MObile Number: ";
            cin >> mobileNo;
            cout << "Enter Address: ";
            cin >> address; 
        }
        out << "\ncustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << endl;
        out.close();
        cout << "\nSAVED \n NOTE: YOur details saved for future uses.\n" << endl;
    }
    void show()
    {
        ifstream in("old-customers.txt");
        {
            if(!in)
            {
                cout << "File Error... !" << endl;
            }
            while(!in.eof())
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};
int customers::cusID; 
class cab{
    public:
        int cabchoice, dist;
        float cabcost; 
        static float lastcabcost;

        void cab_details(){
            
            cout << "----------------ABC Cabs------------------" << endl;
            cout << "1. Rent a standard cab - RS 15 for 1KM" << endl;
            cout << "2.Rent a Luxury cab - RS 25 per 1km" << endl;

            cout << "\nTo calculate the cost of the journey: " << endl;
            cout << "Enter the cab Choice: ";
            cin >> cabchoice;
            cout << "Enter Km you want to travel: ";
            cin >> dist;

            int hirecab;
            if(cabchoice == 1){
                cabcost = dist * 15;
                cout << "Total cost for the journey : " << cabcost << "Rupees for standard" << endl;
                cout << "Press 1 to hire this One OR ";
                cout << "press 2 for Other One: ";
                cin >> hirecab;
                
                system("CLS");
                if(hirecab == 1){
                    lastcabcost = cabcost;
                    cout << "\n You have successfully hired standard cab" << endl;
                    cout << "Goto Menu and take your receipt" << endl;
                }
                else if(hirecab == 2)
                {
                    cab_details();
                }
                else{
                    cout << "Invalid Input: Redirecting to Menu" << endl;
                    Sleep(999);
                    system("CLS");
                    cab_details();
                }
            }
            else if(cabchoice ==2){
                cabcost = dist * 25;
                cout << "Total cost for the journey : " << cabcost << "Rupees for standard" << endl;
                cout << "Press 1 to hire this One OR ";
                cout << "press 2 for Other One: ";
                cin >> hirecab;
                
                system("CLS");
                if(hirecab == 1){
                    lastcabcost = cabcost;
                    cout << "\n You have successfully hired Luxury cab" << endl;
                    cout << "Goto Menu and take your receipt" << endl;
                }
                else if(hirecab == 2)
                {
                    cab_details();
                }
                else{
                    cout << "Invalid Input: Redirecting to Menu" << endl;
                    Sleep(1100);
                    system("CLS");
                    cab_details();
                }
            }
            else{
                cout << "Invalid Input : Redirecting to Main Menu: " << endl;
                Sleep(1100);
                system("CLS");
                menu();
            }
            cout << "\nPress 1 to Redirect Main menu: ";
            cin >> hirecab;
            system("CLS");
            if(hirecab == 1)
                menu();
            else{  
                menu();
            }
        }
};
float cab ::lastcabcost;

class Booking
{
public:
    int choiceHotel, packchoice;
    static float hotelcost;

    void hotels(){
        string hotelNo[] = {"Avendra", "choiceYou", "ElephantBay"};
        for(int i = 0; i < 3; i++){
            cout << (i+1) << "Hotel" << hotelNo[i] << endl;
        }
        cout << "\n currently we collaborate with above Ones" << endl;
        cout << "\n Press any key to Back OR\nEnter number of the hotel you want to stay or stay: ";
        cin >> choiceHotel;
        system("CLS");

        if(choiceHotel == 1){
            cout << "------------------Welcome To Hotel Avendra--------------" << endl;
            cout << " The Garden, food and beverage. Enjoy all you can drink and stay cool" << endl;
            cout << "Package offered by Avendra:\n" << endl;
            cout << "1. Standard pack : All Basic facilities for just RS 5000.00 " << endl;
            cout << "2. Premium pack : Enjoy premium at RS 10000.00" << endl;
            cout << "3. Luxury pack : At just RS 15000.00 " << endl;
            cout << "\nEnter any other key to Back OR \nEnter the package you want to avail: ";
            cin >> packchoice;

            if(packchoice == 1){
                hotelcost = 5000.00;
                cout << "\nYou have availed standard pack" << endl;
                cout << "Goto Menu and take receipt" << endl;
            }
            else if(packchoice == 2){
                hotelcost = 10000.00;
                cout << "\nYou have availed Premium pack" << endl;
                cout << "Goto Menu and take receipt" << endl;
            }
            else if(packchoice == 3){
                hotelcost = 15000.00;
                cout << "\nYou have availed Luxury pack" << endl;
                cout << "Goto Menu and take receipt" << endl;
            }
            else{
                cout << "Invalid Input : Redirecting to previous menu \n please wait..." << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to redirect main menu: ";
            cin >> gotomenu;
            if(gotomenu == 1){
                menu();
            }
            else{
               menu();
            }

        }
        else if(choiceHotel == 2){
            cout << "------------------Welcome To Hotel Avendra--------------" << endl;
            cout << " The Garden, food and beverage. Enjoy all you can drink and stay cool" << endl;
            cout << "Package offered by Avendra:\n" << endl;
            cout << "1. Standard pack : All Basic facilities for just RS 5000.00 " << endl;
            cout << "2. Premium pack : Enjoy premium at RS 10000.00" << endl;
            cout << "3. Luxury pack : At just RS 15000.00 " << endl;
            cout << "\nEnter any other key to Back OR \nEnter the package you want to avail: ";
            cin >> packchoice;

            if(packchoice == 1){
                hotelcost = 5000.00;
                cout << "\nYou have availed standard pack" << endl;
                cout << "Goto Menu and take receipt" << endl;
            }
            else if(packchoice == 2){
                hotelcost = 10000.00;
                cout << "\nYou have availed Premium pack" << endl;
                cout << "Goto Menu and take receipt" << endl;
            }
            else if(packchoice == 3){
                hotelcost = 15000.00;
                cout << "\nYou have availed Luxury pack" << endl;
                cout << "Goto Menu and take receipt" << endl;
            }
            else{
                cout << "Invalid Input : Redirecting to previous menu \n please wait..." << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to redirect main menu: ";
            cin >> gotomenu;
            if(gotomenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if (choiceHotel == 3){
             cout << "------------------Welcome To Hotel Avendra--------------" << endl;
            cout << " The Garden, food and beverage. Enjoy all you can drink and stay cool" << endl;
            cout << "Package offered by Avendra:\n" << endl;
            cout << "1. Standard pack : All Basic facilities for just RS 5000.00 " << endl;
            cout << "2. Premium pack : Enjoy premium at RS 10000.00" << endl;
            cout << "3. Luxury pack : At just RS 15000.00 " << endl;
            cout << "\nEnter any other key to Back OR \nEnter the package you want to avail: ";
            cin >> packchoice;

            if(packchoice == 1){
                hotelcost = 5000.00;
                cout << "\nYou have availed standard pack" << endl;
                cout << "Goto Menu and take receipt" << endl;
            }
            else if(packchoice == 2){
                hotelcost = 10000.00;
                cout << "\nYou have availed Premium pack" << endl;
                cout << "Goto Menu and take receipt" << endl;
            }
            else if(packchoice == 3){
                hotelcost = 15000.00;
                cout << "\nYou have availed Luxury pack" << endl;
                cout << "Goto Menu and take receipt" << endl;
            }
            else{
                cout << "Invalid Input : Redirecting to previous menu \n please wait..." << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to redirect main menu: ";
            cin >> gotomenu;
            if(gotomenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout << "Invalid Input : Redirecting to previous menu \n please wait..." << endl;
                Sleep(1100);
                system("CLS");
                menu();
        }
        
    }
};
float Booking :: hotelcost;


class charges : public Booking, cab, customers
{
    public:
        void printBill(){
            ofstream outf("receipt,txt");
            {
                outf << "---------ABC Travel Agency---------" << endl;
                outf << "-------------Receipt---------------" << endl;
                outf << "___________________________________" << endl;
                outf << "Customer Id:" << customers::cusID << endl << endl;
                outf << "Description\t\t Total" << endl;
                outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelcost << endl;
                outf << "Cab cost:\t\t " << fixed << setprecision(2) << cab::lastcabcost << endl;
                outf << "_________________________________________" << endl;
                outf << "Total charge:\t\t " << fixed << setprecision(2) << Booking::hotelcost + cab::lastcabcost << endl;
                outf << "____________________________________" << endl;
                outf << "-------------Thank You--------------" << endl;
            }
            outf.close();
        }
        void showBill(){
            ifstream inf("receipt.txt");
            {
                if(!inf){
                    cout << "FIle opening error! " << endl;
                }
                while(!inf.eof()){
                    inf.getline(all, 999);
                    cout << all << endl;
                }
            }
            inf.close();
        }
};
void menu()
{
    int mainchoice, inchoice, gotomenu;
    cout << "\t--------------ABC Travels--------------\n" << endl;
    cout << "\t---------------Main menu--------------" << endl;
    cout <<"\t-------------------------------------------" << endl;
    cout << "\t|\t\t\t\t\t\t\t" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\t Cabs Management    -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges and Bill    -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t\t\t\t" << endl;
    cout << "\t|-----------------------------------------" << endl;

    cout << "\nEnter your choice: ";
    cin >> mainchoice;
    system("CLS");

    customers a2;
    cab a3;
    Booking a4;
    charges a5;

    if(mainchoice == 1){
        cout << "-------Customers------\n" << endl;
        cout << "1. Enter new customer" << endl;
        cout << "2.see old customer" << endl;
        cout << "\n Enter choice";
        cin >> inchoice;
        system("CLS");
        
        if(inchoice == 1){
            a2.detDetails();
        }
        else if(inchoice == 2){
            a2.show();
        }
        else{
            cout << "Invalid Input : Redirecting to previous menu \n please wait..." << endl;
                Sleep(1100);
                system("CLS");
                menu();
        }
        cout << "\nPress 1 to Redirect main menu: ";
        cin >> gotomenu;
        system("CLS");
        if(gotomenu == 1){
            menu();
        }
        else{
            menu();
        }
    }
    else if(mainchoice == 2){
        a3.cab_details();
    }
    else if(mainchoice == 3) {
        cout << "--->Book a Luxury hotel using the system <---" << endl;
        a4.hotels();
    }
    else if(mainchoice == 4){
        cout << "--> Get your Receipt <--" << endl;
        a5.printBill();

        cout << "your receipt is already printed you can get it from fiel path\n" << endl;
        cout << "To display the your receipt in the screen , Enter 1: OR Enter another key to back main Menu:";
        cin >> gotomenu;

        if(gotomenu == 1){
            system("CLS");
            a5.showBill(); 
            cout << "\nPress 1 to Main Menu: ";
            cin >> gotomenu;
            system("CLS");
            if(gotomenu == 1){
                menu();
            }else    
                menu();
        }
    }
    else if(mainchoice == 5){
        cout << "--->VISIT AGAIN<---" << endl;
        Sleep(999);
        system("CLS");
        menu();
    }
    else{
        cout << "Invalid Input : Redirecting to previous menu \n please wait..." << endl;
            Sleep(1100);
            system("CLS");
            menu();
    }
    
}
int main(){
    ManageMenu sys;
    return 0;
}