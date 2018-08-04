#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int             main()
{
    int         nbFloors;
    int         width;
    int         nbRounds;
    int         exitFloor;
    int         exitPos;
    int         nbTotalClones;
    int         nbAdditionalElevators;
    int         nbElevators;
    int         elevators[nbElevators + 1];

    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; 
    cin.ignore();
    elevators[exitFloor] = exitPos;

    for (int i = 0; i < nbElevators; i++)
    {
        int     elevatorFloor;
        int     elevatorPos;
        
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        elevators[elevatorFloor] = elevatorPos;
    }

    while (1)
    {
        int     cloneFloor;
        int     clonePos;
        string  direction;

        cin >> cloneFloor >> clonePos >> direction; 
        cin.ignore();

        if (elevators[cloneFloor] < clonePos && direction == "RIGHT")
            cout << "BLOCK" << endl;
        else if (elevators[cloneFloor] > clonePos && direction == "LEFT")
            cout << "BLOCK" << endl;
        else
            cout << "WAIT" << endl;
    }
    return 0;
}
