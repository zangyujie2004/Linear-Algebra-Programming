 /*
    ok, here is the practice to confirm 4 foundamenta spaces of matrix
 */

#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

void Visualize(vector<vector<float>> &matrix){
    cout << endl;
    int m = matrix.size(), n = matrix[0].size();
    // Set fixed precision for floating-point numbers
    cout << fixed << setprecision(1);  
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j];  
        }
        cout << endl;
    }
}

int rref(const vector<vector<float>> &M) {
    vector<vector<float>> matrix = M;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> PivotLoaction;
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

        // Normalize the pivot row (make pivot element 1)
        float temp_pivot = matrix[pivot_row][col];
        for(int j = col; j < n; j++) {
            matrix[pivot_row][j] /= temp_pivot;
        }

        // Elimination for the below rows
        for(int i = pivot_row + 1; i < m; i++) {
            float factor = - matrix[i][col] / matrix[pivot_row][col];
            for(int j = col; j < n; j++) {
                matrix[i][j] += factor * matrix[pivot_row][j];
            }
        }
        PivotLoaction.push_back(vector<int> {pivot_row++, col});
    }
    
    // substitution to simplify pivot column 
    for(int k = PivotLoaction.size() - 1; k >= 0; k--) {
        int row = PivotLoaction[k][0], col = PivotLoaction[k][1];
        for(int i = row - 1; i >= 0; i--) {
            if(matrix[i][col] == 0) continue;
            float factor = - matrix[i][col] / matrix[row][col];
            for(int j = 0; j < n; j++) {
                matrix[i][j] += factor * matrix[row][j];
            }
        }
    }
    
    Visualize(matrix);
    return pivot_row;
}

vector<vector<float>> Transpose_Matrix(vector<vector<float>> &matrix) {
    size_t height = matrix.size();
    size_t width = matrix[0].size();
    vector<vector<float>> transposed_Matrix(width, vector<float>(height, 0.0));

    for(size_t i = 0; i < height; i++) {
        for(size_t j = 0; j < width; j++) {
            transposed_Matrix[j][i] = matrix[i][j];
        }
    }
    return transposed_Matrix;
}

int main() {
    int m = 0, n = 0, Rank = 0, RankofTranspose = 0;
    cout << "Please input the shape of m by n matrix:";
    cin >> m >> n;
    vector<vector<float>> matrix(m, vector<float>(n, 0));
    
    for(int i = 0; i < m; i++) {
        cout << "Please Input the row of " << i+1 << ":";
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << endl << endl << "Reduced Row Echelon Form of Matrix is:";    
    Rank = rref(matrix);
    cout << "The Space of Matrix is:"<< Rank << endl;
    cout << "The Nullspace of Matrix is:"<< matrix[0].size() - Rank << endl;

    vector<vector<float>> new_matrix = Transpose_Matrix(matrix);
    cout << endl << endl << "Reduced Row Echelon Form of Transposed Matrix is:";
    RankofTranspose = rref(new_matrix);
    cout << "The Rank of Transposed_Matrix is:"<< RankofTranspose << endl;
    cout << "The Nullspace of Transpose Matrix is:"<< matrix.size() - RankofTranspose << endl;
}
