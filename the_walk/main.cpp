#include <iostream>
#include "Map.h"
#include "Robot1.h"
#include "Robot2.h"
#include "Robot3.h"
#include <stdlib.h>

using namespace std;

int main()
{
    char ch;
    cout << "-----------------------------THE WALK----------------------------------\n";
    cout << "Apasa orice tasta pentru a continua si a ajuta robotul sa ajunga la destinatie.\n";
    cout << "Daca vrei sa iesi apasa 'q' sau 'Q'\n";

    cin >> ch;

    if(ch == 'q' || ch == 'Q')
        return 0;

    else
    {
        cout << "Alege robotul cu care vrei sa joci: (@, #, &)\n";
        cin >> ch;

        Map *start = NULL;

        while(ch != '&' && ch != '@' && ch != '#')
        {
            cout << "Alegere gresita, mai alege inca o data." << "\n";
            cin >> ch;
        }

        if(ch == '@')
            start = new Robot1();

        else
            if(ch == '#')
                start = new Robot2();

            else
                start = new Robot3();

        start->Draw(ch);
    }
    return 0;
}
