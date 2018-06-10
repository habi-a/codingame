#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void printMaya(vector<string> const& maya)
{
  for (auto line : maya)
    cout << line << endl;
}

void printMayaDebug(vector<string> const& maya)
{
  for (auto line : maya)
    cerr << line << endl;
}

bool compareMaya(vector<string> const &maya, vector<string> const& tmpMaya, unsigned int firstIndex, unsigned int lastIndex)
{
  bool isEqual = true;
  unsigned int j = 0;

  for (unsigned int i = firstIndex; i < lastIndex; i++)
    {
      if (maya[i] != tmpMaya[j])
	isEqual = false;
      j++;
    }
  return isEqual;
}

void splitBase(unsigned long long int resultInt, vector<unsigned long long int> &resultsInt, int power, bool begin)
{
  if (resultInt >= pow(20, power))
    {
      unsigned long long int push = floor(resultInt / pow(20, power));
      resultInt -= (pow(20, power) * push);
      resultsInt.push_back(push);
      begin = false;
    }
  else if (!begin)
    resultsInt.push_back(0);

  power--;

  if (power >= 0)
    splitBase(resultInt, resultsInt, power, begin);
}

vector<string> intToMaya(unsigned long long int number, vector<string> const& motif, int L, int H)
{
  vector<string> maya;
  maya.resize(H);
  for (unsigned int j = 0; j < motif.size(); j++)
    for (unsigned int i = L * number; i < L * (number + 1); i++)
      maya[j].push_back(motif[j][i]);
  return maya;
}

unsigned long long int mayaToInt(vector<string> const& maya, vector<string>const& motif, int L, int H)
{
  unsigned long long int result;
  unsigned long long int multiplicator;
  vector<unsigned int> values;
  vector<unsigned int> possibleValue;
  unsigned int mayaInt;
  string tmp;

  for (unsigned int j = 0; j < maya.size(); j += H)
    {
      mayaInt = 0;
      for (unsigned int i = 0; i < motif[0].size(); i++)
	{
	  if (i % L == 0 && i != 0)
	    {
	      if (maya[j] == tmp)
		possibleValue.push_back(mayaInt);
	      tmp.clear();
	      mayaInt++;
	    }
	  tmp.push_back(motif[0][i]);
	}

      for (auto value : possibleValue)
	{
	  auto tmpMaya = intToMaya(value, motif, L, H);
	  if (compareMaya(maya, tmpMaya, j, j + H))
	    {
	      values.push_back(value);
	      break;
	    }
	}
      possibleValue.clear();
      tmp.clear();
    }

  result = 0;
  multiplicator = pow(20, maya.size() / H - 1);
  for (auto value : values)
    {
      result += (value * multiplicator);
      multiplicator /= 20;
    }
  return result;
}

int main()
{
  unsigned long long int num1;
  unsigned long long int num2;
  vector<string> motif;
  vector<string> mayaFirst;
  vector<string> mayaSecond;
  vector<unsigned long long int> resultsInt;
  map<string, unsigned long long int> calcul;

  int L;
  int H;
  cin >> L >> H; cin.ignore();
  motif.reserve(H);
  for (int i = 0; i < H; i++) {
    string numeral;
    cin >> numeral; cin.ignore();
    motif.push_back(numeral);
  }
  int S1;
  cin >> S1; cin.ignore();
  mayaFirst.reserve(S1);
  for (int i = 0; i < S1; i++) {
    string num1Line;
    cin >> num1Line; cin.ignore();
    mayaFirst.push_back(num1Line);
  }
  int S2;
  cin >> S2; cin.ignore();
  mayaSecond.reserve(S2);
  for (int i = 0; i < S2; i++) {
    string num2Line;
    cin >> num2Line; cin.ignore();
    mayaSecond.push_back(num2Line);
  }
  string operation;
  cin >> operation; cin.ignore();

  num1 = mayaToInt(mayaFirst, motif, L, H);
  num2 = mayaToInt(mayaSecond, motif, L, H);

  calcul["+"] = num1 + num2;
  calcul["-"] = num1 - num2;
  calcul["*"] = num1 * num2;
  if (num2 != 0)
    calcul["/"] = num1 / num2;

  splitBase(calcul[operation], resultsInt, 10, true);

  if (resultsInt.size() == 0)
    resultsInt.push_back(0);
  for (auto resultInt : resultsInt)
    printMaya(intToMaya(resultInt, motif, L, H));
}
