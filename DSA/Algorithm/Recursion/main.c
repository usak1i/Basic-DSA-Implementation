#include <stdio.h>

unsigned long long factorial(unsigned int n);
unsigned long long fib(unsigned int n);
void print(int n);

int count = 0;

int main(int argc, char *argv[]) {
	
	print(10);

	return 0;
}

unsigned long long factorial(unsigned int n) {
	if (n == 0 || n == 1) 
		return 1;
	
	return n * factorial(n - 1);
}

unsigned long long fib(unsigned int n) {
	if (n <= 2) 
		return n;

	count++;

	return fib(n - 1) + fib(n - 2);
}

void print(int n) {
	if (n > 0) {
		for (int i = 1; i < n; i = i * 2)
			printf(" %d", i);

		printf("\n");

		print(n - 1);
	}
}
