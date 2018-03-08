#include <stdio.h>
int main() {
	int n = 320, res = 0, buf = 0, k = 10;
	do {
	 buf = n%k;
	 res = res*10+buf;
	 n/=10;
	} while(n!=0);
	printf("%d", res);
}
