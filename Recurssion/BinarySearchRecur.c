#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
	if (first > last)
		return -1; // target value does not exist
	
	int mid = (first + last) / 2;
	if (ar[mid] == target)
		return mid;
	else if (ar[mid] < target)
		BSearchRecur(ar, mid+1, last, target);
	else
		BSearchRecur(ar, first, mid-1, target);
}

int main(void)
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 8);
	
	if (idx == -1)
		printf("target value does not exist!@\n");
	else 
		printf("target exists at index %d\n", idx);
	
	return 0;
	
}