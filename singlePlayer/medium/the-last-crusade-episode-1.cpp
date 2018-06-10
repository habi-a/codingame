#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <utility>

using namespace std;

vector<string> explode(string const& s, char delim)
{
  vector<string> result;
  istringstream iss(s);
  string token;

  while (getline(iss, token, delim))
    result.push_back(move(token));

  return result;
}

void fillSolver(map<string, string> solver[])
{
  solver[1]["TOP"] = "BOTTOM";
  solver[1]["LEFT"] = "BOTTOM";
  solver[1]["RIGHT"] = "BOTTOM";

  solver[2]["LEFT"] = "RIGHT";
  solver[2]["RIGHT"] = "LEFT";

  solver[3]["TOP"] = "BOTTOM";

  solver[4]["TOP"] = "LEFT";
  solver[4]["RIGHT"] = "BOTTOM";

  solver[5]["TOP"] = "RIGHT";
  solver[5]["LEFT"] = "BOTTOM";

  solver[6]["LEFT"] = "RIGHT";
  solver[6]["RIGHT"] = "LEFT";

  solver[7]["TOP"] = "BOTTOM";
  solver[7]["RIGHT"] = "BOTTOM";

  solver[8]["LEFT"] = "BOTTOM";
  solver[8]["RIGHT"] = "BOTTOM";

  solver[9]["TOP"] = "BOTTOM";
  solver[9]["LEFT"] = "BOTTOM";

  solver[10]["TOP"] = "LEFT";

  solver[11]["TOP"] = "RIGHT";

  solver[12]["RIGHT"] = "BOTTOM";

  solver[13]["LEFT"] = "BOTTOM";
}

int main()
{
  int W; // number of columns.
  int H; // number of rows.
  cin >> W >> H; cin.ignore();
  vector<int> carte[H];
  map<string, string> solver[14];
  for (int i = 0; i < H; i++) {
    string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
    getline(cin, LINE);
    auto v = explode(LINE, ' ');
    for (auto x : v)
      carte[i].push_back(stoi(x));
  }
  int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
  cin >> EX; cin.ignore();

  fillSolver(solver);

  // game loop
  while (1) {
    int XI;
    int YI;
    string POS;
    cin >> XI >> YI >> POS; cin.ignore();

    auto direction = solver[carte[YI][XI]][POS];
    if (direction == "LEFT")
      XI--;
    else if (direction == "RIGHT")
      XI++;
    else if (direction == "BOTTOM")
      YI++;

    cout << to_string(XI) + " " + to_string(YI) << endl;
  }
}
