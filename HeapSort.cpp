/**
 * heapsort.cpp - программа для сортировки чисел с помощью алгоритма сортировки кучей
 *
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <fstream>

using namespace std;

void pushDown(int i, int n, int* A)
{
	int j;
	while (i <= n / 2) {
		if ((2 * i == n) || (A[2 * i - 1] > A[2 * i])) {
			j = 2 * i;
		}
		else {
			j = 2 * i + 1;
		}
		if (A[i - 1] < A[j - 1]) {
			swap(A[i - 1], A[j - 1]);
			i = j;
		}
		else {
			break;
		}
	}
}

void heapSort(int n, int* A)
{
	for (int i = n / 2; i >= 1; i--) {
		pushDown(i, n, A);
	}
	for (int i = n; i >= 2; i--) {
		swap(A[0], A[i - 1]);
		pushDown(1, i - 1, A);
	}
}

int main()
{
	ifstream fin("input.txt");
	int n;
	fin >> n;
	int *A = new int[n];
	for (int i = 0; i < n; i++) {
		fin >> A[i];
	}
	fin.close();

	heapSort(n, A);

	ofstream fout("output.txt");
	for (int i = 0; i < n; i++) {
		fout << A[i] << " ";
	}
	fout.close();

	delete[] A;

	return 0;
}