///////////////////////////Hospital Management Sysytem//////////////////
#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<windows.h>

void menu();
void passcode();
void cpasscode();

using namespace std;

class one
{
    public:
        virtual void get() = 0;
        virtual void show()= 0;
};

class info: public one
{
    public:
        char name[50], time[50];
        int num, age;
        void get()
        {
            system("cls");
            cin.sync();
            cout << "\nEnter the patient name = ";
            cin.getline(name, 50);
            cout << "\nEnter the appointment Time: ";
            cin.getline(time, 50);
            cout << "\nEnter Age: ";
            cin >> age;
            cout << "\nEnter Appointment No: ";
            cin >> num;
        }
        void show()
        {
            cout <<"\nName: " << name;
            cout << "\nAge: " << age;
            cout << "\nNumber: " << num;
            cout << "\nTime: " <<time;
        }
        
};
class Raju: public info
{
    public:
        info a1;
        void get()
        {
            system("cls");
            ofstream out("Raju.txt", ios::app|ios::binary);
            a1.get();
            out.write((char*)&a1, sizeof(a1));
            out.close();
            cout << " your Entry has been saved. ";
            getch();
            menu();
        }
        void show()
        {
            ifstream in("Raju.txt");
            if(!in)
            {
                cout << "\n\nNo data in the file. ";
                cout << "\npress any key to continue...";
                getch();
                menu();
            }
            else
            {
                while (!in.eof())
                {
                    in.read((char*)&a1, sizeof(a1));
                    a1.show();
                }
                in.close();
                getch();
                menu();                
            }
        }
};
/////////////////////////// class Dr jayakumar///////////////////
class jaya: public info
{
    public:
        info a1;
        void get()
        {
            system("cls");
            ofstream out("Dr_jaya.txt", ios::app|ios::binary);
            a1.get();
            out.write((char*)&a1, sizeof(a1));
            out.close();
            cout << " your Entry has been saved. ";
            getch();
            menu();
        }
        void show()
        {
            ifstream in("Dr_jaya.txt");
            if(!in)
            {
                cout << "\n\nNo data in the file. ";
                cout << "\npress any key to continue...";
                getch();
                menu();
            }
            else
            {
                while (!in.eof())
                {
                    in.read((char*)&a1, sizeof(a1));
                    a1.show();
                }
                in.close();
                getch();
                menu();                
            }
        }
};
/////////////////////////// class Dr Amir///////////////////////
class Amir: public info
{
    public:
        info a1;
        void get()
        {
            system("cls");
            ofstream out("amir.txt", ios::app|ios::binary);
            a1.get();
            out.write((char*)&a1, sizeof(a1));
            out.close();
            cout << " your Entry has been saved. ";
            getch();
            menu();
        }
        void show()
        {
            ifstream in("amir.txt");
            if(!in)
            {
                cout << "\n\nNo data in the file. ";
                cout << "\npress any key to continue...";
                getch();
                menu();
            }
            else
            {
                while (!in.eof())
                {
                    in.read((char*)&a1, sizeof(a1));
                    a1.show();
                }
                in.close();
                getch();
                menu();                
            }
        }
};

///////////////////////////STAFF class///////////////////////////
class staff: public one
{
    public:
        char all[999];
        char name[50], age[20], sal[30], pos[20];
        void get()
        {            
            ofstream out("staff.txt", ios::app|ios::binary);
            {
                cin.sync();
                cout << "\nEnter Name: ";
                cin.getline(name, 50);
                cout << "\nEnter Age: ";
                cin.getline(age, 20);
                cout << "\nEnter Salary: ";
                cin.getline(sal, 30);
                cout << "\nEnter Working Position: ";
                cin.getline(pos, 20);
            }
            out << "\nName: " << name  << "\nAge: " << age << "\nsalary: " << sal << "\nWorking Position: "
            << pos;
            out.close();
            cout << "\n\nYour information has been saved...\n\t\t\tPress ANY key to continue..";
            getch();
            menu();
        }
        void show()
        {
            ifstream in("staff.txt");
            if(!in)
            {
                system("cls");
                cout << "\n\n\n\t\t\tError...! ";
                Sleep(1000);
                menu();
            }
            while (!in.eof())
            {
                in.getline(all, 999);
                cout << all <<endl;
            }
            in.close();
            cout << "\n\n\t\t\tPress ANY key to continue..";
            getch();
            menu();                
        }
};

