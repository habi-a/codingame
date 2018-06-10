#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctgmath>

using namespace std;

bool hasDirection(string bombDir, char Letter)
{
  for (unsigned int i = 0; i < bombDir.size(); i++)
    if (bombDir[i] == Letter)
      return true;
  return false;
}

int main()
{
  vector<int> eliminatedX;
  vector<int> eliminatedY;
  int W; // width of the building.
  int H; // height of the building.
  cin >> W >> H; cin.ignore();
  int N; // maximum number of turns before game over.
  cin >> N; cin.ignore();
  int X0;
  int Y0;
  cin >> X0 >> Y0; cin.ignore();

  // game loop
  while (1) {
    string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
    cin >> bombDir; cin.ignore();


    // Eliminate
    if (hasDirection(bombDir, 'L'))
      for (unsigned int i = W - 1; i >= X0; i--)
	eliminatedX.push_back(i);
    else if (hasDirection(bombDir, 'R'))
      for (unsigned int i = 0; i <= X0; i++)
	eliminatedX.push_back(i);
    if (hasDirection(bombDir, 'U'))
      for (unsigned int i = H - 1; i >= Y0; i--)
	eliminatedY.push_back(i);
    else if (hasDirection(bombDir, 'D'))
      for (unsigned int i = 0; i <= Y0; i++)
	eliminatedY.push_back(i);


    // remove doublon
    sort(eliminatedX.begin(), eliminatedX.end());
    eliminatedX.erase(unique(eliminatedX.begin(), eliminatedX.end() ), eliminatedX.end());

    sort(eliminatedY.begin(), eliminatedY.end());
    eliminatedY.erase(unique(eliminatedY.begin(), eliminatedY.end() ), eliminatedY.end());


    // Move
    auto moveRL = ceil((float)(W - eliminatedX.size()) / 2);
    auto moveDU = ceil((float)(H - eliminatedY.size()) / 2);

    if (hasDirection(bombDir, 'L'))
      {
	while (X0 - moveRL < 0)
	  moveRL--;
	X0 -= moveRL;
      }
    else if (hasDirection(bombDir, 'R'))
      {
	while (X0 + moveRL >= W)
	  moveRL--;
	X0 += moveRL;
      }
    if (hasDirection(bombDir, 'U'))
      {
	cerr << "UP" << endl;
	while (Y0 - moveDU < 0)
	  moveDU--;
	Y0 -= moveDU;
      }
    else if (hasDirection(bombDir, 'D'))
      {
	while (Y0 + moveDU >= H)
	  moveDU--;
	cerr << "moveDU: " << moveDU << endl;
	Y0 += moveDU;
      }

    // the location of the next window Batman should jump to.
    cout << to_string(X0) + " " + to_string(Y0) << endl;
  }
}
