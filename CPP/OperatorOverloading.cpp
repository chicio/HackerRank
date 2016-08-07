//
//  OperatorOverloading.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/08/16.
//
//  https://www.hackerrank.com/challenges/operator-overloading

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Matrix {
public:
    //Vector to store matrix values.
    vector<vector<int>> a;
    
    /*
     * Overload + operator to sum matrix.
     *
     * @param otherMatrix the other matrix to be summed.
     *
     * @returns the other matrix to be summed.
     */
    Matrix operator+(const Matrix& otherMatrix) {
        
        Matrix resultMatrix;
        
        for(int i = 0; i < a.size(); i++) {
            
            vector<int> row;
            
            for(int k = 0; k < a[i].size(); k++) {
                
                row.push_back(a[i][k] + otherMatrix.a[i][k]);
            }
            
            resultMatrix.a.push_back(row);
        }
        
        return resultMatrix;
    };
};

//Code provided by Hackerank
int main () {
    int cases,k;
    cin >> cases;
    for(k=0;k<cases;k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n,m,i,j;
        cin >> n >> m;
        for(i=0;i<n;i++) {
            vector<int> b;
            int num;
            for(j=0;j<m;j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for(i=0;i<n;i++) {
            vector<int> b;
            int num;
            for(j=0;j<m;j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x+y;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }  
    return 0;
}
