#include "Robot1.h"
#include <iostream>

Robot1::Robot1(): energy(200), t2(false)
{
    //ctor
}

int Robot1::Move()
{

    Check();

    //verifica daca a ajuns la destinatie
    if(map[x][y] == 7)
    {
        std::cout << "\nRobotul a ajuns la destinatie.\n";
        return 0;
    }

    //daca a ajuns la capcana 2 atunci jocul se opreste
    if(t2 == true)
    {
        std::cout << "\nRobotul a cazut intr-o capcana.\n";
        return 0;
    }

    //verifica energia
    if(energy <= 0)
    {
        std::cout << "\nRobotul a ramas fara energie.\n";
        return 0;
    }

    //pe coloana impara se va deplasa in jos
    if(y % 2)
    {
        if(x < Size - 2)
            x++;
        else
            y++;
    }

    //pe coloana para se va deplasa in sus
    else
    {
        if(x > 1)
            x--;
        else
            y++;
    }

    energy--;
    return 1;
}

void Robot1::Item1()
{
    //pe coloana impara muta robotul cu 3 casute mai jos
    std::cout << "\nRobotul a avansat cu 3 casute.\n";
    if(y % 2)
    {
        if(x + 3 <= Size - 2)
            x +=3;
        else
        {
            y++;
            x += 3;
            int i = Size - 2 - x + 1;
            x += i;
        }
    }

    //pe coloana para muta robotul cu 3 casute mai sus
    else
    {
        if(x - 3 >= 1)
            x -= 3;
        else
        {
            y++;
            x -= 3;
            int i = x - Size - 2;
            x -= i;
        }
    }
}

void Robot1::Item2()
{
    std::cout << "\nObiectul gasit nu a fost compatibil cu robotul.\n";
}

void Robot1::Item3()
{
    std::cout << "\nObiectul gasit nu a fost compatibil cu robotul.\n";
}

void Robot1::Trap1()
{
    //muta robotul cu 5 casute inapoi
    map[x][y] = 0;

    std::cout << "\nRobotul s-a intors cu ";

    if(y == 1 && x <= 5)
    {
        std::cout << x << " linii.\n";
        x = 0;
    }
    else
    {
        if(x > 5 && y%2 != 0)
        {
            std::cout << "5 linii.\n";
            x -= 5;
        }
        else
            if(x <= 5 && y%2 != 0)
            {
                y--;
                x += 5;
                std::cout << "5 linii si o coloana.\n";
            }
            else
                if(x + 5 < Size - 1 && y%2 == 0)
                {
                    x += 5;
                    std::cout << "5 linii.\n";
                }
                else
                {
                    y--;
                    x -= 5;
                    std::cout << "5 linii si o coloana.\n";
                }
    }
}

void Robot1::Trap2()
{
    t2 = true;
}

void Robot1::Trap3()
{
    energy -= 10;
    std::cout << "\nRobotul a pierdut energie.\n";
}

void Robot1::Show()
{
    std::cout << "\nRobotul '@' se afla pe linia " << x << " si coloana " << y << "\n";

	switch (map[x][y])
	{
        case 1:
            nr_items++;
            break;

        case 4:
            nr_traps++;
            break;

        case 5:
            nr_traps++;
            break;

		case 6:
            nr_traps++;
            break;
	}

	std::cout << "Obiecte gasite: " << nr_items << "\n";
	std::cout << "Capcane gasite: " << nr_traps << "\n";
	std::cout << "Energie ramasa: " << energy << "\n";
	std::cout << "Runda numarul: " << rounds++ << "\n";
}
