#pragma once
#include<string>

using namespace std;

class Enemy
{
    public:
        Enemy(string name, char tile, int level, int attack, int defence, int health, int xp);

         //setters
        void setPosition(int x, int y);
        char getTile() { return _tile; };

        //Getters
        void getPosition(int &x, int &y);

        int attack();
        int takeDamage(int attack);

        // Get AI move command
        char getMove(int playerX, int playerY);

    private:
        string _name;
        char _tile;

        int _level;
        int _attack;
        int _defence;
        int _health;
        int _experienceValue;

        //position
        int _x;
        int _y;

};