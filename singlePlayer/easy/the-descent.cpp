#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int             main()
{
    while (1)
    {
        int     indexHighestMountain = 0;
        int     valueHighestMountain = 0;

        for (int i = 0; i < 8; i++)
        {
            int mountainH;

            cin >> mountainH; cin.ignore();
            if (mountainH > valueHighestMountain)
            {
                valueHighestMountain = mountainH;
                indexHighestMountain = i;
            }
        }

        cout << indexHighestMountain << endl;
    }
    return 0;
}
