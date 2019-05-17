#include <iostream>

using namespace std;

bool gameOver;
char board[3][3];

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

void draw()
{

}

void input()
{

}

void logic()
{

}

void test()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j< 3; j++)
        {
            cout << "[" << board[i][j] << "]";
        }
        cout << endl;
    }
}

int main()
{
    setup();
    test();
   /* setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();
    }*/
}