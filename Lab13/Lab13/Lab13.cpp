#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int** MakeMatr(int m, int n)
{
	int** t;
	t = new int*[m];
	for (int i = 0; i < m; i++)
	{
		t[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			t[i][j] = rand() % 20 - 10;
		}
	}
	return t;
}

void PrintMatr(int m, int n, int** matr)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(4);
			cout << matr[i][j];
		}
		cout << endl;
	}
}

int* MakeArray(int m, int n, int** matr)
{
	int* arr = new int[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = 0;
		for (int j = 0; j < n; j++)
		{
			if ((matr[i][j] < 0) && (matr[i][j] % 3 == 0))
			{
				arr[i]++;
			}
		}
	}
	return arr;
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int M, N;
	cout << "Введите размерности матрицы: ";
	cin >> M >> N;
	int** A;
	A = MakeMatr(M, N);
	PrintMatr(M, N, A);
	int* B = MakeArray(M, N, A);
	cout << "Результат:\n";
	for (int i = 0; i < M; i++)
	{
		cout << B[i] << ' ';
		cout << endl;
	}
	system("pause");
}