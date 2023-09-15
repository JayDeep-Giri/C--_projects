#include <iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
string name[50];
string phoneNo[50];
string MobileNo[50];
string FaxNo[50];
string email[50];
string address[50];
int counter = -1;

int validateContact(string tmpName){
    for(int i = 0; i <= counter; i++){
        if(name[i] == tmpName){
            return 0;
        }
    }
    return 1;
}

void addcontact(){
    string tmpName = "";
    cout << "Enter Name: ";
    cin >> tmpName;
    if(validateContact(tmpName) == 1){
        counter++;
        name[counter] = tmpName;
    }
    else{
        cout << endl << "Contact already Exist with this Name" << endl;
        return;
    }
    cout << "Enter Phone No : ";
    cin >> phoneNo[counter];
    cout << "Enter Mobile No: ";
    cin >> MobileNo[counter];
     cout << "Enter Fax No : ";
    cin >> FaxNo[counter];
    cout << "Enter your Email: ";
    cin >> email[counter];
    cout << "Enter your Address: ";
    cin >> address[counter];
}

void print(int tmpcounter) {
    if(name[tmpcounter] == "")
        return;
    if(counter > -1){
        cout << "Name : " << name[tmpcounter] << endl;
        cout << "Phone No: " << phoneNo[tmpcounter] << endl;
        cout << "Mobile No: " << MobileNo[tmpcounter] << endl;
        cout << "FAX No: " << FaxNo[tmpcounter] << endl;
        cout << "Email : " << email[tmpcounter] << endl;
        cout << "Address : " << address[tmpcounter] << endl;
        cout << "Press Any Key to view Next/ Continue... " << endl << endl;
        getch();
    }
}

void printAll(){
    if(counter > -1){
        for(int i = 0; i <= counter; i++){
            print(i);
        }
    }
}

void updateContact(int tmpcounter) {
    string tmpName = "";
    cout << "Enter Name: ";
    cin >> tmpName;
    if(validateContact(tmpName) ) {
        name[tmpcounter] = tmpName;
    }
    else {
        cout << endl << "Contact Already Exist with this Name " << endl;
        return;
    }
    cout << "Enter PhoneNo : ";
    cin >> phoneNo[tmpcounter];
    cout << "Enter Mobile No: ";
    cin >> MobileNo[tmpcounter];
     cout << "Enter Fax No : ";
    cin >> FaxNo[tmpcounter];
    cout << "Enter your Email: ";
    cin >> email[tmpcounter];
    cout << "Enter your Address: ";
    cin >> address[tmpcounter];

}

void deletecontact(int tmpcounter) {
    name[tmpcounter] = "";
    phoneNo[tmpcounter] = "";
    MobileNo[tmpcounter] ="";
    FaxNo[tmpcounter] = "";
    email[tmpcounter] = "";
    address[tmpcounter] = "";
}
int findcounter() {
    if(counter < 0)
        return -1;

    string tmpName;
    cout << "ENter Name :";
    cin >> tmpName ;
    for(int i = 0; i <= counter; i++) {
        if(name[i] == tmpName){return i;}
    }
    return 1;
}

int main() {
    char op;
    do{
        system("cls");
        cout << "1. Add contact" << endl;
        cout << "2. List Conatct" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Update Contact" << endl;
        cout << "5. Delete Contact" << endl;
        cout << "6. Exit" << endl << endl;
        cout << "Enter Option (1-6): ";
        cin >> op;

        switch(op) {
            case '1':
            {
                addcontact();
                cout << "Contact added Successfuly..." << endl;
                cout << "Press any Key to Counter" ;
                getch();
                break;
            }
            case '2':
            {
                printAll();
                break;
            }
            case '3':
            {
                int tmpcounter = findcounter();
                if(tmpcounter > -1) {
                    print(tmpcounter);
                }
                break;
            }
            case '4':
            {
                int tmpcounter = findcounter();
                if(tmpcounter > -1) {
                    updateContact(tmpcounter);
                }
                break;
            }
            case '5':
            {
                int tmpcounter = findcounter();
                if(tmpcounter > -1) {
                    deletecontact(tmpcounter);
                }
                break;
            }
            case '6':
            {
                continue;
                break;
            }
        }
    }
    while(op != '6');
    return 0;
}