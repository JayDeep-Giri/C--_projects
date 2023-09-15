#include<iostream>

using namespace std;
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player ='X';
int n;

void Draw() {
    system("cls");
    for(int i = 0; i<3; i++) {
        for(int j = 0; j <3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void input() 
{
    int a;
    cout << "It's " << player << " turn.\n" << "Press the number of the field: ";
    cin >> a;

    if(a==1)
    {
        if(matrix[0][0] == '1')
            matrix[0][0] = player;
        else{
            cout << "Operation failed....Already filled!" << endl;
            input();
        }
    }
    else if(a==2)
    {
        if(matrix[0][1] == '2')
            matrix[0][1]= player;
        else{
            cout << "Operation failed....Already filled!" << endl;
            input();
        }
    }
    else if(a==3)
    {
        if(matrix[0][2] == '3')
            matrix[0][2] = player;
        else{
            cout << "Operation failed....Already filled!" << endl;
            input();
        }
    }
    else if(a==4)
    {
        if(matrix[1][0] == '4')
            matrix[1][0]= player;
        else{
            cout << "Operation failed....Already filled!" << endl;
            input();
        }
    }
    else if(a==5)
    {
        if(matrix[1][1] == '5')
            matrix[1][1]= player;
        else{
            cout << "Operation failed....Already filled!" << endl;
            input();
        }
    }    
    else if(a==6)
    {
        if(matrix[1][2] == '6')
            matrix[1][2]= player;
        else{
            cout << "Operation failed....Already filled!" << endl;
            input();
        }
    }
    else if(a==7)
    {
        if(matrix[2][0] == '7')
            matrix[2][0]= player;
        else{
            cout << "Operation failed....Already filled!" << endl;
            input();
        }
    }
    else if(a==8)
    {
        if(matrix[2][1] == '8')
            matrix[2][1]= player;
        else{
            cout << "Operation failed....Already filled!" << endl;
            input();
        }
    }
    else if(a==9)
    {
        if(matrix[2][2] == '9')
            matrix[2][2]= player;
        else{
            cout << "Operation failed....Already filled!" << endl;
            input();
        }
    }
}
void Toggleplayer() {
    if(player == 'X') 
        player = '0';
    else
        player = 'X';
}
char win() 
{
    // First Player
    if(matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
    return 'X';
    if(matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
    return 'X';
    if(matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
    return 'X';

    if(matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
    return 'X';
    if(matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
    return 'X';
    if(matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
    return 'X';

    if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
    return 'X';
    if(matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
    return 'X';

    //Second Player
    if(matrix[0][0] == '0' && matrix[0][1] == '0' && matrix[0][2] == '0')
    return '0';
    if(matrix[1][0] == '0' && matrix[1][1] == '0' && matrix[1][2] == '0')
    return '0';
    if(matrix[2][0] == '0' && matrix[2][1] == '0' && matrix[2][2] == '0')
    return '0';

    if(matrix[0][0] == '0' && matrix[1][0] == '0' && matrix[2][0] == '0')
    return '0';
    if(matrix[0][1] == '0' && matrix[1][1] == '0' && matrix[2][1] == '0')
    return '0';
    if(matrix[0][2] == '0' && matrix[1][2] == '0' && matrix[2][2] == '0')
    return '0';

    if(matrix[0][0] == '0' && matrix[1][1] == '0' && matrix[2][2] == '0')
    return '0';
    if(matrix[0][2] == '0' && matrix[1][1] == '0' && matrix[2][0] == '0')
    return '0';

    return '/';
}
int main() {

    n = 0;
    Draw();
    while(1) 
    {
        n++;
        input();
        Draw();
        if(win() == 'X'){
            cout << "X Wins..." <<endl;
            break;
        }
        else if (win() == '0') {
            cout << "0 Wins..." << endl;
            break;
        }
        else if(win() == '/' && n == 9) {
            cout << "It's a Draw..." <<endl;
            break;
        }
        Toggleplayer();
    }
    system("pause");
    
    return 0;
}