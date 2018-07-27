#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctgmath>

using namespace std;

bool            hasDirection(string bombDir, char Letter)
{
    for (unsigned int i = 0; i < bombDir.size(); i++)
        if (bombDir[i] == Letter)
            return true;
    return false;
}

int             main()
{
    int         W; // width of the building.
    int         H; // height of the building.
    int         N; // maximum number of turns before game over.
    int         X0;
    int         Y0;
    vector<int> eliminatedX;
    vector<int> eliminatedY;

    cin >> W >> H; cin.ignore();
    cin >> N; cin.ignore();
    cin >> X0 >> Y0; cin.ignore();

    while (1)
    {
        string  bombDir;

        cin >> bombDir; cin.ignore();
        if (hasDirection(bombDir, 'L'))
            for (unsigned int i = W - 1; i >= X0; i--)
                eliminatedX.push_back(i);
        else if (hasDirection(bombDir, 'R'))
            for (unsigned int i = 0; i <= X0; i++)
                eliminatedX.push_back(i);
        if (hasDirection(bombDir, 'U'))
            for (unsigned int i = H - 1; i >= Y0; i--)
                eliminatedY.push_back(i);
        else if (hasDirection(bombDir, 'D'))
            for (unsigned int i = 0; i <= Y0; i++)
                eliminatedY.push_back(i);

        sort(eliminatedX.begin(), eliminatedX.end());
        eliminatedX.erase(unique(eliminatedX.begin(), eliminatedX.end()), eliminatedX.end());

        sort(eliminatedY.begin(), eliminatedY.end());
        eliminatedY.erase(unique(eliminatedY.begin(), eliminatedY.end() ), eliminatedY.end());

        auto    moveRL = ceil((float)(W - eliminatedX.size()) / 2);
        auto    moveDU = ceil((float)(H - eliminatedY.size()) / 2);

        if (hasDirection(bombDir, 'L'))
        {
            while (X0 - moveRL < 0)
                moveRL--;
            X0 -= moveRL;
        }
        else if (hasDirection(bombDir, 'R'))
        {
            while (X0 + moveRL >= W)
                moveRL--;
            X0 += moveRL;
        }
        if (hasDirection(bombDir, 'U'))
        {
            while (Y0 - moveDU < 0)
                moveDU--;
            Y0 -= moveDU;
        }
        else if (hasDirection(bombDir, 'D'))
        {
            while (Y0 + moveDU >= H)
                moveDU--;
            Y0 += moveDU;
        }

        cout << to_string(X0) + " " + to_string(Y0) << endl;
        return 0;
    }
}
