#include <iostream>
using namespace std;

int r1, c1, r2, c2, n, m;

void matrix_in(int choice);
void add_matrix(int matrix1[4][4], int matrix2[4][4], int n);
void subtract_matrix(int matrix1[4][4], int matrix2[4][4], int n);
void multiply_matrix(int matrix1[100][100], int matrix2[100][100], int r1, int r2, int c1, int c2);

int choice(){
	cout << "Enter what calculation you would like to perform on your matrix:" << endl;
	cout << "1. Addition\n2. Subtraction\n3. Multiplication\n";
	int select;
	do{
		cin >> select;
	}while (select>3||select<1);
	return select;
}


int main(){
	cout << "Welcome to Matrix Calculator!" << endl;
	cout << "-----------------------------" << endl;
	int ch=choice();
	matrix_in(ch);
	
}

void matrix_in(int choice){
	int n=0;
	if (choice==1||choice==2){
		int num;
		cout << "Choose the matrix size:\n1. 2x2\n2. 3x3\n3, 4x4\n";
		cin >> num;
		int matrix1[4][4]={0};
		int matrix2[4][4]={0};
		if (num==1){
			n=2;
			cout << "Enter values of Matrix 1, from left to right." << endl;
			for (int i=0; i<n; i++){
				cout << "Row" << i+1 << endl;
				for (int j=0; j<n; j++){
					cin >> matrix1[i][j];
				}
				cout << endl;
			}
			cout << "Enter values of Matrix 2, from left to right." << endl;
			for (int i=0; i<n; i++){
				cout << "Row" << i+1 << endl;
				for (int j=0; j<n; j++){
					cin >> matrix2[i][j];
				}
				cout << endl;
			}
		}
		if (num==2){
			n=3;
			cout << "Enter values of Matrix 1, from left to right." << endl;
			for (int i=0; i<n; i++){
				cout << "Row" << i+1 << endl;
				for (int j=0; j<n; j++){
					cin >> matrix1[i][j];
				}
				cout << endl;
			}
			cout << "Enter values of Matrix 2, from left to right." << endl;
			for (int i=0; i<n; i++){
				cout << "Row" << i+1 << endl;
				for (int j=0; j<n; j++){
					cin >> matrix2[i][j];
				}
				cout << endl;
			}
		}
		if (num==3){
			n=4;
			cout << "Enter values of Matrix 1, from left to right." << endl;
			for (int i=0; i<n; i++){
				cout << "Row" << i+1 << endl;
				for (int j=0; j<n; j++){
					cin >> matrix1[i][j];
				}
				cout << endl;
			}
			cout << "Enter values of Matrix 2, from left to right." << endl;
			for (int i=0; i<n; i++){
				cout << "Row" << i+1 << endl;
				for (int j=0; j<n; j++){
					cin >> matrix2[i][j];
				}
				cout << endl;
			}
		}
		if (choice == 1){
			add_matrix(matrix1, matrix2, n);
		}
		if (choice == 2){
			subtract_matrix(matrix1, matrix2, n);
		}
	}
	if (choice==3){
		cout << "Enter the size of Matrix 1:\n";
		cout << "Rows: ";
		cin >> r1;
		cout << "Columns: ";
		cin >> c1;
		cout << "Enter the size of Matrix 2:\n";
		cout << "Rows: ";
		cin >> r2;
		cout << "Columns: ";
		cin >> c2;
		while (c1!=r2){
			cout << "Oops! The number of columns in the first matrix should match the number of rows in the second matrix.\n Try Agsin\n";
			cout << "Matrix 1 Columns: ";
			cin >> c1;
			cout << "Matrix 2 Rows: ";
			cin >> r2;
		}
		int matrix1[100][100]={0};
		int matrix2[100][100]={0};
		cout << "Enter values of Matrix 1, from left to right." << endl;
		for (int i=0; i<r1; i++){
			cout << "Row" << i+1 << endl;
			for (int j=0; j<c1; j++){
				cin >> matrix1[i][j];
			}
			cout << endl;
		}
		cout << "Enter values of Matrix 2, from left to right." << endl;
		for (int i=0; i<r2; i++){
			cout << "Row" << i+1 << endl;
			for (int j=0; j<c2; j++){
				cin >> matrix2[i][j];
			}
			cout << endl;
		}
		multiply_matrix(matrix1, matrix2, r1, r2, c1, c2);
	}
}

void add_matrix(int matrix1[4][4], int matrix2[4][4], int n){
	int res_matrix[4][4] = {0};
	for (int a=0; a<n; a++){
		for (int b=0; b<n; b++){
			res_matrix[a][b] = matrix1[a][b] + matrix2[a][b]; 
		}
	}
	cout << endl << "RESULTANT MATRIX: " << endl;
	for (int c=0; c<n; c++){
		for (int d=0; d<n; d++){
			cout << res_matrix[c][d] << "\t";
		}
		cout << endl;
	}
}

void subtract_matrix(int matrix1[4][4], int matrix2[4][4], int n){
	int res_matrix[4][4] = {0};
	for (int a=0; a<n; a++){
		for (int b=0; b<n; b++){
			res_matrix[a][b] = matrix1[a][b] - matrix2[a][b]; 
		}
	}
	cout << endl << "RESULTANT MATRIX: " << endl;
	for (int c=0; c<n; c++){
		for (int d=0; d<n; d++){
			cout << res_matrix[c][d] << "\t";
		}
		cout << endl;
	}
}

void multiply_matrix(int matrix1[100][100], int matrix2[100][100], int r1, int r2, int c1, int c2){
	int res_matrix[r1][c2] = {0};
	for (int x=0; x<r1; x++){
		for(int y=0; y<c2; y++){
			for (int z=0; z<c1; z++){
				res_matrix[x][y] = res_matrix[x][y] + (matrix1[x][z]*matrix2[z][y]);
			}
		}
	}
	
	cout << endl << "RESULTANT MATRIX" << endl;
	for (int a=0; a<r1; a++){
		for (int b=0; b<c2; b++){
			cout << res_matrix[a][b] << "\t";
		}
		cout << endl;
	}
}
