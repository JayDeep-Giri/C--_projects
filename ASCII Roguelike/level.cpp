#include"level.h"
#include<fstream>
#include<iostream>
#include<cstdio>

Level::Level() {

}
void Level::load(string fileName, player &player, vector<Enemy> &_enemies) {
    //Loads the level

    ifstream file;
    file.open(fileName);
    if(file.fail()) {
        perror(fileName.c_str());
        system("PAUSE");
        exit(1);
    }
    string line;
    while(getline(file, line)) {
        _levelData.push_back(line);
    }
    file.close();

    //Processes the table
    char tile;
    for(int i =0; i< _levelData.size(); i++) {
        for(int j =0; j < _levelData[i].size(); j++) {
            tile = _levelData[i][j];

            switch(tile) {
                case '@'://pl
                    player.setPosition(j,i);
                    break;
                case 's': //snake
                    _enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 10));
                    _enemies.back().setPosition(j,i);
                    break;
                case 'g':
                    _enemies.push_back(Enemy("Goblin", tile, 2, 5, 5, 35, 50));
                    _enemies.back().setPosition(j,i);
                    break;
                case 'o':
                    _enemies.push_back(Enemy("Ogre", tile, 4, 3, 5, 100, 70));
                    _enemies.back().setPosition(j,i);
                    break;
                case 'D':
                    _enemies.push_back(Enemy("Dragon", tile, 100, 50, 45, 90, 900));
                    _enemies.back().setPosition(j,i);
                    break;
            }
        }
    }
}
void Level::print() {

    cout << string(100,'\n');
    for(int i = 0; i<_levelData.size(); i++) {
        printf("%s\n",_levelData[i]);
    }
    printf("\n");
}
void Level::movePlayer(char input, player &player) {
    
    int playerX;
    int playerY;
    player.getPosition(playerX, playerY);

    char moveTile;
    switch(input) {
        case 'w': //up
        case 'W':
            processPlayerMove(player, playerX, playerY-1);
            break;
        case 's': //down
        case 'S':
            processPlayerMove(player,playerX, playerY+1);
            break;
        case 'a': // left
        case 'A':
            processPlayerMove(player, playerX-1, playerY);
            break;
        case 'd':
        case 'D':
            processPlayerMove(player, playerX+1, playerY);
            break;
        default:
            printf("INVALID INPUT : \n");
            system("PAUSE");
            break;
    }
}
void Level::updateEnemies(player &player) {
    char aiMove;
    int playerX;
    int playerY;
    int enemyX;
    int enemyY;

    player.getPosition(playerX, playerY);

    for(int i = 0; i < _enemies.size(); i++) {
        aiMove = _enemies[i].getMove(playerX, playerY);
        _enemies[i].getPosition(enemyX, enemyY);
        switch(aiMove) {
        case 'w': //up
            processEnemyMove(player, i, enemyX, enemyY-1);
            break;
        case 's': //down
            processEnemyMove(player, i, enemyX, enemyY+1);
            break;
        case 'a': // left
            processEnemyMove(player, i, enemyX-1, enemyY);
            break;
        case 'd':
            processEnemyMove(player, i, enemyX+1, enemyY);
            break;
        }
    }
}
char Level::getTile(int x, int y) {
    return _levelData[y][x];
}
void Level::seTile(int x, int y, char tile) {
    _levelData[y][x] = tile;
}
void Level::processPlayerMove(player &player, int targetX, int targetY) {
    int playerX;
    int PlayerY;
    player.getPosition(targetX, targetY);
    char moveTile = getTile(targetX, targetY);

    switch(moveTile) {
        case '.':
            player.setPosition(targetX, targetY);
            seTile(targetX, targetY, '.');
            seTile(targetX, targetY, '@');
            break;
        case '#':
            break;
        default:
            battlemonster(player, targetX, targetY);
            break;
    }   
}
void Level:: processEnemyMove(player &player, int enemyIndex, int targetX, int targetY) {
    int playerX;
    int PlayerY;
    int enemyX;
    int enemyY;

    _enemies[enemyIndex].getPosition(enemyX, enemyY);
    player.getPosition(targetX, targetY);
    
    char moveTile = getTile(targetX, targetY);

    switch(moveTile) {
        case '.':
            _enemies[enemyIndex].setPosition(targetX, targetY);
            seTile(targetX, targetY, '.');
            seTile(targetX, targetY, _enemies[enemyIndex].getTile());
            break;
        case '@':
            battlemonster(player, enemyX, enemyY);
            break;
        default:
            break;
    }
}
void Level::battlemonster(player &player, int targetX, int targetY) {
    int attackRoll;
    int enemyX;
    int enemyY;
    int playerX;
    int playerY;
    int attackResult;

    player.getPosition(playerX, playerY);

    for(int i=0; i < _enemies.size(); i++) {
        _enemies[i].getPosition(enemyX, enemyY);

        if(targetX == enemyX && targetY == enemyY) {
            //Battle..
            attackRoll = player.attack();
            attackResult = _enemies[i].takeDamage(attackRoll);

            if(attackResult != 0) {
                seTile(targetX, targetY, '.');
                print();
                printf("Monster died");

                //Remove the enemy
                _enemies[i] = _enemies.back();
                _enemies.pop_back();
                i--;

                system("PAUSE");
                player.addExperience(attackResult);
            }
            //MOnster's turn
            attackRoll = _enemies[i].attack();
            attackResult = player.takeDamage(attackRoll);

            if(attackResult != 0) {
                seTile(playerX, playerY, 'X');
                print();
                printf("You Dead...");
                system("PAUSE");
                
                exit(0);
            }
            system("PAUSE");
            return;
        }
    }
}