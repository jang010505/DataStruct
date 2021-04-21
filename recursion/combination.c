#include <stdio.h>

int combination(int n, int k){
	if(k == 0 || k == n)
		return 1;
	else
		return combination(n-1, k-1) + combination(n - 1, k);
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", combination(n, k));
	return 0;
}
