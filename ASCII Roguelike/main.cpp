#include<iostream>
#include<cstdlib>
#include<string>
#include<conio.h>

#include"GameSystem.h"

using namespace std;

int main() {
    
    GameSystem gamesystem("level1.txt");
    gamesystem.playGame();

    return 0;
}