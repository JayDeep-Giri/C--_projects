#include"player.h"
#include<random>
#include<ctime>

using namespace std;

//Constructor sets the position as zero
player::player() {
    _x = 0;
    _y = 0;
}

void player::init(int level, int health, int attack, int defence, int experience) {
    _level = level;
    _health = health;
    _attack = attack;
    _defence = defence;
    _experience = experience;
}
int player::attack() {
    static default_random_engine randomEngine(time(NULL));
    uniform_int_distribution<int> attackRoll(0, _attack);

    return attackRoll(randomEngine);
}

//set the position 
void player::setPosition(int x, int y) {
    _x = x;
    _y = y;
}
void player::addExperience(int experience) {
    _experience+=experience;

    while(_experience > 50) {
        printf("Leveled UP...\n");
        _experience -= 50;
        _attack+=10;
        _defence += 5;
        _health += 10;
        _level++;
        system("PAUSE");
    }
}
//Get the position
void player::getPosition(int &x, int &y) {
    x = _x;
    y = _y;
}
int player::takeDamage(int attack) {
    attack-= _defence;
    if(attack > 0) {
        _health-= attack;
        //checking if dead
        if(_health <= 0)
            return 1;
    }
    return 0;
}   