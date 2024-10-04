/*
    ok, here we need to calculate eigenvalue and eigenvector of square matrix
    just do it
*/

#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>

using namespace std;

float Det(vector<vector<float>> &matrix) {
    int n = matrix.size();
    if(n == 1) {
        return matrix[0][0];
    }
    if(n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
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

vector<vector<float>> Subtract_Lambda_Identity(const vector<vector<float>> &matrix, float lambda) {
    int n = matrix.size();
    vector<vector<float>> result = matrix;
    for(int i = 0; i < n; i++) {
        result[i][i] -= lambda;
    }
    return result;
}

float Find_Eigenvalue(const vector<vector<float>> &matrix) {
    // Set the tolerance and initial range based on matrix properties
    float tolerance = 1e-6;
    float high = 1000.0;  // You can adjust this based on the matrix size
    float low = -1000.0;
    float mid = 0.0;
    
    while(high - low > tolerance) {
        mid = (high + low) / 2.0;
        vector<vector<float>> temp_matrix = Subtract_Lambda_Identity(matrix, mid);
        float det = Det(temp_matrix);

        cout << endl << "mid: " << mid << ", det: " << det;

        if(fabs(det) < tolerance) return mid;  // Close enough to zero, return eigenvalue
        else if(det > 0) high = mid;           // Adjust search range
        else low = mid;
    }

    return mid;  // Return the approximate eigenvalue
}

int main() {
    // Define the matrix and fill entries
    int n = 0;
    cout << "Please input the shape of square matrix (n): ";
    cin >> n;
    vector<vector<float>> matrix(n, vector<float>(n, 0));
    for(int i = 0; i < n; i++) {
        cout << "Please Input row " << i+1 << ": ";
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calculate the eigenvalue of matrix
    float eigenvalue = Find_Eigenvalue(matrix);
    cout << endl << "An eigenvalue of the matrix is approximately: " << eigenvalue << endl;
    return 0;
}

