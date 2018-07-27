#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void            addEdge(vector<int> adj[], int firstNode, int secondNode)
{
    adj[firstNode].push_back(secondNode);
    adj[secondNode].push_back(firstNode);
}

int             main()
{
    int         N;
    int         L;
    int         E;
    bool        danger;
    vector<int> adj[N];
    vector<int> exits;

    cin >> N >> L >> E; cin.ignore();

    for (int i = 0; i < L; i++)
    {
        int     N1;
        int     N2;

        cin >> N1 >> N2; cin.ignore();
        addEdge(adj, N1, N2);
    }
    for (int i = 0; i < E; i++)
    {
        int     EI;
        
        cin >> EI; cin.ignore();
        exits.push_back(EI);
    }

    while (1)
    {
        int     SI;
        cin >> SI; cin.ignore();

        danger = false;
        for (auto x : adj[SI])
            for (auto y : exits)
                if (x == y)
                {
                    cout << to_string(SI) + " " + to_string(x) << endl;
                    danger = true;
                }

        if (!danger)
            cout << to_string(SI) + " " + to_string(adj[SI][0]) << endl;
    }
    return 0;
}
