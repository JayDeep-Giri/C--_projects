#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<ctime>

#define WRONGTRIES 5

using namespace std;

void  DrawMan(int tries)
{
    cout << endl << endl;
    cout << " --------" << endl;
    cout << " |      |" << endl;
    cout << " |";  if(tries >= 1)  cout << "      o    "; cout << endl;
    cout << " |";  if(tries >= 3)  cout << "     /|\\   "; cout << endl;
    cout << " |";  if(tries >= 5)  cout << "     / \\   "; cout << endl;
    cout << " |" << endl;
    cout << "_|_" << endl;
}

int main()
{
    srand(time(NULL));
    string worldList[5] = {"apple", "Peach", "banana", "Strawberry", "Mango"};
    string word;
    string guessed;

    word = worldList[rand()%5];
    int wordlength = word.length();
    string dispword(wordlength,'_');

    int found = 0;
    char guess =' ';
    int tries = 5;
    int flagfound = 0;

    while(tries >= 0){
        system("cls");
        cout << "Guess Fruit NAme : " << endl << endl;

        for(int i = 0; i < wordlength; i++)
            cout << " " << dispword[i] << " ";
        cout << endl << endl << endl;

        cout << "Wrong Attempts: " << tries << " / " << WRONGTRIES << endl;
        cout << "Guessed Letters: " << guessed << endl;

        DrawMan(tries);

        if(found == wordlength){
            cout << endl;
            cout << "************************" << endl;
            cout << "*        You Win       *" << endl;
            cout << "************************" << endl;
            break;
        }

        if(tries == 0) break;

        cout << "Pick a Letter : ";
        guess = getch();

        guessed = guessed + " " + guess;

        if(dispword.find(guess)!= string :: npos) tries++;

        flagfound = 0;
        for (int i = 0; i < wordlength; i++)
        {
            if(word[i] == guess && dispword[i] == '_'){
                dispword[i] =guess;
                found++;
                flagfound =1;
            }
        }
        if(!flagfound)
            tries--;
    }
    if(found != wordlength){
        cout << endl;
        cout << "************************" << endl;
        cout << "*        You Lose      *" << endl;
        cout << "************************" << endl;
    }

    getch();
    return 0;
}