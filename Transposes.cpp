/*
    Here is the operation of Tanspose
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>

using namespace std;

void Visualize_Matrix(const vector<vector<float>> &matrix) {
    for(const auto &row : matrix) {
        cout << endl;
        for(const auto elem : row) {
            cout << setw(5) << elem;
        }
    }

}
void Get_Matrix(vector<vector<float>> &matrix) {
    int height = 0, width = 0;
    do {
    cout << "Please input the height and width of your Matrix:";
    cin >> height >> width;
    } while(height == 0 || width == 0);
    
    for(int i = 0; i < height; i++) {
        cout << "Please input the numbers for row " << i + 1 << ": ";
        vector<float> temp(width, 0.0);
        for(int j = 0; j < width; j++) {
            cin >> temp[j];
        }
        matrix.push_back(temp);
    }
    cout << endl << "Original Matrix is:";
    Visualize_Matrix(matrix);
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
    vector<vector<float>> matrix;
    vector<vector<float>> transposed_matrix;
    Get_Matrix(matrix);
    transposed_matrix = Transpose_Matrix(matrix);
    cout << endl << endl << "Transposed Matrix is:";
    Visualize_Matrix(transposed_matrix);
    return 0;
}