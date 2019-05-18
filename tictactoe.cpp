#include <iostream>
#include <string>

using namespace std;

bool gameOver;
char board[3][3];
string player1;
string player2;
int colInput1, rowInput1, colInput2, rowInput2;
int curr_player;

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

    cout << "Player 1 [X]: ";
    cin >> player1;

    cout << "Player 2 [O]: ";
    cin >> player2;

    curr_player = 1;
}

void draw()
{
    system("clear");
    for (int i = 0; i < 3; i++)
    {
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
        cout << "Enter Column Number: ";
        cin >> colInput1;
        cout << "Enter Row Number: ";
        cin >> rowInput1;
        curr_player = 2;
    }
    else if (curr_player == 2)
    {
        cout << "Enter Column Number: ";
        cin >> colInput2;
        cout << "Enter Row Number: ";
        cin >> rowInput2;
        curr_player = 1;
    }
}

void logic()
{
    if (curr_player == 2)
    {
        board[colInput1][rowInput1] = 'X';
    }
    else{
        board[colInput2][rowInput2] = 'O';
    }
}

void test()
{
    
}

int main()
{
    setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();
    }
}