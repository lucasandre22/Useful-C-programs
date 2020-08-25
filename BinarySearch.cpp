#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 80000
using namespace std;

int binarySearch(int vetor[], int size, int key)
{
	int middle;
	int right = size-1;
	int left = 0;
	while (left <= right)
	{
		middle = (right + left)/2;
		if (vetor[middle] > key)
			right = middle - 1;
		else if (vetor[middle] == key)
			return 1;
		else
			left = middle + 1;
	}
	return 0;
}

int sequencialSearch(int vetor[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (vetor[i] == key)
			return 1;
		else if (vetor[i] > key)
			return 0;
	}
}

int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > * y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}

int main() 
{
	int vetor[SIZE];
	float start;
	float end;
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		vetor[i] = rand() % 1000000;
	}
	qsort(vetor, TAM, sizeof(int), compare);
	start = (float)clock();
	for(int i = SIZE; i > 0; i--)
		binarySearch(vetor, SIZE, i);
	end = (float)clock();
	printf("Binary search finished, it took %.3f seconds.\n", ((end - start) / CLOCKS_PER_SEC));
	start = (float)clock();
	for (int i = SIZE; i > 0; i--)
		sequencialSearch(vetor, SIZE, i);
	end = (float)clock();
	printf("Sequential search finished, it took %.3f seconds.\n", ((end - start) / CLOCKS_PER_SEC));
	system("PAUSE");
	return 0;
}
