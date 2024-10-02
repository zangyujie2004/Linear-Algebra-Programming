 /*
    Hello,here we will transform a independent matrix to orthonormal matrix
    Let's start!
 */

#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>

using namespace std;

void Visualize(vector<vector<float>> &matrix){
    cout << endl;
    int m = matrix.size(), n = matrix[0].size();
    // Set fixed precision for floating-point numbers
    cout << fixed << setprecision(5);  
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << setw(10) << matrix[i][j];  
        }
        cout << endl;
    }
}

void IndependenceJudgement(vector<vector<float>> &M) {
    vector<vector<float>> matrix = M;
    int m = matrix.size(), n = matrix[0].size();
    int pivot_row = 0;
    for(int col = 0; col < n; col++) {
        int row = pivot_row;
        // find the loaction of pivot
        while(row < m && matrix[row][col] == 0) row++;
        if(row == m) continue;
        else if(row != pivot_row) {
            swap(matrix[pivot_row], matrix[row]);
            row = pivot_row;
        }

        // Elimination for the below rows
        for(int i = pivot_row + 1; i < m; i++) {
            float factor = - matrix[i][col] / matrix[pivot_row][col];
            for(int j = col; j < n; j++) {
                matrix[i][j] += factor * matrix[pivot_row][j];
            }
        }
        pivot_row++;
    }
    int min_m_n = min(m, n);
    if(min_m_n != pivot_row) {
        cout << endl << "Sorry, the matrix is not independent !";
        Visualize(matrix);
        exit(1);
    }
}

vector<vector<float>> TransformToOrthonormal(vector<vector<float>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<float>> orthonomal_matrix = matrix;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            float parameter = 0.0f;
            for(int k = 0; k < m; k++) {
                parameter += orthonomal_matrix[k][i] * orthonomal_matrix[k][j];
            }
            for(int k = 0; k < m; k++) {
                orthonomal_matrix[k][i] -= parameter * orthonomal_matrix[k][j];
            }
        }
        float Norm_2 = 0.0f;
        for(int k = 0; k < m; k++) {
            Norm_2 += orthonomal_matrix[k][i] * orthonomal_matrix[k][i];
        }
        Norm_2 = sqrt(Norm_2);
        for(int k = 0; k < m; k++) {
            orthonomal_matrix[k][i] /= Norm_2;
    
        }
    } 
    return orthonomal_matrix;
}

void Verification(vector<vector<float>> &matrix) {
    vector<float> vset;
    int m = matrix.size(), n = matrix[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            float temp = 0.0f;
            for(int k = 0; k < m; k++) {
                temp += matrix[k][i] * matrix[k][j];
            }
            vset.push_back(temp);
        }
    }
    cout << endl << "Verification is:";
    cout << fixed << setprecision(5); 
    for(auto x : vset) {
        cout << setw(10) << x; 
    }
}

int main() {
    int m = 0, n = 0;
    cout << "Please input the shape of m by n matrix:";
    cin >> m >> n;
    vector<vector<float>> matrix(m, vector<float>(n, 0));
    
    for(int i = 0; i < m; i++) {
        cout << "Please Input the row of " << i+1 << ":";
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    IndependenceJudgement(matrix);
    vector<vector<float>> orthonormal_matrix = TransformToOrthonormal(matrix);
    cout << endl << endl << "Luckily matrix is independent.Here is the orthonormal matrix:";    
    Visualize(orthonormal_matrix);
    Verification(orthonormal_matrix);
    return 0;
}