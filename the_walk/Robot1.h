#ifndef ROBOT1_H
#define ROBOT1_H

#include "Map.h"

class Robot1: public Map
{
    //se deplaseaza pe coloana
    int energy; // numarul de pasi pe care il poate face robotul
    bool t2; //verifica daca a ajuns pe capcana 2

    public:
        Robot1();
        int Move();

        void Item1();
        void Item2();
        void Item3();

        void Trap1();
        void Trap2();
        void Trap3();

        void Show();
};

#endif // ROBOT1_H
