#include <algorithm>
#include <iostream>
#include <map> 
#include <string>
#include <vector>

using namespace std;


struct Edge 
{
	int src;
	int dest;
};

class Graph
{
    private:
    	map<int, vector<int>> _adjlist;
    	vector<int> _list_nodes;

    public:
    	Graph(vector<Edge> const &edges, vector<int> const &list_nodes)
    	{
    	    _list_nodes = list_nodes;
    		for (auto &edge: edges)
    			_adjlist[edge.src].push_back(edge.dest);
    	}
        
        unsigned int getMaxNbRelations()
        {
            unsigned int max_nb_relations = 0;
            
            for (int node : _list_nodes) {
        	    int nb_relations = getNbRelations(node, 1);
        	    if (nb_relations > max_nb_relations)
        	        max_nb_relations = nb_relations;
        	}
        	return max_nb_relations;
        }
        
        unsigned int getNbRelations(int node, int current_nb_relation)
        {
            unsigned int max_nb_relations = 0;

            if (_adjlist[node].size() == 0)
                return current_nb_relation;
            for (int subnode : _adjlist[node]) {
                int nb_relations = getNbRelations(subnode, current_nb_relation + 1);
                if (nb_relations > max_nb_relations)
        	        max_nb_relations = nb_relations;
            }
            return max_nb_relations;
        }
};


int main()
{
    int n;
    int N;
    vector<int> list_nodes;
    vector<Edge> edges;
    cin >> n; cin.ignore();
    
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        
        if (std::find(list_nodes.begin(), list_nodes.end(), x) == list_nodes.end())
            list_nodes.push_back(x);
        if (std::find(list_nodes.begin(), list_nodes.end(), y) == list_nodes.end())
            list_nodes.push_back(y);
        edges.push_back({ x, y });
    }
    Graph graph(edges, list_nodes);
    cout << graph.getMaxNbRelations() << endl;
    return 0;
}
