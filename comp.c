#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <stdbool.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<fcntl.h>


void help(){
	printf("**********************USAGE********************************\n");
	
	printf("\tDescription : \n");
	printf("\t\t-help \n");
	printf("\t\t-template \n");
	printf("\t\t-detect \n");
	
	printf("***********************************************************\n");
}

void checkValidArguments(int argc){
	if(argc < 2){
		printf("please provide valid argument\n");
		help();
		exit(0);
	}
	return;
}

int main(int argc,char* argv[]){
	int status;
	
	checkValidArguments(argc);
	
	if(fork()==0){
		if(strcmp(argv[1],"-detect")==0){
			execlp("bash","bash","detect.sh",argv[2],argv[3],NULL);
		}
		else if(strcmp(argv[1],"-template")==0){
			execlp("bash","bash","template.sh",argv[2],argv[3],NULL);
		}
		else if(strcmp(argv[1],"-help")==0){
			help();
		}
		else{
			printf("please provide valid argument\n");
			help();
			exit(0);
		}
		
	}
	else{
		wait(&status);
	}
}
