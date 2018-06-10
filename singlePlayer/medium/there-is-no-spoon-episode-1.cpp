#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string response;
  vector<unsigned int> nodeCoordX;
  vector<unsigned int> nodeCoordY;
  vector<std::string> map;
  int width; // the number of cells on the X axis
  cin >> width; cin.ignore();
  int height; // the number of cells on the Y axis
  cin >> height; cin.ignore();
  for (int i = 0; i < height; i++)
    {
      string line; // width characters, each either 0 or .
      getline(cin, line);
      map.push_back(line);
      cerr << line << endl;
    }


  // Fill Node
  for (unsigned int x = 0; x < width; x++)
    for (unsigned int y = 0; y < height; y++)
      if (map[y][x] == '0')
	{
	  nodeCoordX.push_back(x);
	  nodeCoordY.push_back(y);
	}

  // For each node, check neighb
  for (unsigned int i = 0; i < nodeCoordX.size(); i++)
    {
      bool rightFinded;
      bool bottomFinded;
      int rightN[2] = {-1, -1};
      int bottomN[2] = {-1, -1};

      rightFinded = false;
      bottomFinded = false;
      for (unsigned int j = 0; j < nodeCoordX.size(); j++)
	{
	  // Check Right
	  if (nodeCoordX[j] > nodeCoordX[i] && nodeCoordY[j] == nodeCoordY[i] && !rightFinded)
	    {
	      rightN[0] = nodeCoordX[j];
	      rightN[1] = nodeCoordY[j];
	      rightFinded = true;
	    }

	  // Check Bottom
	  if (nodeCoordX[j] == nodeCoordX[i] && nodeCoordY[j] > nodeCoordY[i] && !bottomFinded)
	    {
	      bottomN[0] = nodeCoordX[j];
	      bottomN[1] = nodeCoordY[j];
	      bottomFinded = true;
	    }
	}

      // Three coordinates: a node, its right neighbor, its bottom neighbor
      cout << to_string(nodeCoordX[i]) + " " + to_string(nodeCoordY[i]) + " " + to_string(rightN[0]) + " " + to_string(rightN[1]) + " " + to_string(bottomN[0]) + " " + to_string(bottomN[1]) << endl;
    }
}
