#pragma once

class player
{
    public:
        player();
        void init(int level, int health, int attack, int defence, int experience);

        int attack();
        //setters
        void setPosition(int x, int y);

        void addExperience(int experience);

        //Getters
        void getPosition(int &x, int &y);

        int takeDamage(int attack);

    private:
        //properties
        int _level;
        int _health;
        int _attack;
        int _defence;
        int _experience;

        //position
        int _x;
        int _y;
};