////////////////////////// Information Class////////////////////
class information
{
    public:
        void DrInfo()
        {
            system("cls");
            system("color F3");
            cout << "\n==========================================================================\n";
            cout << "\n\n\t\t(Three Doctor Avaiable) \n\n\t\t[Information And Timing Are Given Below]\n";
            cout << "-----------------------------------------------------------------------------\n";
            cout << "\t\t Doctor avcailable: \n";
            cout << "\t\tDr. Jayakumar(skin Specialist)\n\n";
            cout << "\t\t\t[Timing]: \n\n";
            cout << "\tmonday to friday\t\t9AM TO 5PM\n";
            cout << "\tSaturday            \t\t9AM TO 1PM\n";
            cout << "\tsunday              \t\tOff\n";
            cout << "\n-----------------------------------------------------------------------------\n";
            cout << "\t\tDr. Amir (Gut specialist)\n\n";
            cout << "\t\t\t[Timing]: \n\n";
            cout << "\tmonday to friday\t\t9AM TO 5PM\n";
            cout << "\tSaturday            \t\t9AM TO 1PM\n";
            cout << "\tsunday              \t\t12PM TO 7PM\n";
            cout << "\n-----------------------------------------------------------------------------\n";
            cout << "\nPress Any key to continue..";
            getch();
            menu();
        }
};
void call_Dr()
{
    system("cls");
    int choice;
    cout << "\n\n\n\t\tPress 1 for Dr.Raju   \n\n\t\tPress 2 for Dr.Jayakumar  \n\n\t\tPress 3 for Dr.Amir";
    cin >> choice;

    one* ptr;
    Raju s3;
    jaya s4;
    Amir s5;
    
    if(choice == 1)
    {
        ptr = &s3;
        ptr->get();
    }
    if(choice == 2)
    {
        ptr = &s4;
        ptr->get();
    }
    if(choice == 3)
    {
        ptr =&s5;
        ptr->get();
    }
    else{
        cout << "Invalid Choice..";
    }
}
void menu()
{
    system("cls");
    system("color FC");

    cout <<"\n\n";
    cout << "\t\t       | ****************** MAIN MENU ***************** |  \n";
    cout << "\t\t       |         Hospital Management System             | \n";
    cout << "\n-----------------------------------------------------------------------------\n";
    cout << "\t\t              please Select any option                    \n";

    cout << "\n\n\t1-\tPress 1 for Available Doctor Information\n\n";
    cout << "\t2-\tPress 2 for Doctor Appointment\n\n";
    cout << "\t3-\t Press 3 for Saving Staff Information \n\n";
    cout << "\t4-\t Press 4 to check Patient Appointment Menu:\n\n";
    cout << "\t5-\t Press 5 to check staff Information Menu: \n\n";
    cout << "\t6-\t Press 6 to change password or create One:  \n\n";
    cout << "\t7-\t\t[    Press 7 to Logout   ]\n";

    cout << "\n==========================================================================\n";
    cout << "\n\n\t\tPlease Enter your Choice : ";
    information a1;
    one* ptr;
    staff a2;
    int a;
    cin >> a;
    if(a == 1)
    {
        a1.DrInfo();
    }
    else if (a == 2)
    {
        call_Dr();
    }
    else if (a == 3)
    {
        ptr = &a2;
        ptr->get();
    }
    else if (a ==4)
    {
        ptr->get();
        ptr->show();
    }
    else if (a == 5)
    {
        ptr = &a2;
        ptr->show();
    }
    else if (a == 6)
    {
        cpasscode();
    }
    else if (a == 7)
    {
        passcode();
    }
    else{
        cout << "Invalid Choice...";
    }
}
void passcode()
{
    system("cls");
    char p1[50], p2[50], p3[50];

    system("color Fc");
    ifstream in("password.txt");
    {
        cin.sync();
        cout << "\n\n\t\t\tEnter your password:";
        cin.getline(p1, 50);
        in.getline(p2, 50);
        if(strcmp(p2, p1) == 0)
        {
            menu();
        }
        else
        {
            cout << "\n\n\t\t\tIncorrect Password \nTry agaim..!";
            Sleep(999);
            passcode();
        }
    }
    in.close();
}
void cpasscode()
{
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout << "\n\n\n\t\t\tEnter the New password: ";
        cin.getline(n, 50);
        out << n;
    }
    out.close();
    cout << "\n\nYour Password has been Saved : ";
    cout << "\n\n\tPress Any key......";
    getch();
    menu();
}

int main()
{
    passcode();
    return 0;
}