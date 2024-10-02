/*
    Here is rref function
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

int rref(vector<vector<float>> &matrix) {
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
    
    return pivot_row;
}

int main() {
    int m = 0, n = 0, Rank_Matrix = 0;
    cout << "Please input the shape of m by n matrix:";
    cin >> m >> n;
    vector<vector<float>> matrix(m, vector<float>(n, 0));
    
    for(int i = 0; i < m; i++) {
        cout << "Please Input the row of " << i+1 << ":";
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << endl << "The Orgin Martix is:";
    Visualize(matrix);

    Rank_Matrix = rref(matrix);
    cout << endl <<"The Rank of Matrix is:"<< Rank_Matrix << endl;
    cout << endl << "The Reduced Row Echelon Form is:";
    Visualize(matrix);


}
