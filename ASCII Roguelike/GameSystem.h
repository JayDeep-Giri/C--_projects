#pragma once
#include"level.h"
#include"player.h"
#include"Enemy.h"
#include<string>

using namespace std;

class GameSystem
{
    public:
        GameSystem(string levelFileName);

        void playGame();
        void playerMove();

    private:
        Level _level;
        player _player;
        vector<Enemy> _enemies;
};