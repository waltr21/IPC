#include<stdio.h>
#include<signal.h>

//#define SIGUSR1 8
//#define SIGUSR2 9


void sigHandler(int);

int main() {

	// setup signalhandler
	// print waiting
	

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
