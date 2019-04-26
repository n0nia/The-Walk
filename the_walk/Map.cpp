#include "Map.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

int Map::rounds = 1;

Map::Map(): Size(15), x(1), y(1), nr_traps(0), nr_items(0)
{
    //alocarea dinamica
    map = new int*[Size]{0};
    for(int i = 0; i < Size; i++)
        map[i] = new int[Size]{0};

    MAP = new char*[Size];
    for(int i = 0; i < Size; i++)
        MAP[i] = new char[Size];

    srand((unsigned)time(NULL));
    map[rand() % (Size - 2) + 1][rand() % (Size - 2) + 1] = 1; // obiectul pentru robotul 1
    map[rand() % (Size - 2) + 1][rand() % (Size - 2) + 1] = 2; // obiectul pentru robotul 2
    map[rand() % (Size - 2) + 1][rand() % (Size - 2) + 1] = 3; // obiectul pentru robotul 3

    map[rand() % (Size - 2) + 1][rand() % (Size - 2) + 1] = 4; //capcana 1
    map[rand() % (Size - 2) + 1][rand() % (Size - 2) + 1] = 5; //capacana 2
    map[rand() % (Size - 2) + 1][rand() % (Size - 2) + 1] = 6; //capcana 3

    map[rand() % (Size - 3) + 2][rand() % (Size - 3) + 2] = 7; //locul unde trebuie sa ajunga

}

Map::~Map()
{
    for(int i = 0; i < Size; i++)
        delete[] map[i];
    delete[] map;

    for(int i = 0; i < Size; i++)
        delete[] MAP[i];
    delete[] MAP;
}

int*& Map::operator[](const int &index)const
{
    return map[index];
}

void Map::Check()
{
    switch(map[x][y])
    {
        case 1:
            map[x][y] = 0;
            Item1();
            break;

        case 2:
            map[x][y] = 0;
            Item2();
            break;

        case 3:
            map[x][y] = 0;
            Item3();
            break;

        case 4:
            map[x][y] = 0;
            Trap1();
            break;

        case 5:
            map[x][y] = 0;
            Trap2();
            break;

        case 6:
            map[x][y] = 0;
            Trap3();
            break;
    }

}

void Map::Create(char choice)
{
    for(int i = 1; i < Size; i++)
    {
        MAP[0][i] = '-';
        MAP[Size-1][i] = '-';

        MAP[i][0] = '|';
        MAP[i][Size-1] = '|';

        for(int j = 1; j < Size-1; j++)
            switch(map[i][j])
            {
                case 1:
                    MAP[i][j] = '+';
                    break;

                case 2:
                    MAP[i][j] = '*';
                    break;

                case 3:
                    MAP[i][j] = '^';
                    break;

                case 4:
                    MAP[i][j] = '=';
                    break;

                case 5:
                    MAP[i][j] = '_';
                    break;

                case 6:
                    MAP[i][j] = '/';
                    break;

                case 7:
                    MAP[i][j] = 'A';
                    break;

                default:
                    MAP[i][j] = '.';
                }
    }

    for(int i = 0; i < Size; i++)
        MAP[Size-1][i]= '-';
}

//controleaza jocul
void Map::Draw(char choice)
{
    int ok;
    do{

        Create(choice);

        //a, b, c, d ajuta la afisarea a 4 pozitii fata de pozitia curenta a robotului
        int a = x + 5, b = y + 5, c = x - 4, d = y - 4;

        //verifica sa nu depaseasca limitele hartii
        if(a > Size)
            a = Size;
        if(b > Size)
            b = Size;

        if(x - 4 < 0)
            c = 0;
        if(y - 4 < 0)
            d = 0;

        cout << "\n";
        for(int i = c; i < a; i++)
        {
            for(int j = d; j < b; j++)
            {
                if(i == x && j == y)
                    MAP[i][j] = choice;

                cout << MAP[i][j];
            }
            cout << "\n";
        }

        Show();

        //oprirea simularii rundelor la stadiul curent
        char yn;
        do
        {
            cout << "\nContinuati?(d/n)\n";
            cin >> yn;
            if(yn == 'd' || yn =='n')
                break;
            cout << "Alegere gresita,  mai alege inca o data.";
        }while(yn != 'd' && yn != 'n');

        ok = Move();


    }while(ok == 1);
}
