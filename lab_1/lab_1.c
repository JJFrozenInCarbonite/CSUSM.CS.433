#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
	pid_t q;
	printf("before fork\n");
	q=fork();
	if (q==0) {
		printf("I am child having id %d\n", getpid());
		printf("My parent's id is %d\n", getppid());
	} else {
		printf("My child's id is %d\n", q);
		printf("I am parent having id %d\n", getpid()); 
	}
	printf("This line is printed by both parent and child. pid %d\n", getpid());
}
