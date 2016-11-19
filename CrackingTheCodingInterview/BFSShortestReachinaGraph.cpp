//
//  BFSShortestReachinaGraph.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 15/11/2016.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//

#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    
    /// Number of vertices.
    int numberOfVertices;
    
    /// Adjacency list.
    list<int> *adj;
    
public:
    
    /*!
     Constructor.
     
     @param n number of vertices.
     */
    Graph(int n) : numberOfVertices{n} {
        
        adj = new list<int>[n];
    }
    
    /*!
     Add edge to graph.
     
     @param u first vertex of the edge. 
     @param v second vertex of the edge.
     */
    void addEdge(int u, int v) {
     
        //Help in discussion: undirected graph have edge in both direction.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    /*!
     breadth first search implementation.
     
     @param start starting vertex.
     */
    void bfs(int start) {
        
        //Set all nodes to "not visited".
        vector<bool> visited(numberOfVertices, false);
        
        list<int> queue;
        
        visited[start] = true;
        queue.push_back(start);
        
        while (!queue.empty()) {
            
            start = queue.front();
            cout << start << " ";
            queue.pop_front();
            
            for (list<int>::iterator i = adj[start].begin(); i != adj[start].end(); i++) {
                
                if (visited[*i] == false) {
                    
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
    
    /*!
     breadth first search modified to get
     the count of the shortest path to all the vertex
     in a graph from a starting one.
     
     @param start starting vertex.
     */
    vector<int> shortestReach(int start) {

        //Set all nodes to "not visited".
        vector<bool> visited(numberOfVertices, false);
        
        list<int> queue;
        
        visited[start] = true;
        queue.push_back(start);
        
        vector<int> levels(numberOfVertices, -1);
        levels[start] = 0;
        
        while (!queue.empty()) {
            
            start = queue.front();
            queue.pop_front();
            
            for (list<int>::iterator i = adj[start].begin(); i != adj[start].end(); i++) {
                
                if (visited[*i] == false) {
                    
                    visited[*i] = true;
                    queue.push_back(*i);
                    levels[*i] = levels[start] + 6;
                }
            }
        }

        return levels;
    }
};

int main() {
    
    int queries;
    
    cin >> queries;
    
    for (int t = 0; t < queries; t++) {
        
        int n, m;
        
        //Number of graph nodes.
        cin >> n;
        
        // Create a graph of size n where each edge weight is 6.
        Graph graph(n);
        
        //Number of edge.
        cin >> m;
        
        // read and set edges
        for (int i = 0; i < m; i++) {
            
            int u, v;
            
            cin >> u >> v;
            u--, v--;
            
            // add each edge to the graph
            graph.addEdge(u, v);
        }
        
        int startId;
        
        cin >> startId;
        
        startId--;
        
        // Find shortest reach from node s.
        vector<int> distances = graph.shortestReach(startId);
        
        for (int i = 0; i < distances.size(); i++) {
            
            if (i != startId) {
                
                cout << distances[i] << " ";
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
