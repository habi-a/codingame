#include <vector>
#include <algorithm>

using namespace std;

bool                croissant(int i, int j)
{
    return(i < j);
}

int                 main()
{
    int             N;
    vector<int>     listPower;
    unsigned int    diffMin = 9999;

    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++)
    {
        int         Pi;
        
        cin >> Pi; cin.ignore();
        listPower.push_back(Pi);
    }

    sort(listPower.begin(), listPower.end(), croissant);

    for (unsigned int i = 0; i < listPower.size(); i++)
        if (abs(listPower[i] - listPower[i + 1]) < diffMin)
            diffMin = abs(listPower[i] - listPower[i + 1]);

    cout << diffMin << endl;
    return 0;
}
