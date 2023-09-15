#include<iostream>
#include<string>
#include<random>
#include<ctime>

using namespace std;

int main() {
    default_random_engine randomGenerator(time(0));
    uniform_int_distribution <int> diceroll(1,6);

    cout << "Your dice no: " << diceroll(randomGenerator) << endl;
    
    system("PAUSE");
    return 0;

}