#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void addEdge(vector<int> adj[], int firstNode, int secondNode)
{
  adj[firstNode].push_back(secondNode);
  adj[secondNode].push_back(firstNode);
}

int main()
{
  int N; // the total number of nodes in the level, including the gateways
  int L; // the number of links
  int E; // the number of exit gateways
  bool danger;
  cin >> N >> L >> E; cin.ignore();
  vector<int> adj[N]; // Graph
  vector<int> exits; // Exit

  for (int i = 0; i < L; i++) {
    int N1; // N1 and N2 defines a link between these nodes
    int N2;
    cin >> N1 >> N2; cin.ignore();
    addEdge(adj, N1, N2);
  }
  for (int i = 0; i < E; i++) {
    int EI; // the index of a gateway node
    cin >> EI; cin.ignore();
    exits.push_back(EI);
  }

  // game loop
  while (1) {
    int SI; // The index of the node on which the Skynet agent is positioned this turn
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
}
