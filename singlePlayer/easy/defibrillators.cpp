#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Defibrilateur
{
public:
  Defibrilateur(string index, string name, string adresse, string LON, string LAT)
  {
    _index = index;
    _name = name;
    _adresse = adresse;
    _LON = LON;
    _LAT = LAT;
  }
  string _index;
  string _name;
  string _adresse;
  string _LON;
  string _LAT;
};

vector<string> explode(string const& s, char delim)
{
  vector<std::string> result;
  istringstream iss(s);

  for (string token; getline(iss, token, delim); ) {
      result.push_back(move(token));
  }
  return result;
}

void str_replace(string& s, char from, char to)
{
  for (unsigned int i = 0; i < s.size(); i++) {
      if (s[i] == from)
	s[i] = to;
  }
}

double degreeToRadian(double d)
{
  d = d * 3.14159265358979323846 / 180.0;
  return d;
}

int main()
{
  unsigned int indexBest;
  vector<Defibrilateur*> defibrilateurs;
  string LON;
  cin >> LON; cin.ignore();
  string LAT;
  cin >> LAT; cin.ignore();
  int N;
  cin >> N; cin.ignore();
  for (int i = 0; i < N; i++) {
    string DEFIB;
    getline(cin, DEFIB);
    auto v = explode(DEFIB, ';');
    defibrilateurs.push_back(new Defibrilateur(to_string(i), v[1], v[2], v[4], v[5]));
    str_replace(defibrilateurs[i]->_LON, ',', '.');
    str_replace(defibrilateurs[i]->_LAT, ',', '.');
  }
  str_replace(LON, ',', '.');
  str_replace(LAT, ',', '.');

  // Main Loop
  indexBest = 0;
  auto x = (degreeToRadian(stod(defibrilateurs[0]->_LON)) - degreeToRadian(stod(LON))) * cos((degreeToRadian(stod(LAT)) + degreeToRadian(stod(defibrilateurs[0]->_LAT))) / 2);
  auto y = degreeToRadian(stod(defibrilateurs[0]->_LAT)) - degreeToRadian(stod(LAT));
  auto dmin = sqrt(x * x + y * y) * 6371;
  for (unsigned int i = 1; i < defibrilateurs.size(); i++) {
      x = (degreeToRadian(stod(defibrilateurs[i]->_LON)) - degreeToRadian(stod(LON))) * cos((degreeToRadian(stod(LAT)) + degreeToRadian(stod(defibrilateurs[i]->_LAT))) / 2);
      y = degreeToRadian(stod(defibrilateurs[i]->_LAT)) - degreeToRadian(stod(LAT));
      auto d = sqrt(x * x + y * y) * 6371;
      if (d <= dmin) {
	  dmin = d;
	  indexBest = stoi(defibrilateurs[i]->_index);
      }
  }

  cout << defibrilateurs[indexBest]->_name << endl;
}
