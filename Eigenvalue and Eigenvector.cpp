/*
    ok, here we need to calculate eigenvalue and eigenvector of square matrix
    just do it
*/

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

vector<float> Eigenvalue_Fuction(vector<vector<float>> &matrix) {
    
}


int main() {
     // define the matrix and fill every entries
    int n = 0;
    cout << "Please input the shape of square matirx(n):";
    cin >> n;
    vector<vector<float>> matrix(n, vector<float>(n, 0));
    for(int i = 0; i < n; i++) {
        cout << "Please Input the row of " << i+1 << ":";
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // calculate the eigenvalue of matrix
    vector<float> eigenvalue(n, 0);
    eigenvalue = Eigenvalue_Fuction(martix);
    return 0;
}

