#ifndef MAP_H
#define MAP_H


class Map
{
    protected:
        int **map;
        char **MAP; //harta creata
        int x, y; // x, y sunt coordonatele robotului
        const int Size; // dimensiunea hartii
        static int rounds; //numarul de runde
        int nr_traps, nr_items; //numarul de capcane, obiecte

    public:
        Map();

        int*& operator[](const int &)const;

        virtual int Move() = 0; //ajuta robotul sa se miste si va opri jocul cand functia returneaza 0

        //obiectele
        virtual void Item1() = 0;
        virtual void Item2() = 0;
        virtual void Item3() = 0;

        //capcanele
        virtual void Trap1() = 0;
        virtual void Trap2() = 0;
        virtual void Trap3() = 0;

        //afiseaza ce modificari au fost facute la harta
        virtual void Show() = 0;

        //verifica pe ce casuta e robotul si daca trebuie facute modificari
        void Check();

        //creeaza harta de char-uri in functie de cea cu int
        void Create(char);

        //afiseaza harta si controleaza rundele
        void Draw(char);

        virtual ~Map();
};

#endif // MAP_H
