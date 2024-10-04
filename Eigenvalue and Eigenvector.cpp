/*
    ok, here we need to calculate eigenvalue and eigenvector of square matrix
    just do it
*/
#include <iostream>
#include <Eigen/Dense> // Include the Eigen library header

using namespace std;
using namespace Eigen; // Use the Eigen namespace

int main() {
    // Define the size of the matrix
    int n = 0;
    cout << "Please input the size of the square matrix (n): ";
    cin >> n;

    MatrixXf matrix(n, n); // Create an n x n matrix
    for (int i = 0; i < n; i++) {
        cout << "Please input row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> matrix(i, j); // Fill the matrix using Eigen's indexing
        }
    }

    // Calculate eigenvalues and eigenvectors
    EigenSolver<MatrixXf> solver(matrix); // Create the eigenvalue solver
    VectorXf eigenvalues = solver.eigenvalues().real(); // Get the eigenvalues (real part)
    MatrixXf eigenvectors = solver.eigenvectors().real(); // Get the eigenvectors (real part)

    // Output eigenvalues
    cout << endl << "The eigenvalues of the matrix are: ";
    for (int i = 0; i < n; i++) {
        cout << eigenvalues[i] << " ";
    }
    cout << endl;

    // Output eigenvectors
    cout << "The eigenvectors of the matrix are: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Eigenvector " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cout << eigenvectors(j, i) << " "; // Eigen stores in column-major order
        }
        cout << endl;
    }

    return 0;
}
