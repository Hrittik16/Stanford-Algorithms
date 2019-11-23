#include <iostream>
using namespace std;

void merge(int* arr, int beg, int mid, int end) {
	int i = beg, j = mid+1, k = 0;
	int c[end-beg+1];
	while(i <= mid && j <= end) {
		if(arr[i] <= arr[j]) {
			c[k] = arr[i];
			k++;
			i++;
		}	
		else if(arr[j] <= arr[i]){
			c[k] = arr[j];
			k++;
			j++;
		}		
	}
	while(i <= mid) {
		c[k] = arr[i];
		k++;
		i++;
	}
	while(j <= end) {
		c[k] = arr[j];
		k++;
		j++;
	}
	for(i = beg; i <= end; i++)
		arr[i] = c[i-beg];
}

// The mergesort function recursively breaks the array
// into two subarrays and the merge function merges
// the two subarrays in sorted order
void mergesort(int* arr, int beg, int end) {
	if(beg < end) {
		int mid = beg+(end-beg)/2;
		mergesort(arr, beg, mid);
		mergesort(arr, mid+1, end);
		merge(arr, beg, mid, end);
	}
}

int main() {
	int n;
	cout << "Enter size of array : ";
	cin >> n;
	int arr[n];
	cout << "Enter elements of array : \n";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	mergesort(arr, 0, n-1);
	
	cout << "Array is Sorted\n";
	for(int j = 0; j < n; j++) 
		cout << arr[j] << " ";
	cout << "\n";
	return 0;
}
