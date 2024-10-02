/*
    Here is n * n Matrix Multiplicaton
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>

using namespace std;

#define A_rownum 3
#define A_colnum 3
#define B_rownum 3
#define B_colnum 3

void Visualize_process(vector<vector<float>> &A, vector<vector<float>> &B){
    for(int i = 0; i < A_rownum; i++) {
        if(i == 0) {
            printf("A =");
        }
        else {
            printf("   "); 
        }
        for(int j = 0; j < A_colnum; j++) {
            cout << setw(5) << A[i][j];  
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < B_rownum; i++) {
        if(i == 0) {
            printf("B =");
        }
        else {
            printf("   "); 
        }
        for(int j = 0; j < B_colnum; j++) {
            cout << setw(5) << B[i][j];  
        }
        cout << endl;
    } 
}

void Input_Matrix(vector<vector<float>> &A, vector<vector<float>> &B) {
    char choice = 'c';
    do {
        printf("Please input matrix A(%d * %d): \n",A_rownum, A_colnum);
        for(int i = 0; i < A_rownum; i++) {
            printf("Here input the row of %d: ", i + 1);
            for(int j = 0; j < A_colnum; j++) {
                cin >> A[i][j];
            }
        }

        printf("Please input matrix B(%d * %d): \n",B_rownum, B_colnum);
        for(int i = 0; i < B_rownum; i++) {
            printf("Here input the row of %d: ", i + 1);
            for(int j = 0; j < B_colnum; j++) {
                cin >> B[i][j];
            }
        }
        printf("\nConfirm your input (if incorrect press 'r' to re-enter, any other key to continue): \n");
        Visualize_process(A, B);
        cin >> choice;
    } while(choice == 'r' || choice == 'R');
}

void Show_Multiply(vector<vector<float>> &A, vector<vector<float>> &B, vector<vector<float>> &R) {
    printf("The Multiplier Result is: \n");
    for(int i = 0; i < A_rownum; i++) {
        if(i == 0) {
            printf("A =");
        }
        else {
            printf("   "); 
        }
        for(int j = 0; j < B_colnum; j++) {
            for(int k = 0; k < A_colnum; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
            cout << setw(5) << R[i][j];
        }
        cout << endl;
    }
}

int main() {
    vector<vector<float>> A(A_rownum, vector<float>(A_colnum, 0.0));
    vector<vector<float>> B(B_rownum, vector<float>(B_colnum, 0.0));
    vector<vector<float>> R(A_colnum, vector<float>(B_rownum, 0.0));
    Input_Matrix(A, B);
    Show_Multiply(A, B ,R);
    return 0;
}