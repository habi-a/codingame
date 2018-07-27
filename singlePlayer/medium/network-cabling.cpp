#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template            <typename It>
auto                median(It begin, It end)
{
    using           T = typename iterator_traits<It>::value_type;
    vector<T>       data(begin, end);

    nth_element(data.begin(), data.begin() + data.size() / 2, data.end());
    return data[data.size() / 2];
}

bool                minComparator(int i, int j)
{
    return (i < j);
}

void                addLink(vector<int> y_range, auto median_y,
                        long long int &length)
{
    for (auto y : y_range)
        length += abs(y - median_y);
}

int                 main()
{
    unsigned int    N;
    long long int   length = 0;
    vector<int>     x_range;
    vector<int>     y_range;

    cin >> N; cin.ignore();
    x_range.reserve(N);
    y_range.reserve(N);

    for (unsigned int i = 0; i < N; i++)
    {
        int         X;
        int         Y;

        cin >> X >> Y; cin.ignore();
        x_range.push_back(X);
        y_range.push_back(Y);
    }

    if (x_range.size() > 1)
        length = abs(*min_element(x_range.begin(), x_range.end()) - *max_element(x_range.begin(), x_range.end()));

    auto median_y = median(y_range.begin(), y_range.end());
    addLink(y_range, median_y, length);
    cout << length << endl;
    return 0;
}
