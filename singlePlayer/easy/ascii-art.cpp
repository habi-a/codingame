#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int getIndex(char letter)
{
  unsigned int i;
  vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  letter = tolower(letter);
  i = 0;
  while(i < alphabet.size()) {
      if (alphabet[i] == letter)
	return i;
      i++;
  }
  return 26;
}

int main()
{
  vector<string*> result;
  unsigned int index;
  vector<std::string> motif;
  int L;
  cin >> L; cin.ignore();
  int H;
  cin >> H; cin.ignore();
  string T;
  getline(cin, T);
  for (int i = 0; i < H; i++) {
    string ROW;
    getline(cin, ROW);
    motif.push_back(ROW);
  }

  for (unsigned int i = 0; i < T.size(); i++) {
      index = getIndex(T[i]);
      for (unsigned int j = 0; j < motif.size(); j++) {
	  for (unsigned int k = 0; k < L; k++) {
	      if (result.size() == j)
		result.push_back(new string(""));
	      *result[j] += motif[j][index * L + k];
	  }
      }
  }

  for (unsigned int l = 0; l < result.size(); l++) {
      cout << *result[l] << endl;
  }
}
