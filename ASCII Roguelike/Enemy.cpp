#include"Enemy.h"
#include<string>
#include<random>
#include<ctime>

Enemy::Enemy(string name, char tile, int level, int attack, int defence, int health, int xp) {
    _name = name;
    _tile = tile;
    _level = level;
    _attack = attack;
    _defence = defence;
    _health = health;
    _experienceValue = xp;
}
//set the position 
void Enemy::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

//Get the position
void Enemy::getPosition(int &x, int &y) {
    x = _x;
    y = _y;
}
int Enemy::attack() {
    static default_random_engine randomEngine(time(NULL));
    uniform_int_distribution<int> attackRoll(0, _attack);

    return attackRoll(randomEngine);
}
int Enemy::takeDamage(int attack) {
    attack-= _defence;
    if(attack > 0) {
        _health-= attack;
        //checking if dead
        if(_health <= 0)
            return _experienceValue;
    }
}
char Enemy::getMove(int playerX, int playerY) {
    static default_random_engine randEngine(time(NULL));
    uniform_int_distribution<int> moveRoll(0, 6);
    int dis;
    int dx = _x - playerX;
    int dy = _y - playerY;
    int adx = abs(dx);
    int ady = abs(dy);
    dis =adx + ady;

    if(dis < 5) {
        //Moving along X-axis
        if(adx > ady) {
            if(dx > 0) {
                return 'd';
            }else { 
            return 'a';
            }
        } else { // Move along Y-axis
            if(dy > 0) {
                return 's';
            } else {
                return 'w';
            }
        }
    }
    int randmove = moveRoll(randEngine);
    switch(randmove) {
        case 0:
            return 'a';
        case 1:
            return 'w';
        case 3:
            return 's';
        case 4:
            return 'd';
        default:
            return '.';
    }
}