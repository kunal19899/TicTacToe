#include <iostream>
#include <string>

///error made:
////        -colInputs are row inouts
////        -rowInputs are column inputs

using namespace std;

bool gameOver;
char board[3][3];
string player1;
string player2;
int colInput1, rowInput1, colInput2, rowInput2, tempCol, tempRow;
int curr_player;
int gameMode = -1;


int main_menu()
{
    system("clear");
    cout << "TIC-TAC-TOE Game" << endl << endl << "Choose Game Mode" << endl << endl << "1. Single Player" << endl << "2. MultiPlayer" << endl << "3. Options" << endl;
    cout << endl << "Which Mode: ";
    cin >> gameMode;
    if (gameMode > 3)
    {
        return 0;
    }

    return gameMode;
}

void setup()
{
    gameOver = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

/////Draw the game board////
void draw()
{
    system("clear");
    cout << "Column:" << " 1  2  3" << endl; 
    for (int i = 0; i < 3; i++)
    {
        cout << "Row " << i+1 << ": ";
        for (int j = 0; j< 3; j++)
        {
            cout << "[" << board[i][j] << "]";
        }
        cout << endl;
    }
}

void input()
{
    if (curr_player == 1)
    {
        cout << "Enter Row Number: ";
        cin >> colInput1;
        tempCol = colInput1;
        cout << "Enter Column Number: ";
        cin >> rowInput1;
        tempRow = rowInput1;
        curr_player = 2;
    }
    else if (curr_player == 2)
    {
        cout << "Enter Row Number: ";
        cin >> colInput2;
        tempCol = colInput2;
        cout << "Enter Column Number: ";
        cin >> rowInput2;
        tempRow = rowInput2;
        curr_player = 1;
    }
}

void single_input()
{
    if (curr_player == 1)
    {
        cout << "Enter Row Number: ";
        cin >> colInput1;
        tempCol = colInput1;
        cout << "Enter Column Number: ";
        cin >> rowInput1;
        tempRow = rowInput1;
        curr_player = 2;
    }
    else{
        colInput2 = rand()%3;
        tempCol = colInput2;
        rowInput2 = rand()%3;
        tempRow = rowInput2;
        curr_player = 1;
    }
}

bool rowCrossed()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return true;
        }
    }
    return false;
}

bool colCrossed()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return true;
        }
    }
    return false;
}

bool diagCrossed()
{
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' '))
    {
        return true;
    }
    else{
        return false;
    }
}

void logic()
{
    if (curr_player == 2)
    {
        board[colInput1-1][rowInput1-1] = 'X';
    }
    else{
        board[colInput2-1][rowInput2-1] = 'O';
    }

    if (rowCrossed() || colCrossed() || diagCrossed())
    {
        gameOver = true;
    }
}

bool error_check()
{
    ////check for input out of bounds
    if (colInput1 > 3  || colInput2 > 3 || rowInput1 > 3 || rowInput2 > 3)
    {
        cout << "Cell Out of Bounds" << endl;
        //sleep(3);                                         //////check how to use function 
        if (curr_player == 1)
            curr_player = 2;
        else{curr_player = 1;}
        return true;
    }

    if (board[tempCol-1][tempRow-1] != ' ')
    {
        cout << "Cell already in use" << endl;
        //sleep(3);                                         //////check how to use function 
        if (curr_player == 1)
            curr_player = 2;
        else{curr_player = 1;}
        return true;
    }

    return false;
}

int main()
{
    while (gameMode != 0)
    {
        setup();
        main_menu();
        if (gameMode == 1)
        {
            system("clear");
            cout << "Player Name [X]: ";
            cin >> player1;

            curr_player = 1;

            while(!gameOver)
            {
                draw();
                single_input();
                if (error_check())
                {
                    continue;
                }
                logic();
            }
        }
        else if (gameMode == 2) {
            system("clear");
            cout << "Player 1 [X]: ";
            cin >> player1;
        
            ///error checking here for player 1 inpout format
        
        
            ///////
        
            cout << "Player 2 [O]: ";
            cin >> player2;
        
            //error checking here for player 2 input format
        
        
        
            /////
        
            curr_player = 1;
            
                /////Game Loop//////
            while(!gameOver)
            {
                draw();
                input();
                if(error_check())
                {
                    continue;
                }
                logic();
            }
            
            
            ////Winner Announcement/////
            system("clear");
            draw();
            cout << "Winner is ";
            if (curr_player == 2)
            {
                cout << player1 << endl;
            }
            else{
                cout << player2 <<endl;
            }
            cout << "Enter <ANY LETTER> to continue...";
            char enter;
            cin >> enter;
        }
        /*else if (gameMode == 3)
        {

        }*/
    }
    
}