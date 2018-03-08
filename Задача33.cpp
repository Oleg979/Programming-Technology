#include <stdio.h>
int main() {
	const int arr[] ={5,4,3,2};
	const int N = sizeof(arr)/sizeof(arr[0]);
	
	int i,j, count = 0;
	for(i = 0; i < N-1; i++)
		for(j = i+1; j < N; j++)
			if(arr[i] > arr[j]) count++;
	printf("%d", count);
}
