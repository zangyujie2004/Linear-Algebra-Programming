 /*
    ok,here is C++ practice for determinant formula solution
    let's go!
 */

#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>

using namespace std;

float Det(vector<vector<float>> &matrix) {
    int n = matrix.size();
    if(n == 1) {
        return matrix[0][0];
    }
    if(n == 2) {
        return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
    }

    float det = 0.0f;

    for(int i = 0; i < n; i++) {
        vector<vector<float>> submatrix(n - 1, vector<float>(n - 1, 0));
        for(int row = 1; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(col < i) {
                    submatrix[row-1][col] = matrix[row][col];
                } else if(col > i) {
                    submatrix[row-1][col-1] = matrix[row][col];
                }
            }
        }
        det += pow(-1, i) * matrix[0][i] * Det(submatrix); 
    }
    
    return det;
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

    //caculate the det and print
    float det = Det(matrix);
    cout << endl << "The determinat of the matrix is:" << det; 
    return 0;
}
