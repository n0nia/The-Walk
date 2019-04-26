#ifndef ROBOT3_H
#define ROBOT3_H

#include "Map.h"

class Robot3: public Map
{
    //pe coloana
    int energy, nr; // daca nr este par robotul merge in jos daca nu atunci merge in sus
    bool item, t2, ok; //cu ok verific daca robotul a gasit obiectul compatibil si daca a ajuns la capatul hartii
    //item verifica daca a gasit obiectul

    public:
        Robot3();
        int Move();

        void Move_1(); //este folosit pentru prima parte a jocului
        void Move_2(); //este folosit pentru a doua parte a jocului

        void Item1();;
        void Item2();
        void Item3();

        void Trap1();
        void Trap2();
        void Trap3();

        void Show();
};

#endif // ROBOT3_H
