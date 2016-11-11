//
//  DFSConnectedCellInaGrid.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 10/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid

#include <vector>
#include <iostream>

using namespace std;

class Graph {
private:
    
    int n;
    int m;
    
    vector<int> rowNeighbours;
    vector<int> colNeighbours;
    
public:
    
    vector<vector<int>> adjacencyMatrix;
    vector<vector<bool>> visited;
    int countContinuosNodeConnected;
    
    Graph(int n, int m, vector<vector<int>> matrix) : n{n}, m{m}, adjacencyMatrix{matrix} {
        
        rowNeighbours = {-1, -1, -1,  0, 0,  1, 1, 1};
        colNeighbours = {-1,  0,  1, -1, 1, -1, 0, 1};
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
    }
    
    void resetSearchModified() {
        
        countContinuosNodeConnected = 0;
    }
    
    bool notVisited(int row, int col) {
        
        if ((row >= 0 && row < n) && (col >= 0 && col < m) && adjacencyMatrix[row][col] && !visited[row][col]) {
            
            return true;
        }
        
        return false;
    }
    
    void dfsModified(int row, int column){
        
        visited[row][column] = true;
        countContinuosNodeConnected++;
        
        for (int i = 0; i < 8; i++) {
            
            if (notVisited(row + rowNeighbours[i], column + colNeighbours[i])) {
                
                dfsModified(row + rowNeighbours[i], column + colNeighbours[i]);
            }
        }
    }
};

int getBiggestRegion(vector<vector<int>> grid, int n, int m) {
    
    Graph g(n, m, grid);
    
    int biggestRegion = 0;
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
            
            if (g.adjacencyMatrix[i][j] && !g.visited[i][j]) {
                
                g.countContinuosNodeConnected = 0;
                g.dfsModified(i, j);
                
                if (biggestRegion < g.countContinuosNodeConnected) {
                    
                    biggestRegion = g.countContinuosNodeConnected;
                }
            }
        }
    }
    
    return biggestRegion;
}

int main() {
    
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    
    vector<vector<int>> grid(n,vector<int>(m));
    
    for (int grid_i = 0;grid_i < n;grid_i++) {
        
        for (int grid_j = 0; grid_j < m; grid_j++) {
            
            cin >> grid[grid_i][grid_j];
        }
    }
    cout << getBiggestRegion(grid, n, m) << endl;
    
    return 0;
}
