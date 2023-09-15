#include"sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main()
{
    int ** puzzle;
    int progres;
    Sudoku * sudoku;
    puzzle = createPuzzle();
    sudoku = setUpPuzzle(puzzle);
    printPuzzle(sudoku->squares);
    while(UNSOLVED > 0)
    {
        progres = checkPuzzle(sudoku->squares, sudoku->boxes);
        if(progres == 0)
        {
            cout << " Failed/..";
            break;
        }
    }

    printf("\n\n");

    printPuzzle(sudoku->squares);

    return 0;
}