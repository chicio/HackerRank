//
//  EvenTree.cpp
//  GraphTest
//
//  Created by Duroni Fabrizio on 04/08/16.
//  Copyright © 2016 Duroni Fabrizio. All rights reserved.
//
//  https://www.hackerrank.com/challenges/even-tree

#include <iostream>
#include <vector>

using namespace std;

class Tree {
private:
    
    /// Number of vertices of the tree.
    int numberOfVertices;
    /// Adjacency list for vertices.
    vector<vector<int>> adj;
    
    /*!
     Depth first search visit method.
     It implements the recursive part of DFS.
     This is a modified version of the algorithm that only counts the node visited.
     
     @param v current vertex visited.
     @param countVisited count of already visited node.
     */
    void depthFirstSearchVisit(int vertex, int& countVisited) {
        
        //Increment count visited.
        countVisited++;
        
        //Visit recursively all child of the current vertex.
        //Tree is directed directed acylic graph, so no need
        //to check if node in the adjacency list has been visited:
        //they are not visited for sure.
        for (int i = 0; i < adj[vertex].size(); i++) {
            
            depthFirstSearchVisit(adj[vertex][i], countVisited);
        }
    }
    
public:
    
    /*!
     Constructor
     
     @param numVertices number of vertices of the tree.
     */
    Tree(int numVertices) {
        
        numberOfVertices = numVertices;
        
        for (int i = 0; i <= numberOfVertices; i++) {
            
            adj.push_back(vector<int>());
        }
    };
    
    /*!
     Add an edge to the tree.
     
     @param vi vertex 1
     @param ui vertex 2
     */
    void addEdge(int vi, int ui) {
        
        adj[vi].push_back(ui);
    }
    
    /*!
     Get child for vertex received as parameter.
     
     @param vertex vertex used as indices to get the list of its children.
     
     @returns the list of children for vertex.
     */
    const vector<int>& getChildForVertex(int vertex) {

        return adj[vertex];
    }
    
    /*!
     Depth first search method.
     Modified version to count the number of elements visited.
     
     @param vertex starting vertex.
     
     @returns the number of elements visited.
     */
    int depthFirstSearch(int vertex) {
        
        //Set all vertices as not visited.
        int countVisited = 0;
        
        //Start depth search first.
        depthFirstSearchVisit(vertex, countVisited);
        
        return countVisited;
    }
};

int main() {
    
    //n is the number of vertices.
    //m is the number of edges.
    int n, m;
    
    //Read parameters.
    cin >> n >> m;
    
    //Create tree.
    Tree t(n);
    
    //Vertices of an edge.
    int ui, vi;
    
    for (int i = 0; i < m; i++) {
        
        //Read edge vertices.
        cin >> ui >> vi;
        
        //Add edge to tree.
        t.addEdge(vi, ui);
    }
    
    int edgesToRemove = 0;
    
    //Count number of edges that can remove from the tree
    //to get a forest such that each connected component of
    //the forest contains an even number of vertices.
    for (int i = 1; i <= n; i++) {
        
        //For each child of the current node count
        //the number of elements using DSF (including the child vertex).
        //If the count is even, then the edge could be removed.
        for (int h = 0; h < t.getChildForVertex(i).size(); h++) {
            
            int countChildVisited = t.depthFirstSearch(t.getChildForVertex(i)[h]);
            
            if(countChildVisited % 2 == 0) {
                
                edgesToRemove++;
            }
        }
    }
    
    cout << edgesToRemove;
    
    return 0;
}
