/*
    ok, here we need to calculate eigenvalue and eigenvector of square matrix
    just do it
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>

using namespace std;

// Matrix multiplication
vector<vector<float>> multiply(const vector<vector<float>>& A, const vector<vector<float>>& B) {
    int n = A.size();
    vector<vector<float>> result(n, vector<float>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Vector dot product
float dot(const vector<float>& a, const vector<float>& b) {
    float result = 0;
    for (int i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

// Normalize a vector
void normalize(vector<float>& v) {
    float norm = sqrt(dot(v, v));
    for (auto& val : v) {
        val /= norm;
    }
}

// QR decomposition
pair<vector<vector<float>>, vector<vector<float>>> qrDecompose(const vector<vector<float>>& A) {
    int n = A.size();
    vector<vector<float>> Q(n, vector<float>(n, 0));
    vector<vector<float>> R(n, vector<float>(n, 0));
    vector<vector<float>> V = A;

    // Perform Gram-Schmidt orthogonalization
    for (int i = 0; i < n; ++i) {
        // Calculate R[i][i]
        R[i][i] = sqrt(dot(V[i], V[i]));
        for (int j = 0; j < n; ++j) {
            Q[j][i] = V[j][i] / R[i][i];
        }

        for (int j = i + 1; j < n; ++j) {
            R[i][j] = dot(Q[i], V[j]);
            for (int k = 0; k < n; ++k) {
                V[k][j] -= R[i][j] * Q[k][i];
            }
        }
    }

    return {Q, R};
}

// QR iteration to find eigenvalues and eigenvectors
pair<vector<float>, vector<vector<float>>> qrEigenvaluesAndVectors(vector<vector<float>> A, int iterations) {
    int n = A.size();
    vector<vector<float>> eigenvectors = A;
    
    for (int i = 0; i < iterations; ++i) {
        auto [Q, R] = qrDecompose(A);
        A = multiply(R, Q);  // A_k+1 = R * Q
        eigenvectors = multiply(eigenvectors, Q); // Accumulate eigenvectors
    }

    // The diagonal elements are the eigenvalues
    vector<float> eigenvalues(n);
    for (int i = 0; i < n; ++i) {
        eigenvalues[i] = A[i][i];
    }

    // Normalize eigenvectors
    for (int i = 0; i < n; ++i) {
        normalize(eigenvectors[i]);
    }

    return {eigenvalues, eigenvectors};
}

int main() {
    // Define the matrix and fill entries
    int n = 0;
    cout << "Please input the size of the square matrix (n): ";
    cin >> n;
    vector<vector<float>> matrix(n, vector<float>(n, 0));
    for(int i = 0; i < n; i++) {
        cout << "Please input row " << i+1 << ": ";
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Number of iterations
    int iterations = 1000;
    auto [eigenvalues, eigenvectors] = qrEigenvaluesAndVectors(matrix, iterations);

    // Output eigenvalues
    cout << "The eigenvalues of the matrix are: ";
    for (float eigenvalue : eigenvalues) {
        cout << eigenvalue << " ";
    }
    cout << endl;

    // Output eigenvectors
    cout << "The eigenvectors of the matrix are: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Eigenvector " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cout << eigenvectors[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}

