#include <stdio.h>
unsigned fibo(int n);
int main(){

printf("%d",fibo(7));
	return 0;
}

unsigned fibo(int n){
	if (n == 0 || n == 1) return 1;
	return fibo(n - 1) + fibo(n - 2);
}
