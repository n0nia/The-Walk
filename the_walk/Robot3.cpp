#include "Robot3.h"
#include <iostream>

Robot3::Robot3(): energy(91), nr(0), item(false), t2(false), ok(false)
{
    //ctor
}

void Robot3::Move_1()
{
    if(nr%2 == 0 && x < Size - 2)
    {
        x++;
        y++;
    }
    else
        if(x == Size - 2 && nr%2 == 0)
        {
            y--;
            nr++;
        }
        else
            if(nr%2 != 0 && y > 1)
            {
                x--;
                y--;
            }
            else
                if(nr%2 != 0 && y == 1 && x < Size - 2)
                {
                    nr++;
                    x++;
                }

}

void Robot3::Move_2()
{
    if(nr%2 != 0 && y < Size - 2)
    {
        x++;
        y++;
    }
    else
        if(y == Size - 2 && nr%2 != 0)
        {
            x++;
            nr++;
        }
        else
            if(nr%2 == 0 && x > 1)
            {
                x--;
                y--;
            }
            else
                if(nr%2 == 0 && x == 1)
                {
                    nr++;
                    y--;
                }
}

int Robot3::Move()
{
    Check();

    if(map[x][y] == 7)
    {
        std::cout << "\nRobotul a ajuns la destinatie.\n";
        return 0;
    }

    if(energy <= 0)
    {
        std::cout << "\nRobotul a ramas fara energie.\n";
        return 0;
    }

    if(t2 == true)
    {
        std::cout << "\nRobotul a cazut intr-o capcana.\n";
        return 0;
    }

    if(ok == true)
        Move_2();

    if(x == Size - 2 && y == 1)
    {
        if(item == true)
        {
            std::cout << "\nRobotul a ajuns in coltul din dreapta sus si si-a recapatat energia.\n";
            nr++;

            energy = 91;
            y = Size - 2;
            ok = true;
            x = 1;
        }
    }
    else
        if(ok == false)
            Move_1();

    energy --;

    return 1;
}

void Robot3::Item3()
{
    item = true;
    std::cout << "\nRobotul se poate muta in coltul din dreapta sus cu ajutorul obiectului gasit.\n";
}

void Robot3::Item2()
{
    std::cout << "\nObiectul gasit nu a fost compatibil cu robotul.\n";
}

void Robot3::Item1()
{
    std::cout << "\nObiectul gasit nu a fost compatibil cu robotul.\n";
}

void Robot3::Trap1()
{
    //muta robotul cu 5 casute inapoi

    std::cout << "\nRobotul s-a intors cu ";

    if(x <= 5 && y <= 5 && nr == 0)
    {
        std::cout <<  x << " linii si " << y << " coloane.\n";
        y = 0;
        x = 0;
    }

    else
    {
        if(y <= 1 && nr%2 == 0)
        {
            nr--;
            x--;
            y += 4;
            x += 4;
            std::cout << "5 linii si 4 coloane.\n";
        }
        else
            if(y + 5 < Size - 1 && nr%2 != 0)
            {
                y += 5;
                x += 5;
                std::cout << "5 linii si 5 coloane.\n";
            }
            else
                if(y - 5 > 1 && nr%2 == 0)
                {
                    std::cout << "5 linii si 5 coloane.\n";
                    y -= 5;
                    x -= 5;
                }
                else
                {
                    std::cout << "4 linii si 5 coloane.\n";
                    y++;
                    x -= 5;
                    y -= 5;
                    nr--;
                }
        }
}

void Robot3::Trap2()
{
    t2 = true;
}

void Robot3::Trap3()
{
    energy -= 10;
    std::cout << "\nRobotul a pierdut energie.\n";
}

void Robot3::Show()
{
    std::cout << "\nRobotul '&' se afle pe linia " << x << " si coloana " << y << "\n";

	switch (map[x][y])
	{
        case 3:
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
