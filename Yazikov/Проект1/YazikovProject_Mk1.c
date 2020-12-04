#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

int Linear_search(int *A, int n)
{
	int i, p;
	int sw = 0;
	printf("������� ������� ��� ������\n");
	scanf_s("%d", &p);
	for (i = 0; i < n; i++)
	{
		if (A[i] == p)
		{
			return i;
			sw = 1;
		}
	}
	if (sw = 0)
	{
		return -1;
	}
}

void Count_sort(int *A, int n, int a, int b)
{
	int i,j;
	int *R = malloc((b - a + 1) * sizeof(int));
	for (i = 0; i < (b - a); i++)
		R[i] = 0;
	for (i = 0; i < n; i++)
	{
		R[A[i] - a]++;
		A[i] = 0;
	}
	j = 0;
	for (i = 0; i < (b - a); i++)
	{
		while (R[i] > 0)
		{
			A[j] = (i + a);
			j++;
			R[i]--;
		}
	}
	free(R);
}

int* Merge_sort(int *X, int *Y, int a, int b)
{
	int mid;
	if (a == b)
	{
		Y[a] = X[a];
		return Y;
	}
	mid = (a + b) / 2;
	int *left = Merge_sort(X, Y, a, mid);
	int *right = Merge_sort(X, Y, mid + 1, b);

	int *target = left == X ? Y : X;

	int l_cur = a, r_cur = mid + 1;
	for (int i = a; i <= b; i++)
	{
		if (l_cur <= mid && r_cur <= b)
		{
			if (left[l_cur] < right[r_cur])
			{
				target[i] = left[l_cur];
				l_cur++;
			}
			else
			{
				target[i] = right[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= mid)
		{
			target[i] = left[l_cur];
			l_cur++;
		}
		else
		{
			target[i] = right[r_cur];
			r_cur++;
		}
	}
	return target;
}

void SortBubble(int* A, int n)
{
	int tmp, i, j;
	char bl;
	for (i = 0; i < n; i++)
	{
		bl = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j + 1] < A[j])
			{
				tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
				bl = 1;
			}
		}
		if (bl = 0)
			break;
	}
}

void ItemList()
{
	printf("\nMenu:\n");
	printf("1)������� ������\n");
	printf("2)����������� ������\n");
	printf("3)���������� ���������\n");
	printf("4)���������� ���������\n");
	printf("5)���������� ��������\n");
	printf("6)���������� ���������\n");
	printf("7)�������� ����� ��������� �����\n");
	printf("0)�����\n");
}

int randArray(int B[], int n, int a, int b)
{
	int i, was_filled;
	was_filled = 0;
	printf("������� ������ �������\n");
	scanf_s("%d", &a);
	printf("������� ������� �������\n");
	scanf_s("%d", &b);
	if (a <= b)
	{
		for (i = 0; i < n; i++)
			B[i] = rand() % (b - a) + a;
		was_filled = 1;
	}
	else printf("������� ������� �� ������ ���� ������ ������");
	return was_filled;
}

void print(int B[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d  ", B[i]);
	printf("\n");
}

int Check(int *B, int n)
{
	int f = 1;
	int i;
	for (i = 0; i < n - 1; i++)
	{
		if (B[i + 1] < B[i])
		{
			f = 0;
			break;
		}
	}
	return f;
}

void SortByInserts(int* A, int n)
{
	int i, tmp, z;
	for (i = 1; i < n; i++)
	{
		tmp = A[i];
		z = i;
		while ((z > 0) && (A[z - 1] > tmp))
		{
			A[z] = A[z - 1];
			z--;
		}
		A[z] = tmp;
	}
}

void main()
{
	int B[100];
	int Bb[100];
	int n = 100;
	int t = 10;
	int indexInput, wasfound;
	int lb = 0, rb = 0;
	setlocale(LC_CTYPE, "Russian");
	printf("start\n");
	srand(1000);
	indexInput = 0;
	while (t > 0)
	{
		ItemList();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			indexInput = randArray(B, n, lb, rb);
			break;
		}
		case 2:
		{
			if (indexInput == 1)
				print(B, n);
			else printf("������ �����������\n");
			break;
		}
		case 3:
		{
			if (indexInput == 1)
			{
				SortBubble(B, n);
				print(B, n);
			}
			else printf("������ �����������\n");
			break;
		}
		case 4:
		{
			if (indexInput == 1)
			{
				SortByInserts(B, n);
				print(B, n);
			}
			else printf("������ �����������\n");
			break;
		}
		case 5:
		{
			if (indexInput == 1)
			{
				Merge_sort(B, Bb, 0, n-1);
				print(B, n);
			}
			else printf("������ �����������\n");
			break;
		}
		case 6:
		{
			if (indexInput == 1)
			{
				Count_sort(B, n, lb, rb);
				print(B, n);
			}
			else printf("������ �����������\n");
			break;
		}
		case 7:
		{
			if (indexInput == 1)
			{
				wasfound = Linear_search(B, n);
				if (wasfound > -1)
					printf("������� ��������� �� %d �������\n", wasfound+1);
				else printf("������� �� ������\n");
			}
		}
		}
	}
}