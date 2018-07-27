#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int                         main()
{
    int                     n;
    vector<int>             valuesDiff;
    vector<int>             maxLosses;
    vector<unsigned int>    values;

    cin >> n; cin.ignore();

    for (int i = 0; i < n; i++)
    {
        int                 v;
        cin >> v; cin.ignore();
        values.push_back(v);
    }

    for (unsigned int i = 0; i < values.size() - 1; i++)
        valuesDiff.push_back(values[i + 1] - values[i]);

    maxLosses.push_back(valuesDiff[0]);
    for (unsigned int i = 1; i < valuesDiff.size(); i++)
        maxLosses.push_back(min(valuesDiff[i], (maxLosses[i - 1] + valuesDiff[i])));

    auto pMax = *std::min_element(maxLosses.begin(), maxLosses.end());
    if (pMax > 0)
        pMax = 0;

    cout << pMax << endl;
    return 0;
}
