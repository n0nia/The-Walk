#ifndef ROBOT2_H
#define ROBOT2_H

#include "Map.h"

class Robot2: public Map
{
    //se deplaseaza pe linie
    int energy, nr; //daca
    bool t2;
    public:
        Robot2();
        int Move();

        void Item1();
        void Item2();
        void Item3();

        void Trap1();
        void Trap2();
        void Trap3();

        void Show();
};

#endif // ROBOT2_H
