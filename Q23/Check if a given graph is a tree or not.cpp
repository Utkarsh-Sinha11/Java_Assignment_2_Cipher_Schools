#include <bits/stdc++.h> 
using namespace std; 

class Graph 
{
	public: 
	Graph(int V); 
	void addEdge(int v, int w);
	bool isTree(); 
	private:
	int V; 
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], int parent); 

}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v); 
} 

bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
	visited[v] = true; 

	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
	{ 
		if (!visited[*i]) 
		{ 
		if (isCyclicUtil(*i, visited, v)) 
			return true; 
		} 
		else if (*i != parent) 
		return true; 
	} 
	return false; 
} 

bool Graph::isTree() 
{ 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
	visited[i] = false; 
	
	if (isCyclicUtil(0, visited, -1)) 
			return false; 
			
	for (int u = 0; u < V; u++) 
		if (!visited[u]) 
		return false; 
		
	return true; 
} 

int main() 
{ 
	Graph G(4); 
	G.addEdge(1, 0); 
	G.addEdge(0, 2); 
	G.addEdge(2,3); 
	G.addEdge(1,2); 
	
	if(G.isTree())
	{
		cout << "Graph is Tree\n";
	}else
	{
		cout << "Graph is not Tree\n"; 
	}
	return 0; 
} 

