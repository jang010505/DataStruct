#include <stdio.h>

int power(int x, int n){
	if(n == 0)
		return 1;
	else if(n % 2)
		return x * power(x *x, (n - 1) / 2);
	else
		return power(x * x, n / 2);
}

int main(){
	int x, n;
	scanf("%d %d", &x, &n);
	printf("%d", power(x, n));
	return 0;
}
