// Matrix checker - Devaraja G (CB.EN.U4.CSE20614)

// Functions:
/*
Check whether a given 2D array is
1. Square matrix
2. Unit matrix
3. Upper/lower triangular matrix
4. Diagonal matrix
5. Scalar matrix
6. Transpose of a matrix
7. Row Sum/Column sum
*/

#include<stdio.h>
#include<stdbool.h>
#include<time.h>

//Misc Functions
int genRandom(int lower, int upper)
{
	return  (rand() % (upper - lower + 1)) + lower;
}

void printMat(int m, int n, int mat[m][n]){
	int i,j;
	printf("\nMatrix: \n");
	for (i=0; i<m;i++){
		for (j=0; j<n;j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//Square matrix checker
int squareMatrix(int m, int n){
	if (m==n){
		printf("Square Matrix: True");
	}
	else{
		printf("Square Matrix: False");
	}
	return 0;
}

//Unit matrix checker
int unitMatrix(int m, int n, int matrix[m][n]){
	int verdict=1;
	int i,j;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if (i==j){
				if (matrix[i][j]!=1){
					verdict=0;
					break;
				}
			}
			else{
				if (matrix[i][j]!=0){
					verdict=0;
					break;
				}
			}
		}
	}
	if (verdict==1){
		printf("Unit matrix: True");
	}
	else {
		printf("Unit matrix: False");
	}
	return 0;
}

//Upper triangular matrix
int upperMatrix(int m,int n,int matrix[m][n]){
	int upcheck=1;
	int i,j;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if(i<j){
				if(matrix[i][j]!=0){
					upcheck=0;
					break;
				}
			}
		}
	}
	if (upcheck==1){
		printf("Upper = True");
	}
	else{
		printf("Upper = False");
}
return 0;}

//Lower Triangular
int lowerMatrix(int m,int n,int matrix[m][n]){
	int lowcheck=1;
	int i,j;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if(i>j){
				if(matrix[i][j]!=0){
					lowcheck=0;
					break;
				}
			}
		}
	}
	if (lowcheck==1){
		printf("Lower = True");
	}
	else{
		printf("Lower = False");
}
return 0;}

//Diagoanl matrix
int diagonalMatrix(int m,int n,int matrix[m][n]){
	int verdict=1;
	int i,j;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if(i==j){
				if(matrix[i][j]==0){
					verdict=0;
					break;
				}
			}
			else{
				if(matrix[i][j]!=0){
					verdict=0;
					break;
				}
			}
		}
	}
	if (verdict==1){
		printf("Diagonal matrix: True");
	}
	else{
		printf("Diagonal matrix: False");
	}
	return 0;
}

//Scalar matrix
int scalarMatrix(int m,int n,int matrix[m][n]){
	int a=matrix[0][0];
	int verdict=1;
	int i,j;
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			if (i==j){
				if (matrix[i][j]!=a){
					verdict=0;
					break;
				}
			}
		}
	}
	if (verdict==1){
		printf("Scalar matrix: True");
	}
	else{
		printf("Scalar matrix: False");
	}
	return 0;
}

//Transpose
int transposeMatrix(int m,int n,int matrix[m][n]){
	printf("Transpose: \n");
	int i,j;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf("%d ",matrix[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

//Row sum
int rowSum(int m, int n, int matrix[m][n]){
	printf("Row sums: \n");
	int i,j;
	for (i=0;i<m;i++){
		int sum=0;
		for (j=0;j<n;j++){
			sum+=matrix[i][j];
		}
		printf("Row %d: %d\n",i+1,sum);
	}
	return 0;
}

//Coulmn Sum
int colSum(int m, int n, int matrix[m][n]){
	printf("Column sums: \n");
	int i,j;
	for (i=0;i<n;i++){
		int sum=0;
		for (j=0;j<m;j++){
			sum+=matrix[j][i];
		}
		printf("Column %d: %d\n",i+1,sum);
	}
	return 0;
}

//User entered matrix
int choice1(){
	int m,n,i,j;
	printf("\nEnter number of rows: ");
	scanf("%d", &m);
	printf("\nEnter number of columns: ");
	scanf("%d", &n);
	printf("\nEnter elements: \n");
	int matrix[m][n];
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			int a;
			printf("[%d][%d]: ", i+1,j+1);
			scanf("%d", &a);
			matrix[i][j]=a;
		}
	}
	
	printMat(m,n,matrix);
	
	squareMatrix(m,n);
	printf("\n");
	unitMatrix(m,n,matrix);
	printf("\n");
	upperMatrix(m,n,matrix);
	printf("\n");
	lowerMatrix(m,n,matrix);
	printf("\n");
	diagonalMatrix(m,n,matrix);
	printf("\n");
	scalarMatrix(m,n,matrix);
	printf("\n\n");
	transposeMatrix(m,n,matrix);
	printf("\n\n");
	rowSum(m,n,matrix);
	printf("\n\n");
	colSum(m,n,matrix);
	
	printf("\n\n");
	return 0;
}

//Random matrix
int choice2(){
	int m=genRandom(2,5); // The size is random between 2 to 5 in order to increase the probality of hitting a square matrix
	int n=genRandom(2,5);
	int matrix[m][n]; // mxn matrix;
	int i,j;
	for (i=0; i<m;i++){
		for (j=0;j<n; j++){
			matrix[i][j]=genRandom(0,9); // Elements for between 0-9, change thisline to use custom limits
		}
	}
	
	printMat(m,n,matrix);
	
	squareMatrix(m,n);
	printf("\n");
	unitMatrix(m,n,matrix);
	printf("\n");
	upperMatrix(m,n,matrix);
	printf("\n");
	lowerMatrix(m,n,matrix);
	printf("\n");
	diagonalMatrix(m,n,matrix);
	printf("\n");
	scalarMatrix(m,n,matrix);
	printf("\n\n");
	transposeMatrix(m,n,matrix);
	printf("\n\n");
	rowSum(m,n,matrix);
	printf("\n\n");
	colSum(m,n,matrix);
	
	printf("\n\n");
	return 0;
}

int main(){
	bool a=true;
	while(a){
		printf("MATRIX CHECKER \n Press 1 to enter matrix\n Press 2 to generate random matrix \n Press 3 to quit");
		int inp;
		printf("\nEnter choice: ");
		scanf("%d", &inp);
		if(inp==3){
			a=false;
			continue;
		}
		else if(inp==2){
			choice2();
		}
		else if(inp==1){
			choice1();
		}
		else{
			printf("Error: Enter Valid input\n");
		}
	}
	return 0;
}

