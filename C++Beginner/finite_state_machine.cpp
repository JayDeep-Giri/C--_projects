#include <iostream>
#include <string.h>
                
using namespace std;

enum VendingMachineState{
    SELECT, QUANTITY, CALCULATE, UPDATE
};

enum Brand{
    COKE = 100, PEPSI = 200, SEVENUP = 300
};

struct student{
    string name;
    int points;
};
struct Soda{
    Brand brandName;
    int inventory;
    int price;
};


int main(){
    //Initial vending machine state is SELECT. UPdate upon state change
    VendingMachineState currentState = SELECT;

    //Fill up our vending machine with soda.
    Soda vendingMachine[3];
    //stocking with COKE
    vendingMachine[0].brandName = COKE;
    vendingMachine[0].inventory = 10;
    vendingMachine[0].price = 1000;
    //stocking up with PEPSI
    vendingMachine[1].brandName = PEPSI;
    vendingMachine[1].inventory = 10;
    vendingMachine[1].price = 2000;
    //stocking up with SEVENUP
    vendingMachine[2].brandName = SEVENUP;
    vendingMachine[2].inventory = 10;    
    vendingMachine[2].price = 3000;    

    Soda selectedSoda;
    student eric;
    eric.name = "Aman";
    eric.points = 10000; // points in the wallet
    
    while(true) {
        switch (currentState){
            case SELECT:
                //Display current status of vending machine and the student's wallet.
                cout <<"^^^^^<<<<--CURRENT STATUS-->>>>^^^^^" << endl;
                cout <<" [[[VendinG MAchine]]]" << endl << endl;
                for(int i= 0; i<3; i++){
                    cout << vendingMachine[i].brandName << " has " << vendingMachine[i].inventory 
                    << " drinks and each costs " << vendingMachine[i].price << " points." << endl;
                }
                cout << endl <<"  [[[student]]]" << endl;
                cout << eric.name << " has " << eric.points << " points in total."<< endl;
                cout << "^^^^^<<<<--END STATUS-->>>>^^^^^" << endl << endl;
                //2. Ask the user what drink they want.
                cout << "please select your drink___" << endl;
                //3. Display the soda names and corresponding ID values.
                cout << "COKE = 100 \nPEPSI = 200\nSEVENUP = 300" << endl;
                //4. User inputs the drink.
                int selectedDrink;
                cin >> selectedDrink;
                //4. If valid drink selected, move to QUANTITY state; else go back to SELECT state.
                switch(selectedDrink){
                    case COKE:
                        cout << "you have selected COKE " << endl;
                        selectedSoda.brandName = COKE;
                        currentState = QUANTITY;
                        break;
                    case PEPSI:
                        cout << "you have selected PEPSI" << endl;
                        selectedSoda.brandName = PEPSI;
                        currentState = QUANTITY;
                        break;
                    case SEVENUP:    
                        cout << "you have selected SEVENUP" << endl;
                        selectedSoda.brandName = SEVENUP;
                        currentState = QUANTITY;
                        break;
                    default:
                        cout << " Invalid selection" << endl;
                        currentState = SELECT;
                        break;
                }
                break;
            case QUANTITY:
                cout << "How many drinks would you like? ";
                int orderQuantity;
                cin >> orderQuantity;
                cout << "your order has been received. Your order is -> "<< orderQuantity << " soda(s)." << endl;

                switch (selectedSoda.brandName){
                    case COKE:
                        if (orderQuantity < 0 || orderQuantity > vendingMachine[0].inventory){
                            cout << "Not enough in Stock" << endl;
                            currentState = SELECT;
                            cout << endl << endl;
                        }
                        else{
                            currentState = CALCULATE;
                        }
                        break;
                    case PEPSI:
                        if (orderQuantity < 0 || orderQuantity > vendingMachine[1].inventory){
                            cout << "Not enough in Stock" << endl;
                            currentState = SELECT;
                            cout << endl << endl;
                        }
                        else{
                            currentState = CALCULATE;
                        }
                        break;
                    case SEVENUP:
                        if (orderQuantity < 0 || orderQuantity > vendingMachine[2].inventory){
                            cout << "Not enough in Stock" << endl;
                            currentState = SELECT;
                            cout << endl << endl;
                        }
                        else{
                            currentState = CALCULATE;
                        }
                        break;
                    default:
                        cout << " Invalid Amount Received." << endl;
                        break;
                }
                break;
            case CALCULATE:
                cout << "The total cost of your soda is: ";
                int cost;
                switch (selectedSoda.brandName){
                    case COKE:
                        cost = vendingMachine[0].price * orderQuantity;
                        cout<< cost << endl;
                        break;
                    case PEPSI:
                        cost = vendingMachine[1].price * orderQuantity;
                        cout<< cost << endl;
                        break;
                    case SEVENUP:
                        cost = vendingMachine[2].price * orderQuantity;
                        cout<< cost << endl;
                        break;
                    default:
                        cout << "ERROR! ";
                        break;        
                }       
                int payment;
                cout << "Please type your payment: ";
                cin >> payment;

                if (payment > eric.points || payment < cost || payment <= 0) {
                    cout << "You are less with the money!" << endl;
                    currentState = SELECT;
                    cout << endl << endl;
                }
                else {
                    eric.points = eric.points - payment;
                    int change = payment - cost;
                    cout << "Thank you! Your change is " << change << " points." << endl;
                    eric.points = eric.points + change;
                    currentState = UPDATE;
                }
                break;
            case UPDATE:

                switch (selectedSoda.brandName) {
                    case COKE:
                        vendingMachine[0].inventory = vendingMachine[0].inventory - orderQuantity;
                        currentState = SELECT;
                        cout << endl << endl;
                        break;
                    case PEPSI:
                        vendingMachine[1].inventory = vendingMachine[1].inventory - orderQuantity;
                        currentState = SELECT;
                        cout << endl << endl;
                        break;
                    case SEVENUP:
                        vendingMachine[2].inventory = vendingMachine[2].inventory - orderQuantity;
                        currentState = SELECT;
                        cout << endl << endl;
                        break;
                    default:
                        cout << "Error" << endl;
                        currentState = SELECT;
                        cout << endl << endl;
                        break; 
                }

                cout << "Inventory Updated" << endl;
                currentState = SELECT;
                cout<< endl << endl;

                break;
            default:
                cout<<"Error!! Please enter valid data." << endl;
                break;
        }
    }
 return 0;
}
