#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int lightX; // the X position of the light of power
  int lightY; // the Y position of the light of power
  int initialTX; // Thor's starting X position
  int initialTY; // Thor's starting Y position
  cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

  // game loop
  while (1) {
    std::string direction = "";
    int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
    cin >> remainingTurns; cin.ignore();

    if (initialTY > lightY) {
	initialTY--;
	direction = "N";
    }
    else if (initialTY < lightY) {
	initialTY++;
	direction = "S";
    }

    if (initialTX > lightX) {
	initialTX--;
	direction += "W";
    }
    else if (initialTX < lightX) {
	initialTX++;
	direction += "E";
    }

    // A single line providing the move to be made: N NE E SE S SW W or NW
    cout << direction << endl;
  }
}
