#include"GameSystem.h"
#include<conio.h>

//Game setup
GameSystem::GameSystem(string levelFileName) {

    _player.init(1, 100, 10, 10, 0);

    _level.load(levelFileName, _player, _enemies);
    _level.print();

    system("PAUSE");
}
void GameSystem::playGame() {
    bool isDone = false;

    while(isDone !=true) {
        _level.print();
        playerMove();
        _level.updateEnemies(_player);
    }
}
void GameSystem::playerMove() {
    char input;
    printf("Enter a move Command (w/a/s/d): ");
    input = _getch();

    _level.movePlayer(input, _player);
}
