/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Zahari Zvezdomirov
* @idnumber 62216
* @task 2
* @compiler VC
*
*/


#include <iostream>

#define N 3

//I put those in a separate header file, but
//the homework requirement is .cpp files only,
//so I pasted the function declarations here.

void swap(double&, double&);
void displayMatrix(double M[N][N]);
void sumSquareMatrices(double A[N][N], double B[N][N], double C[N][N]);
void transposeSquareMatrix(double matrix[N][N], double transposed[N][N]);
void solveMatrixEquation(double A[N][N], double C[N][N], double result[N][N]);
void multiplySquareMatrices(double mA[N][N], double mB[N][N], double result[N][N]);
void getCofactor(double M[N][N], double temp[N][N], int p, int q, int n);
double determinant(double M[N][N], int n);
void getAdjoint(double M[N][N], double adj[N][N]);
bool inverse(double M[N][N], double inversed[N][N]);

int main()
{
	const int M_SIZE = 3;

	double A[M_SIZE][M_SIZE] = { 
	{-4, 1, 1},
	{1, -3, 2},
	{1, 2, -4}
	};

	double C[M_SIZE][M_SIZE] = {
	{-1, -2, -2},
	{-1, -3, -4},
	{-1, -3, -5}
	};

	double X[M_SIZE][M_SIZE];

	solveMatrixEquation(A, C, X);
	displayMatrix(X);
}

void solveMatrixEquation(double A[N][N], double C[N][N], double result[N][N])
{
	// XA = scalar2 * (A(t) * C) - scalar1*X
	// X(A + scalar1) = scalar2 * (A(t) * C)
	// X = scalar2 * (A(t) * C) * inverse((A + scalar1))

	//defining the two scalars from the equation as
	//diagonal matrices
	double scalar1[3][3] = { {5, 0, 0}, {0, 5, 0}, {0, 0, 5} };
	double scalar2[3][3] = { {-3, 0, 0}, {0, -3, 0}, {0, 0, -3} };

	double transposedA[N][N];
	double AplusSc1[N][N];
	double AtC[N][N];
	double sc2AtC[N][N];
	double inverseOfAplusSc1[N][N];

	transposeSquareMatrix(A, transposedA);
	sumSquareMatrices(A, scalar1, AplusSc1);
	multiplySquareMatrices(A, C, AtC);
	multiplySquareMatrices(scalar2, AtC, sc2AtC);

	inverse(AplusSc1, inverseOfAplusSc1);

	multiplySquareMatrices(sc2AtC,inverseOfAplusSc1, result);
}

//temp is to store the cofactor, p and q are the row and col of the element,
//n is the current size of M
void getCofactor(double M[N][N], double temp[N][N], int p, int q, int n)
{
	int i = 0;
	int j = 0;

	for (int rows = 0; rows < n; rows++)
	{
		for (int cols = 0; cols < n; cols++)
		{
			if (rows != p && cols != q)
			{
				temp[i][j++] = M[rows][cols];
			}

			if (j == n - 1)
			{
				j = 0;
				i++;
			}
		}
	}
}

double determinant(double M[N][N], int n)
{
	double D = 0;

	//Recursion base case
	if (n == 1)
	{
		D = M[0][0];
	}

	double temp[N][N]; //to store the cofactors
	int sign = 1; 

	//process determinant by first row
	for (int i = 0; i < n; i++)
	{
		getCofactor(M, temp, 0, i, n);
		D += sign * M[0][i] * determinant(temp, n - 1);
		
		sign = -sign;
	}

	return D;
}

void getAdjoint(double M[N][N], double adj[N][N])
{
	if (N == 1)
	{
		adj[0][0] = 1;
		return;
	}

	// temp is used to store cofactors of M[][]
	double temp[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// Get cofactor of M[i][j] 
			getCofactor(M, temp, i, j, N);

			// sign of adj[j][i] positive if sum of row 
			// and column indexes is even. 

			// Interchanging rows and columns to get the 
			// transpose of the cofactor matrix 
			adj[j][i] = pow(-1, i + j) * (determinant(temp, N - 1));
		}
	}
}

bool inverse(double M[N][N], double inverse[N][N])
{
	// Find determinant of M[][] 
	double det = determinant(M, N);
	if (det == 0)
	{
		std::cout << "The matrix is singular, therefore has no inverse!";
		return false;
	}

	// Find adjoint 
	double adj[N][N];
	getAdjoint(M, adj);

	// Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			inverse[i][j] = adj[i][j] / float(det);

	return true;
}

void sumSquareMatrices(double mA[N][N], double mB[N][N], double result[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[i][j] = (mA[i][j] + mB[i][j]);
		}
	}
}

void multiplySquareMatrices(double mA[N][N], double mB[N][N], double result[N][N])
{
	double tempSum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			for (int j = 0; j < N; j++)
			{
				tempSum += (mA[i][j] * mB[j][k]);
			}
		result[i][k] = tempSum;
		tempSum = 0;
		}
	}
}

void transposeSquareMatrix(double matrix[N][N], double transposed[N][N])
{
	//fill the new matrix
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			transposed[i][j] = matrix[i][j];
		}
	}
	//transpose the matrix
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			swap(transposed[i][j], transposed[j][i]);
		}
	}

}

void displayMatrix(double M[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << std::round(M[i][j]) << " ";
		}
		std::cout << std::endl;
	}
}

void swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}