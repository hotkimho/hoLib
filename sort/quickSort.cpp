#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

// 5 4 7 2 3 4 5 6 7 8 
int partition(int arr[], int start, int end)
{
	int pivot = (start + end) / 2;
	int i,j;

	i = j = 0;

	while (start < end)
	{
		while (arr[start] < arr[pivot])
			start++;
		while (arr[end] > arr[pivot])
			end--;
		if (start < end){
			swap(&arr[start], &arr[end]);
			start += 1;
			end -= 1;
		}
	}
	return end;
}
void quickSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int p = partition(arr, start, end);

		quickSort(arr, start, p - 1);
		quickSort(arr, p + 1, end);
	}
}
int main()
{
	int T;
	int arr[1002];

	cin >> T;
	for(int i=0; i<T; i++)
		cin>>arr[i];
	
	quickSort(arr,0,T -1);
	for(int i=0; i<T; i++)
		cout<<arr[i]<<endl;

}
