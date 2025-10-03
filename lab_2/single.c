#include <stdio.h>

unsigned long addall() {
	int i = 0;
	unsigned long sum = 0;

	while (i < 10000000) {
		sum += i;
		i++;
	}
	return sum;
}

int main() {
	unsigned long sum;
	
	sum = addall();
	printf("%lu\n", sum);
}
