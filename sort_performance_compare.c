#include <stdio.h>
#include<string.h>

#define SIZE 10


long sel_comp = 0, sel_swap = 0;
long quick_comp = 0, quick_swap = 0;
long merge_comp = 0;



void selectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			sel_comp++;
			if (a[j] < a[min])
				min = j;
		}

		if (min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
			sel_swap++;
		}
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	quick_swap++;
}

int partition(int a[], int left, int right)
{
	int pivot = a[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= right && (++quick_comp && a[low] <= pivot))
			low++;
		while (++quick_comp && a[high] > pivot)
			high--;

		if (low < high)
			swap(&a[low], &a[high]); 
	}
	swap(& a[left], & a[high]);
	return high;
}

void quickSort(int a[], int left, int right)
{
	if (left < right)
	{
		int q = partition(a, left, right);
		quickSort(a, left, q - 1);
		quickSort(a, q + 1, right);
	}
}

void merge(int a[], int left, int mid, int right)
{
	int temp[SIZE];
	int i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		merge_comp++;
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= right)
		temp[k++] = a[j++];

	for (int t = left; t <= right; t++)
		a[t] = temp[t];
}

void mergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		mergeSort(a, left, mid, right);
	}
}


void printResult(char* name, long comp, long swap)
{
	printf("[%s]\n", name);
	printf("Comparisons: %ld\n", comp);
	if (swap >= 0)
		printf("Swaps: %ld\n\n", swap);
	else
		printf("Swaps: (N/A)\n\n");
}

int main() 
{
	int original[SIZE] = { 9,3,7,1,6,2,8,5,4,0 };
	int arr[SIZE];

	memcpy(arr, original, sizeof(original));
	selectionSort(arr, SIZE);
	printResult("Selection", sel_comp, sel_swap);

	memcpy(arr, original, sizeof(original));
	quickSort(arr, 0, SIZE - 1);
	printResult("Quick", quick_comp, quick_swap);

	memcpy(arr, original, sizeof(original));
	mergeSort(arr, 0, SIZE - 1);
	printResult("Merge", merge_comp, -1);

	return 0;
}