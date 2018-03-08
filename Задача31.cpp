#include <stdio.h>
int main() {
	int arr[] = {2,3,-4,0,-4,-2,0,-1,1,6,0,5,8,8,-3}; 
	const int N = sizeof(arr)/sizeof(arr[0]);
	int max = 0, begin = 0, end = 0, len = 0;
	
	for(int i = 0, j = 1; i < N-1; i++) {
		len = 0;
		while(arr[i]*arr[j] > 0 && j < N) {
			len++; j++;
		}

		if(!len) j++;
		if(len > max) {
			max = len;
			begin = i;
			end = j;
		}
	}
	
	for(int i = begin; i < end; i++)
		printf("%d ", arr[i]);
}
