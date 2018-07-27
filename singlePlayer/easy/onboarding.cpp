#include <iostream>

using namespace std;

int             main()
{
    while (1)
    {
        int     dist1;
        int     dist2;
        string  enemy1;
        string  enemy2;

        cin >> enemy1; cin.ignore();
        cin >> dist1; cin.ignore();
        cin >> enemy2; cin.ignore();
        cin >> dist2; cin.ignore();

        if (dist1 < dist2)
            cout << enemy1 << endl;
        else
            cout << enemy2 << endl;
    }
}
