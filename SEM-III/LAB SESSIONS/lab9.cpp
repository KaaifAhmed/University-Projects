#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;
    list<int> *adjList; // int *arr -> Dynamic Array

public:
    Graph (int V) {
        this->V = V;
        adjList = new list<int> [V];
    }

    void addEdge (int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  
    }

    void printAdjList () {
        for (size_t i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (auto neigh : adjList[i]) {
                cout << neigh << " " ;
            }
            cout << endl;
        }
        
    }

    void printBFS (int src) {
        vector<bool> visited(V,false);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (q.size() > 0)
        {
            int current = q.front();
            q.pop();
            cout << current << " ";
            for (auto neigh : adjList[current])
            {
                if (!visited[neigh])
                {
                    q.push(neigh);
                    visited[neigh] = true;
                }                
            }            
        }        
    }

    void shortestDistance (int src) {
        vector<bool> visited(V,false);
        vector<int> distance(V,0);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (q.size() > 0)
        {
            int current = q.front();
            q.pop();

            for (auto neigh : adjList[current])
            {
                if (!visited[neigh])
                {
                    q.push(neigh);
                    visited[neigh] = true;
                    distance[neigh] += distance[current] + 1;
                }                
            }            
        }

        for (size_t i = 0; i < distance.size(); i++)
        {
            cout << "\nDistance from " << src << " till " << i << " is " << distance[i] << ".";
        }        
    }

    void printDFS (int src, vector<bool> visited) {
        visited[src] = true;
        cout << " " << src;

        for (int neigh : adjList[src])
            if (!visited[neigh])
                printDFS(neigh, visited);
    }
    
};

int main () {
    // Graph g(20);
    
//     g.addEdge(0,1);
//     g.addEdge(1,6);
//     g.addEdge(1,2);
//     g.addEdge(2,3);
//     g.addEdge(3,7);
//     g.addEdge(4,5);
//     g.addEdge(4,9);
//     g.addEdge(5,10);
//     g.addEdge(6,11);
//     g.addEdge(7,8);
//     g.addEdge(7,13);
//     g.addEdge(8,9);
//     g.addEdge(10,14);
//     g.addEdge(11,15);
//     g.addEdge(11,12);
//     g.addEdge(12,13);
//     g.addEdge(13,16);
//     g.addEdge(14,19);
//     g.addEdge(16,17);
//     g.addEdge(17,18);
//     g.addEdge(18,19);

    Graph g(8);
    
    g.addEdge(0,7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,6);
    g.addEdge(3,5);

    // g.printAdjList();
    vector<bool> visited(8,false);
    g.printDFS(0, visited);
    // g.shortestDistance(6);

    return 0;
}