#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include <math.h>
#include <string>
#include <time.h>
#include <windows.h>
const int X = 10;
const int Y = 10;
const int hcode = 206;
using namespace std;
struct hero
{
    char code; // alt + 206 => in windows
    int posx;
    int posy;
    int vidas;
};

void init(char world[][Y], struct hero &link)
{
    int i, j;

    link.code = hcode;
    link.posx = X - 1;
    link.posy = 5;
    link.vidas = 3;

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            world[i][j] = ' ';
        }
    }
    world[link.posx][link.posy] = link.code;
}

void paint(char world[][Y])
{
    int i, j;

    cout << endl
         << endl;

    for (i = 0; i < X; i++)
    {
        cout << "\t";
        for (j = 0; j < Y; j++)
        {
            cout << world[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    cout << "\t";
    cout << "SPACE INVADERS by Enupal";
}

void refreshWorld(char world[][Y], struct hero link)
{
    world[link.posx][link.posy] = link.code;
}

void move(char key, char world[][Y], struct hero &link)
{
    // Review the ascii table
    if (key == char(75)) // ascci code for Left
    {
        if (link.posy > 0)
        {
            link.code = ' ';
            refreshWorld(world, link);
            link.code = hcode;
            link.posy--; // link.posy = link.posy -1
            refreshWorld(world, link);
        }
    }
    if (key == char(77)) // ascci code for Left
    {
        if (link.posy < X - 1)
        {
            link.code = ' ';
            refreshWorld(world, link);
            link.code = hcode;
            link.posy++; // link.posy = link.posy +1
            refreshWorld(world, link);
        }
    }
}

void timer(char world[][Y], struct hero link)
{
    char key; // keydown
    int step = 0;

    while (1) // paint all the time
    {
        paint(world);
        if (_kbhit()) // listen when a key is down
        {
            key = _getch(); // save the ascii code
            move(key, world, link);
        }

        Sleep(1000);
        system("cls"); // clean the screen
    }
}

int main()
{
    char world[X][Y];
    struct hero link;

    init(world, link);
    timer(world, link);

    _getch();

    return 0;
}