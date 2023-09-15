#include<iostream>
using namespace std;

long double sqrt(long double n) {
    long double x = n/2;

    for(;;) {
        x= 0.5*(x+(n/x));
        cout << x << endl;

        if((x*x)>= n-0.00001 && (x*x)<=n+0.00001)
            break;
    }
    return x;
}

int main() {
    long double n;
    cout << "Enter a No: ";
    cin>>n;

    cout << "\n" <<"Ans: " << sqrt(n);
    return 0;
}