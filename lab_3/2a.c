#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
int main() {
	pid_t q;
	q=fork();

	// child
	if(q==0) {
		execl("bin/ps", "ps", NULL);
		printf("I am child having ID %d\n", getpid());
		sleep(10);
	}
	// parent
	else { 
		wait(NULL);
		printf("I am parent having id %d\n", getpid());	
	}
}
