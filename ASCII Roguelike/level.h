#pragma once
#include<vector>
#include"player.h"
#include"Enemy.h"

using namespace std;

class Level
{
private:
    vector <string> _levelData;
    vector <Enemy> _enemies;
    void processPlayerMove(player &player, int targetX, int targetY);
    void processEnemyMove(player &player, int enemyIndex, int targetX, int targetY);
    void battlemonster(player &player, int targetX, int targetY);
public:
    Level();
    void load(string fileName, player &player, vector<Enemy> &_enemies); 
    void print();   

    void movePlayer(char input, player &player);
    void updateEnemies(player &player);
    char getTile(int x, int y);
    void seTile(int x, int y, char tile);
};

