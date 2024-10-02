/* 
    Here is Elimination method
    to solve 3 equations and 3 unknown suitation
*/

#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>

using namespace std;
#define matrix_width 2

void Visualize_process(vector<vector<float>> &A, vector<vector<float>> &b){
    for(int i = 0; i < matrix_width; i++) {
        if(i == 0) {
            printf("A =");
        }
        else {
            printf("   "); 
        }
        for(int j = 0; j < matrix_width; j++) {
            cout << setw(5) << A[i][j];  
        }
        cout << endl;
    } 
    printf("\nb =");
    for(int i = 0; i < matrix_width; i++) {
        if(i != 0) {
            cout << "   ";
        }
        cout << setw(5) << b[0][i];
        cout << endl;
    }
}

void Input_Matrix(vector<vector<float>> &A, vector<vector<float>> &b) {
    char choice;
    do {
        printf("Here you need to input number of A(%d*%d): \n", matrix_width, matrix_width);
        for(int i = 0; i < matrix_width; i++) {
            printf("Here input the row of %d: ", i + 1);
            for(int j = 0; j < matrix_width; j++) {
                cin >> A[i][j];
            }
        }

        printf("Here you need to input number of b(1*%d): ", matrix_width);
        for(int i = 0; i < matrix_width; i++) {
            cin >> b[0][i];
        }

        printf("\n\nConfirm your input (if incorrect press 'r' to re-enter, any other key to continue): \n");
        Visualize_process(A, b);

        cin >> choice;
    } while(choice == 'r' || choice == 'R');  // 如果用户选择 'r' 或 'R'，重新输入
}

void Dectect_coindence(vector<vector<float>> &A) {
    const float epsilon = 1e-6; // 容忍度，用于浮点数比较
    for(int row1 = 0; row1 < matrix_width - 1; row1++) {
        for(int row2 = row1 + 1; row2 < matrix_width; row2++) {
            float rate = A[row1][0] / A[row2][0];
            bool is_coincident = true;
            for(int j = 1; j < matrix_width; j++) {
                if (fabs(A[row1][j] / A[row2][j] - rate) > epsilon) {
                    is_coincident = false;
                    break;
                }
            }
            if (is_coincident) {
                printf("\nThe Number of Solutions is Infinity");
                exit(1);
            }
        }
    }
}

void Detect_Zero(vector<vector<float>> &A, vector<vector<float>> &b) {
    for(int i = 0; i < matrix_width; i++) {
        if(A[i][i] == 0) {
            bool swapped = false;
            for(int k = i + 1; k < matrix_width; k++) {
                if(A[k][i] != 0) {
                    swap(A[i], A[k]);
                    swap(b[0][i], b[0][k]);
                    swapped = true;
                    break;
                }
            }
            if(!swapped) {
                cout << "Matrix is singular or cannot proceed with elimination due to a zero pivot." << endl;
                exit(1);
            }
        }
    }
    printf("\nDecte Pivot: \n");
    Visualize_process(A, b);
}

void Substraction(vector<vector<float>> &A, vector<vector<float>> &b) {
    for(int j = 0; j < matrix_width - 1; j++) {
        for(int i = j + 1;i < matrix_width; i++) {
            float rate = - A[i][j] / A[j][j];
            for(int k = j; k < matrix_width; k++) {
                A[i][k] += rate * A[j][k];
            } 
            b[0][i] += rate * b[0][j];
        }
    }
    printf("\nSubStraction to Upper Ritangular Matrix: \n");
    Visualize_process(A, b);
}
void Back_Substitution(vector<vector<float>> &A, vector<vector<float>> &b, vector<vector<float>> &x){
    for(int i = matrix_width - 1; i >= 0; i--) {
        x[0][i] = b[0][i];
        for(int j = matrix_width - 1; j > i; j--) {
            x[0][i] -= A[i][j] * x[0][j];
        }
        x[0][i] /= A[i][i];
    }
    printf("\nAnswer is :\n");
    printf("x =");
    for(int i = 0; i < matrix_width; i++) {
        if(i != 0) {
            cout << "   ";
        }
        cout << setw(5) << x[0][i];
        cout << endl;
    }
}

int main() {
    // create and input number of matrix
    vector<vector<float>> A(matrix_width, vector<float>(matrix_width, 0.00));
    vector<vector<float>> x(matrix_width, vector<float>(1, 0.00));
    vector<vector<float>> b(matrix_width, vector<float>(1, 0.00));
    
    Input_Matrix(A, b);
    Dectect_coindence(A);
    Detect_Zero(A, b);
    Substraction(A, b);
    Back_Substitution(A, b, x);
    return 0;
}