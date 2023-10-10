#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <vector>

using namespace std;

long long n, m;
vector<int> wp;
vector<int> ww;
vector<long long> fd, fv;

// Graph class represents a undirected graph
// using adjacency list representation
class Graph {
    int V; // No. of vertices

    // Pointer to an array containing adjacency lists
    list<int>* adj;

    // A function used by DFS
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V); // Constructor
    ~Graph();
    void addEdge(int v, int w);
    void connectedComponents();
};

// Method to print connected components in an
// undirected graph
void Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            // print all reachable vertices
            // from v
            DFSUtil(v, visited);

            sort(wp.begin(), wp.end());
            sort(ww.rbegin(), ww.rend());

            for (int yp = 0 ;yp < wp.size(); yp++){
                fd[wp[yp]] = ww[yp];
            }

            wp.clear();
            ww.clear();
        }
    }
    delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    wp.push_back(v);
    ww.push_back(fv[v]);

    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph() { delete[] adj; }

// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Driver code
int main()
{
    cin >> n >> m;
    vector<long long> arr(n), res(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    fv = arr;

    Graph g((int)n);
    for (long long i = 0; i < m; i++) {
        long long f, s;
        cin >> f >> s;
        g.addEdge((int)f-1,(int)s-1);
    }

    fd = res;
    g.connectedComponents();

    for (int i = 0; i < fd.size(); ++i) {
        cout << fd[i] << " ";
    }

    return 0;
}