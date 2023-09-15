#include"sudoku.h"

int checkRows(Square *** sudoku, Box ** boxes)
{
    int i, j, x;
    int sum[9];
    int place[9];

    for(i =0; i < 9; i++)
    {
        for(j =0; j<9; j++)
            sum[j] = 0;

        for(j = 0; j < 9; j++)
        {
            if(sudoku[i][j] != 0)
            {
                continue;
            }
            for(x = 0; x<9; x++)
            {
                if(sudoku[i][j]->possible[x] == 0)
                {
                    sum[x]++;
                    place[x] = j;
                }
            }
        }
        for(x = 0; x < 9; x++)
        {
            if(sum[x] == 1 )
            {
                sudoku[i][place[x]]->number = x + 1;
                sudoku[i][place[x]]->solvable = 0;
                UNSOLVED--;

                updateSudoku(sudoku, i, place[x]);
                updateBoxes(sudoku, i, place[x]);

                return 1;
            }
        }
    }
    return 0;
}
Sudoku *createSudoku(Square *** squares, Box ** boxes)
{
    Sudoku * sudoku;
    sudoku = (Sudoku *)malloc(sizeof(Sudoku));

    sudoku->squares = squares;
    sudoku->boxes = boxes;

    return sudoku;

}
Sudoku * setUpPuzzle(int ** puzzle)
{
    Square *** sudoku;
    Box ** boxes;
    int i, j, x;
    int currentBox = 0;

    sudoku = (Square***) malloc(sizeof(Square**)*9);
    boxes = createBoxes();

    // loop through rows and columns
    for(i = 0; i < SIZE_ROWS; i++){

        sudoku[i] = (Square**) malloc(sizeof(Square*)*9);

        for(j = 0; j < SIZE_COLUMNS; j++)
        {
            sudoku[i][j] = (Square*) malloc(sizeof(Square)*9);
            sudoku[i][j] ->number = puzzle[i][j];
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
            sudoku[i][j]->solvable = 9;

            boxes[currentBox]->squares[ boxes[currentBox]->numbers ] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            for(int x = 0; x < SIZE_ROWS; x++)
            {
                sudoku[i][j]->possible[x] = 0;
            }
            if(j == 2)
            {
                currentBox++;
            }
            if(j ==5)
                currentBox++;
        
        }
        currentBox -= 2;
        if(i == 2)
            currentBox = 3;
        if(i == 5)
            currentBox = 6;

    }
    for(i = 0; i < SIZE_ROWS; i++){

        for(j = 0; j < SIZE_COLUMNS; j++)
        {
            if(sudoku[i][j]->number != 0)
            {
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }
    return createSudoku(sudoku, boxes);
}

int updateSudoku(Square *** sudoku, int row, int column)
{
    int x;
    int number = sudoku[row][column]->number;

    for(x = 0; x < SIZE_ROWS; x++)
    {
        if(sudoku[x][column]->possible[number - 1] == 0)
        {
            sudoku[x][column]->solvable--;
        }
        sudoku[x][column]->possible[number - 1] = 1;
    }
}

int checkPuzzle(Square *** sudoku, Box ** boxes)
{
    int i, j, x;

    for(i = 0; i < SIZE_ROWS; i++){

        for(j = 0; j < SIZE_COLUMNS; j++)
        {
            if(sudoku[i][j]->solvable == 1)
            {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
            }
        }
    }
     if( boxSingles(sudoku, boxes))
        return 1;

    return checkRows(sudoku, boxes);
}
int ** createPuzzle()
{
    int ** puzzle;
    int i, j;
    int array[9][9] = {0, 1, 9,     0, 0, 2,        0, 0, 0,
                       4, 7, 0,     6, 9, 0,        0, 0, 1,
                       0, 0, 0,     4, 0, 0,        0, 9, 0,
                       
                       8, 9, 4,     5, 0, 7,        0, 0, 0,
                       0, 0, 0,     0, 0, 0,        0, 0, 0,
                       0, 0, 0,     2, 0, 1,        9, 5, 8,
                       
                       0, 5, 0,     0, 0, 6,        0, 0, 0,
                       6, 0, 0,     0, 2, 8,        0, 7, 9,
                       0, 0, 0,     1, 0, 0,        8, 6, 0,};

    puzzle = new int*[sizeof(int**)*9];

    for(i = 0; i < 9; i++){
        puzzle[i] = new int[sizeof(int)*9];

        for(j = 0; j < 9; j++)
        {
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}
void printPuzzle(int** puzzle){
    int i, j;
    for(i = 0; i < SIZE_ROWS; i++)
    {
        // print each row
        cout << "-----------------------------------\n";
        for(j = 0; j < SIZE_COLUMNS; j++)
        {
            cout << " " << puzzle[i][j];

            if(((j + 1)% 3) == 0)
            {
                cout <<"|";
            }
        }
        cout << "\n";
        if(((i + 1)% 3) == 0){
            cout << "----------------------------------";
        }
    }
}
