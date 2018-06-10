#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  int n; // the number of temperatures to analyse
  int closestNumber = 5527;
  cin >> n; cin.ignore();
  for (int i = 0; i < n; i++) {
    int t; // a temperature expressed as an integer ranging from -273 to 5526
    cin >> t; cin.ignore();
    if (abs(closestNumber) > abs(t))
      closestNumber = t;
    else if (abs(closestNumber) == abs(t) && t > closestNumber)
      closestNumber = t;
  }
  if (closestNumber == 5527)
    closestNumber = 0;

  cout << closestNumber << endl;
}
