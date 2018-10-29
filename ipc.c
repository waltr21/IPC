#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>



void sigHandler(int);

int main() {
	pid_t pid;


	if((pid = fork()) < 0) {
		perror("fork failed");
		exit(1);
	}
	else {
	
	printf("\nspawned child PID# %d", pid);
	while (1) {


	// parent
	if (pid > 0) {
	signal(SIGUSR1, sigHandler);
	signal(SIGUSR2, sigHandler);
	signal(SIGINT, sigHandler);
	printf("\nwaiting... ");
	fflush(stdout);
	pause();
	}
	// child
	else {
	srand(time(NULL));
	
	int num = (rand() % 10) + 1;
	

	if(num > 5) {
		num = num - 5;
		sleep(num);
	}
	else {
		sleep (num);
	}

	pid_t ppid = getppid();
	
	if ( num % 2 == 0 ) {
		// kill send signal 1
		kill(ppid, SIGUSR1);
	}
	else {
		// kill send signal 2
		kill(ppid, SIGUSR2);
	}

	}
	}
	}	

}

void sigHandler(int sigNum) {

	if(sigNum == SIGUSR1) {
		printf("received a SIGUSR1 signal!\n");
	}
	else if (sigNum == SIGUSR2) {
		printf("received a SIGUSR2 signal!\n");

	}
	else if (sigNum == SIGINT){
		printf(" received. That's it, I'm shutting you down...\n");
		exit(0);
	}


}
