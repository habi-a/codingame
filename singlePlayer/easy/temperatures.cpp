#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int         main()
{
    int     n;
    int     closestNumber = 5527;

    cin >> n; cin.ignore();

    for (int i = 0; i < n; i++)
    {
        int t;

        cin >> t; cin.ignore();
        if (abs(closestNumber) > abs(t))
            closestNumber = t;
        else if (abs(closestNumber) == abs(t) && t > closestNumber)
            closestNumber = t;
    }

    if (closestNumber == 5527)
        closestNumber = 0;

    cout << closestNumber << endl;
    return 0;
}
