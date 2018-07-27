#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>

using namespace std;

vector<string>      explode(string const& s, char delim)
{
    vector<string>  result;
    istringstream   iss(s);
    string          token;

    while (getline(iss, token, delim))
        result.push_back(move(token));
    return result;
}

string              get_result(string const& line, unsigned int L)
{
    string          result;
    string          prev_nbr;
    unsigned int    compteur;
    vector<string>  line_vector;

    result = "";
    compteur = 1;
    prev_nbr = "0";
    line_vector = explode(line, ' ');

    for (auto curr_nbr : line_vector)
    {
        if (!curr_nbr.compare(prev_nbr))
            compteur++;
        else if (prev_nbr.compare("0"))
        {
            result += to_string(compteur) + " " + prev_nbr + " ";
            compteur = 1;
        }
        prev_nbr = curr_nbr;
    }
    result += to_string(compteur) + " " + prev_nbr + " ";

    if (!--L)
        return result;
    else
        return get_result(result, L);
}

int                 main()
{
    unsigned int    R;
    unsigned int    L;
    string          result;
    string          first_line;

    cin >> R; cin.ignore();
    cin >> L; cin.ignore();
    L--;
    if (!L)
    {
        cout << R << endl;
        return 0;
    }
    result = get_result(to_string(R), L);
    result.pop_back();
    cout << result << endl;
    return 0;
}
