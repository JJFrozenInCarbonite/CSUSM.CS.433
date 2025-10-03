#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Before\n");
	// execl("/bin/ls", "ls",NULL);
	printf("After\n");
}
