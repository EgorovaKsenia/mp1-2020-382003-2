#include "stdio.h"
#include "stdlib.h"

void randArray(int* B, int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}

void print(int* B, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%3d ", B[i]);
	printf("\n");
}

// A[i, j] = A[i, j] + A2[i, j]
void MatPlusEq(int* A, int* A2, int n, int m)
{
	int size = n * m;
	int i;
	for (i = 0; i < size; i++)
		A[i] += A2[i];
}

// A[i, j] = A[i, j] + A2[i, j]
void MatPlusEq2(int* A, int* A2, int n, int m)
{
	int i, j;
	// [i, j] --> [i*m + j]
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			A[i * m + j] += A2[i * m + j];
}

void Print2D(int* B, int n, int m)
{
	int i;
	for (i = 0; i < n; i++)
		print(&(B[i * m]), m);
	printf("\n");
}

void RandArray2d(int** A, int n, int m, int a1, int b1)
{
	int i;
	for (i = 0; i < n; i++)
		randArray(A[i], m, a1, b1);
}

void RandArray2d_2(int** A, int n, int m, int a1, int b1)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			A[i][j] = rand() % (b1 - a1) + a1;
}

void Print2D_2(int** A, int n, int m)
{
	int i;
	for (i = 0; i < n; i++)
		print(A[i], m);
	printf("\n");
}

void Print2D_3(int** A, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	printf("\n");
}

// ��� �������� int** �� ������
void Malloc2d(int*** A, int n, int m)
{	//��������� ������
	int i;
	// *A  - ��� int**
	*A = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		(*A)[i] = (int*)malloc(sizeof(int) * m);
}

void Free2d(int*** A, int n)
{
	int i;
	// *A  - ��� int**
	for (i = 0; i < n; i++)
		free((*A)[i]);
	free(*A);
}

// �[i][j] = summ(A[i][k]*B[k][j]) 
void MatMult(int** A, int** B, int** C, int n, int m, int l)
{
	// A ������� n * m
	// B ������� m * l
	// � ������� n * l
	int i, j, k, sum;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < l; j++)
		{
			sum = 0;
			for (k = 0; k < m; k++)
				sum += A[i][k] * B[k][j];
			C[i][j] = sum;
		}
	}
}

int SumDiag(int** M, int n, int shift)
{
	int i, j;
	int sum = 0;
	for (i = 0; i < n - shift; i++)
		sum += M[i][i + shift];
	return sum;
}

void main()
{
	int* B, *B2;
	int n = 2, m = 3, l = 4;
	int i, j;
	int** A;
	int** A2;
	int** C;
	/*
	// ������ 1
	// ������� ������� n * m
	B = (int*)malloc(sizeof(int) * n * m);
	B2 = (int*)malloc(sizeof(int) * n * m);
	randArray(B, n * m, -5, 30);
	randArray(B2, n * m, 2, 17);
	// [i, j] --> [i*m + j]
	// 0� ������ � 0 �� m - 1 ���
	//1� ������ � m �� m + m - 1 = 2m-1
	Print2D(B, n, m);
	Print2D(B2, n, m);
	MatPlusEq2(B, B2, n, m);
	Print2D(B, n, m);
	free(B);
	free(B2);
	*/
	// ������ ��������
/*	//��������� ������
	A = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		A[i] = (int*)malloc(sizeof(int) * m);
*/	
	Malloc2d(&A, n, m);
	Malloc2d(&A2, m, l);
	Malloc2d(&C, n, l);

	// A[i, j] --> A[i][j]
	// ������� �� ������ 3 ������� 2 --> A[3][2]
	RandArray2d(A, n, m, -1, 5);
	Print2D_2(A, n, m);
	
	RandArray2d(A2, m, l, -1, 5);
	Print2D_2(A2, m, l);

	MatMult(A, A2, C, n, m, l);
	Print2D_2(C, n, l);

	Free2d(&A, n);
	Free2d(&A2, m);
	Free2d(&C, n);

	// ����� ��������� �� ����������
	{
		int** M;
		int n = 5;
		int sum;
		Malloc2d(&M, n, n);
		RandArray2d(M, n, n, -1, 5);
		Print2D_2(M, n, n);

		sum = SumDiag(M, n, 2);
		printf("sum = %d\n", sum);

		Free2d(&M, n);
	}

	// ���������� ������
	//for (i = 0; i < n; i++)
	//	free(A[i]);
	//free(A);

	//for (i = 0; i < n; i++)
	//	free(A2[i]);
	//free(A2);

}