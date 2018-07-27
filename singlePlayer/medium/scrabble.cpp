#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool                stringHas(const char letter, string &LETTERS)
{
    unsigned int    tmp_size = LETTERS.size();

    for (unsigned int i = 0; i < tmp_size; i++)
        if (LETTERS[i] == letter)
        {
            LETTERS.erase(LETTERS.begin() + i);
            return true;
        }

    return false;
}

vector<string>      filterDictionary(vector<string> const& dictionary, string const& LETTERS)
{
    bool            is_bad_word;
    vector<string>  good_dictionary;

    for (auto word : dictionary)
    {
        string tmp_letters = LETTERS;
        is_bad_word = false;

        for (auto letter : word)
            if (!stringHas(letter, tmp_letters))
            {
                is_bad_word = true;
                break;
            }

        if (!is_bad_word)
            good_dictionary.push_back(word);
    }
    return good_dictionary;
}

unsigned int        calculScore(string const& word)
{
    unsigned int    score = 0;
    string          one_point = "eaionrtlsu";
    string          two_points = "dg";
    string          three_points = "bcmp";
    string          four_points = "fhvwy";
    string          five_points = "k";
    string          eight_points = "jx";
    string          ten_points = "qz";

    for (auto letter : word)
    {
        if (stringHas(letter, one_point))
            score += 1;
        else if (stringHas(letter, two_points))
            score += 2;
        else if (stringHas(letter, three_points))
            score += 3;
        else if (stringHas(letter, four_points))
            score += 4;
        else if (stringHas(letter, five_points))
            score += 5;
        else if (stringHas(letter, eight_points))
            score += 8;
        else if (stringHas(letter, ten_points))
            score += 10;
    }
    return score;
}

string              chooseBestWord(vector<string> const& dictionary)
{
    string          best_word;
    unsigned int    score_max = 0;

    for (auto word : dictionary)
    {
        auto score = calculScore(word);

        if (score > score_max)
        {
            score_max = score;
            best_word = word;
        }
    }
    return best_word;
}

int                 main()
{
    int             N;
    vector<string>  dictionary;
    string          LETTERS;

    cin >> N; cin.ignore();
    dictionary.reserve(N);

    for (int i = 0; i < N; i++)
    {
        string W;
        getline(cin, W);
        dictionary.push_back(W);
    }
    getline(cin, LETTERS);
    dictionary = filterDictionary(dictionary, LETTERS);
    cout << chooseBestWord(dictionary) << endl;
    return 0;
}
