#include <stdio.h>
#include<string.h>

#define SIZE 6


typedef struct
{
	int score;
	char name[20];
}Student;


void merge(Student a[], int left, int mid, int right)
{
	Student temp[SIZE];
	int i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		if (a[i].score <= a[j].score)
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= mid)temp[k++] = a[i++];
	while (j <= right)temp[k++] = a[j++];

	for (int t = left; t <= right; t++)
		a[t] = temp[t];
}

void mergeSort(Student a[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		mergeSort(a, left, mid, right);
	}
}


void swap(Student* a, Student* b)
{
	Student temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(Student a[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1, right = 2 * i + 2;

	if (left<n && a[left].score>a[largest].score)
		largest = left;
	if (right<n && a[right].score>a[largest].score)
		largest = right;

	if (largest != i)
	{
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}


void heapSort(Student a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		heapify(a, i, 0);
	}
}

void print(Student a[])
{
	for (int i = 0; i < SIZE; i++)
		printf("(%d, %s) ", a[i].score, a[i].name);
	printf("\n");
}

int main()
{
	Student data[SIZE] = 
	{
		{90,"A"}, {80,"B"}, {90,"C"},
		{70,"D"}, {80,"E"}, {90,"F"}
	};

	Student arr1[SIZE], arr2[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		arr1[i] = data[i];
	}

	for (int i = 0; i < SIZE; i++)
	{
		arr2[i] = data[i];
	}

	printf("Merge Sort (Stable):\n");
	mergeSort(arr1, 0, SIZE - 1);
	print(arr1);

	printf("Heap Sort (Unstable):\n");
	heapSort(arr2, SIZE);
	print(arr2);

	return 0;
}