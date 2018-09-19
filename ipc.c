#include<stdio.h>
#include<signal.h>

//#define SIGUSR1 8
//#define SIGUSR2 9


void sigHandler(int);

int main() {
	pid_t pid;

	signal(SIGUSR1, sigHandler);
	signal(SIGUSR2, sigHandler);
	signal(SIGINT, sigHandler);

	if((pid = fork()) < 0) {
		perror("fork failed");
		exit(1);
	}
	// parent
	else if (!pid) {
	    printf("\nspawned child PID# %d", pid);
	    printf("waiting... \n");
	    pause();
	    return 0;
	}
	// child
	else {
	Random rand = new Random();
	int num = rand.Next(1, 11);
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

void sigHandler(int sigNum) {

	if(sigNum == SIGUSR1) {
		printf("received a SIGUSR1 signal");
	}
	else if (sigNum == SIGUSR2) {
		printf("received a SIGUSR2 signal");

	}
	else if (sigNum == SIGINT){
		printf("^C received. That's it, I'm shutting you down...");
		exit(0);
	}


}
