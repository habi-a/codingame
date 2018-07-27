#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

bool                sortAscend(int i, int j)
{
    return (i < j);
}

bool                checkTotal(int C, deque<int> const& budget)
{
    unsigned int    sum = 0;

    for (auto x : budget)
    sum += x;
    return (sum >= C);
}

void                spendBudget(deque<int> &budget, int first,
                                const unsigned int pay, int &C)
{
    first -= pay;
    C -= pay;

    if (first < 0)
    {
        C -= first;
        cout << pay + first << endl;
    }
    else
        cout << pay << endl;
    budget.pop_front();
}


int                 main()
{
    int             N;
    int             C;
    deque<int>      budget;

    cin >> N; cin.ignore();
    cin >> C; cin.ignore();
    for (int i = 0; i < N; i++)
    {
        int         B;
        cin >> B; cin.ignore();
        budget.push_back(B);
    }

    if (checkTotal(C, budget))
    {
        sort(budget.begin(), budget.end(), sortAscend);
        for (auto first : budget)
        {
            unsigned int pay = floor(C / budget.size());
            spendBudget(budget, first, pay, C);
        }
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
