#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int             main()
{
    int         lightX;
    int         lightY;
    int         initialTX;
    int         initialTY;

    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    while (1)
    {
        int     remainingTurns;
        string  direction = "";
        
        cin >> remainingTurns; cin.ignore();

        if (initialTY > lightY)
        {
            initialTY--;
            direction = "N";
        }
        else if (initialTY < lightY)
        {
            initialTY++;
            direction = "S";
        }

        if (initialTX > lightX)
        {
            initialTX--;
            direction += "W";
        }
        else if (initialTX < lightX)
        {
            initialTX++;
            direction += "E";
        }

        cout << direction << endl;
    }
    return 0;
}
