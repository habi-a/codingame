#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int                         main()
{
    int                     width;
    int                     height;
    string                  response;
    vector<std::string>     map;
    vector<unsigned int>    nodeCoordX;
    vector<unsigned int>    nodeCoordY;

    cin >> width; cin.ignore();
    cin >> height; cin.ignore();
    for (int i = 0; i < height; i++)
    {
        string              line;
        
        getline(cin, line);
        map.push_back(line);
        cerr << line << endl;
    }

    for (unsigned int x = 0; x < width; x++)
        for (unsigned int y = 0; y < height; y++)
            if (map[y][x] == '0')
            {
                nodeCoordX.push_back(x);
                nodeCoordY.push_back(y);
            }

    for (unsigned int i = 0; i < nodeCoordX.size(); i++)
    {
        bool                rightFinded;
        bool                bottomFinded;
        int                 rightN[2] = {-1, -1};
        int                 bottomN[2] = {-1, -1};

        rightFinded = false;
        bottomFinded = false;
        for (unsigned int j = 0; j < nodeCoordX.size(); j++)
        {
            if (nodeCoordX[j] > nodeCoordX[i] && nodeCoordY[j] == nodeCoordY[i] && !rightFinded)
            {
                rightN[0] = nodeCoordX[j];
                rightN[1] = nodeCoordY[j];
                rightFinded = true;
            }
            if (nodeCoordX[j] == nodeCoordX[i] && nodeCoordY[j] > nodeCoordY[i] && !bottomFinded)
            {
                bottomN[0] = nodeCoordX[j];
                bottomN[1] = nodeCoordY[j];
                bottomFinded = true;
            }
        }

        cout << to_string(nodeCoordX[i]) + " " + to_string(nodeCoordY[i]) + " " + to_string(rightN[0]) + " " + to_string(rightN[1]) + " " + to_string(bottomN[0]) + " " + to_string(bottomN[1]) << endl;
    }
    return 0;
}
