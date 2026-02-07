#include <stdio.h>
#include <string.h>

#define SIZE 10

long comp_first = 0;
long comp_mid = 0;


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition_first(int a[], int left, int right)
{
	int pivot = a[left];
	int low = left + 1, high = right;

	while (low <= high)
	{
		while (low <= right && (++comp_first && a[low] <= pivot))low++;
		while (++comp_first && a[high] > pivot)high--;
		if (low < high)swap(&a[low], &a[high]);
	}
	swap(&a[left], &a[high]);
	return high;
}

void quick_first(int a[], int left, int right)
{
	if (left < right)
	{
		int q = partition_first(a, left, right);
		quick_first(a, left, q - 1);
		quick_first(a, q + 1, right);
	}
}


int partition_mid(int a[], int left, int right)
{
	int mid = (left + right) / 2;
	swap(&a[left], &a[mid]);
	int pivot = a[left];


	int low = left + 1, high = right;
	while (low <= high)
	{
		while (low <= right && (++comp_mid && a[low] <= pivot))low++;
		while (++comp_mid && a[high] > pivot)high--;
		if (low < high)swap(&a[low], &a[high]);
	}
	swap(&a[left], &a[high]);
	return high;
}

void quick_mid(int a[], int left, int right)
{
	if (left < right)
	{
		int q = partition_mid(a, left, right);
		quick_mid(a, left, q - 1);
		quick_mid(a, q + 1, right);
	}
}


int main() 
{
	int sorted[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = sorted[i];
	}

	quick_first(arr, 0, SIZE - 1);
	printf("First Pivot Comparisons: %ld\n", comp_first);

	memcpy(arr, sorted, sizeof(sorted));
	quick_mid(arr, 0, SIZE - 1);
	printf("Middle Pivot Comparisons: %ld\n", comp_mid);

	return 0;
}