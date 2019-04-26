#include "Robot2.h"
#include <iostream>

Robot2::Robot2(): energy(150), nr(0), t2(false)
{
    //ctor
}

int Robot2::Move()
{
    Check();

    if(map[x][y] == 7)
    {
        std::cout << "\nRobotul a ajuns la destinatie.\n";
        return 0;
    }

    if(t2 == true)
    {
        std::cout << "\nRobotul a cazut intr-o capcana.\n";
        return 0;
    }

    if(energy <= 0)
    {
        std::cout << "\nRobotul a ramas fara energie.\n";
        return 0;
    }

    //pe coloana impara robotul se deplaseaza spre dreapta
    if(x % 2)
    {
        if(y < Size - 2)
            y++;
        else
            x++;
    }

    //pe coloana para robotul se deplaseaza spre stanga
    else
    {
        if(y > 1)
            y--;
        else
            x++;
    }

    energy--;

    return 1;
}

void Robot2::Item2()
{
    nr += 2;
    std::cout << "\nRobotul este imun la urmatoarele 2 capcane cu ajutorul obiectului gasit.\n";
}

void Robot2::Item1()
{
    std::cout << "\nObiectul gasit nu a fost compatibil cu robotul.\n";
}

void Robot2::Item3()
{
    std::cout << "\nObiectul gasit nu a fost compatibil cu robotul.\n";
}

void Robot2::Trap1()
{
    //muta robotul cu 5 casute inapoi

    if(nr)
    {
        std::cout << "\nRobotul a evitat capcana.\n\n";
        nr--;
    }
    else
    {
        std::cout << "\nRobotul s-a intors cu ";
        if(x == 1 && y <= 5)
        {
            std::cout << y << " coloane.\n";
            y = 0;
        }

        else
        {
            if(y > 5 && x%2 != 0)
            {
                y -= 5;
                std::cout << "5 coloane.\n";
            }
            else
                if(y <= 5 && x%2 != 0)
                {
                    x--;
                    y += 5;
                    std::cout << "5 coloane si o linie.\n";
                }
                else
                    if(y + 5 < Size - 1 && x%2 == 0)
                    {
                        std::cout << "5 coloane.\n";
                        y += 5;
                    }
                    else
                    {
                        std::cout << "5 coloane si o linie.\n";
                        x--;
                        y -= 5;
                    }
        }
    }
}

void Robot2::Trap2()
{
    if(nr)
    {
        nr--;
        std::cout << "\nRobotul a sarit peste capcana.\n";
    }
    else
        t2 = true;
}

void Robot2::Trap3()
{
    if(nr)
    {
        nr--;
        std::cout << "\nRobotul a evitat capana.\n";
    }
    else
    {
        energy -= 10;
        std::cout << "\nRobotul a pierdut energie.\n";
    }
}

void Robot2::Show()
{
    std::cout << "\nRobotul '#' se afla pe linia " << x << " si coloana " << y << "\n";

	switch (map[x][y])
	{
        case 2:
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
