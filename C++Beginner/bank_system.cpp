#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

class Bank{
    private:
        int total;
        string id;
        struct person{
            string name, ID, address;
            int contact, cash;            
        }person[100];
    public:
        Bank(){
            total = 0;
        }
        void choice();
        void perData();
        void show();
        void update();
        void search();
        void transaction();
        void del();
};
int main(){
    Bank b;
    b.choice();
    return 0;
}
void Bank :: choice(){
    int ch;
    while(1){
        cout << "\n\n Press ..." << endl;
        cout << "1. Create new account" << endl;
        cout << "2. View customers list" << endl;
        cout << "3. Update information of existing account" << endl;
        cout << "4. Check the details of an existing account" << endl;
        cout << "5. For transactions" << endl;
        cout << "6. Remove existing account" << endl;
        cout << "7. Exit" << endl;
        
        cin >> ch;
        system("cls");

        switch(ch){
            case 1:
                Bank :: perData();
                break;
            case 2:
                if(total == 0){
                    cout << "No Data to view. " << endl;
                }
                else{
                    Bank :: show();
                }
                break;
            case 3:
                if(total == 0){
                    cout << "No Data to update. " << endl;
                }
                else{
                    Bank :: update();
                }
                break;
            case 4:
                if(total == 0){
                    cout << "No Data to check. " << endl;
                }
                else{
                    Bank :: search();
                }
                break;
            case 5:
                if(total == 0){
                    cout << "No Data to view. " << endl;
                }
                else{
                    Bank :: transaction();
                }
                break;
            case 6:
                if(total == 0){
                    cout << "No Data to view. " << endl;
                }
                else{
                    Bank :: del();
                }
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "Invalid Input";
                break;
        }
    }
}
void Bank :: perData(){
    cout << "Enter data of person " << total+1 << endl;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, person[total].name);
    cout << "ID: ";
    getline(cin, person[total].ID);
    cout << "Address: ";
    getline(cin, person[total].address);
    cout << "Contact: ";
    cin >> person[total].contact;
    cout << "Total Cash: ";
    cin >> person[total].cash;
    total++;
}
void Bank :: show(){
    for(int i = 0; i < total; i++){
        cout << "Data of person " << i+1 << endl;
        cout << "Name: " << person[i].name << endl;
        cout << "ID: " << person[i].ID << endl;
        cout << "Address: " << person[i].address << endl;
        cout << "contact: " << person[i].contact << endl;
        cout << "cash: " << person[i].cash << endl << endl;
    }
}
void Bank :: update(){
    cout << "Enter id of the student: ";
    cin >> id;
    for(int i = 0; i < total; i++){
        if(id == person[i].ID){
            cout << "Data of " << i+1 << endl;
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "contact: " << person[i].contact << endl;
            cout << "cash: " << person[i].cash << endl;

            cout << "\nEnter new Data" << endl;
            cout << "Enter Name: ";
            
            getline(cin, person[i].name);
            cout << "ID: ";
            getline(cin, person[i].ID);
            cout << "Address: ";
            getline(cin, person[i].name);
            cout << "Contact: ";
            cin >> person[i].contact;
            cout << "Total Cash: ";
            cin >> person[i].cash; 
            break;
        }
        if(i == total -1){
            cout << "No such Record Found" << endl;
        }
    }
}
void Bank ::search(){
    cout << "Enter id of the student for searching: ";
    cin >> id;
    for(int i = 0; i < total; i++){
        if(id == person[i].ID){
            cout << "Data of " << i+1 << endl;
        cout << "Name: " << person[i].name << endl;
        cout << "ID: " << person[i].ID << endl;
        cout << "Address: " << person[i].address << endl;
        cout << "contact: " << person[i].contact << endl;
        cout << "cash: " << person[i].cash << endl;
        break;
        }            
    if(i == total -1){
            cout << "No such Record Found" << endl;
        }
    }
}
void Bank :: transaction(){
    int ch;
    int cash;
    cout << "Enter id of student : ";
    cin >> id;
    for(int i = 0; i < total; i++){
        if(id == person[i].ID){
            cout << "Name: " << person[i].name << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "contact: " << person[i].contact << endl;
            cout << "\nExisting_cash: " << person[i].cash << endl;
            cout << "Press 1 to Deposit" << endl;
            cout << "Press 2 to Withdraw " << endl;
            cin >> ch;
            switch(ch){
                case 1:
                    cout << " Enter the amount to deposit_->" << endl;
                    cin >> cash;
                    person[i].cash += cash;
                    cout << "New Amount in your account_->" << person[i].cash << endl;
                    break;
                case 2:
                    back:
                    cout << "Enter the amount to withdraw_->" << endl;
                    cin >> cash;
                    if(cash > person[i].cash){
                        cout << "Your existing amount is deficient in your account " << endl;
                        Sleep(2000);
                        goto back;
                    }
                    person[i].cash -= cash;
                    cout << "Available Balance _-> " << person[i].cash << endl;
                    break;
                default:
                    cout << "Invalid Input "  << endl;
                    break;
            }
            break;
        }
    
        if(i == total -1){
            cout << "No such Record Found" << endl;
            }
    }
}
void Bank :: del(){
    int ch;
    cout << "Press 1 to remove specific record" << endl;
    cout << "Press 2 to remove full record" << endl;
    cin >> ch;
    switch(ch){
        case 1:
            cout << "Enter Id of the student to remove: " ;
            cin >> id;
            for (int i = 0; i < total; i++){
                if (id == person[i].ID){
                    for( int j = i; j < total; j++){
                        person[j].name = person[j+1].name;
                        person[j].ID = person[i+j].ID;
                        person[j].address = person[i+j].address;
                        person[j].contact = person[i+j].contact;
                        person[j].cash = person[i+j].cash;
                    }
                    total--;
                    cout << "\nAccount has been removed...";
                    break;                        
                }
                if(i == total-1){
                    cout << "NO such record found";
                }
            }
            break;
            case 2:
                total = 0;
                cout << "All record is deleted" << endl;
                break;
            default:
                cout << "Invalid Input";
                break;
    }
}