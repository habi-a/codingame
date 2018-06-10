#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

  // game loop
  while (1) {
    int indexHighestMountain = 0;
    int valueHighestMountain = 0;
    for (int i = 0; i < 8; i++) {
      int mountainH; // represents the height of one mountain.
      cin >> mountainH; cin.ignore();
      if (mountainH > valueHighestMountain) {
	valueHighestMountain = mountainH;
	indexHighestMountain = i;
      }
    }

    cout << indexHighestMountain << endl; // The index of the mountain to fire on.
  }
}
