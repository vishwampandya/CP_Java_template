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
	printf("\n*******************************************USAGE************************************************************\n");
	
	printf("\tDescription : \n");
	printf("\n\tThis project is an complete setup that one can use for its competitve programming. \n\n\n");
	printf("\t\t-help \t[ gets program description and usage ]\n\n\n");
	
	
	printf("\t\t-template \t[ Creates desired template ]\n\n");
	printf("\t\t\t-template <newfilename> <template number(1-4)>\n");
	printf("\t\t\t\t1 => Reader class        ^ ...fastest\n");
	printf("\t\t\t\t2 => FastReader class    |\n");
	printf("\t\t\t\t3 => BufferReader class  |\n");
	printf("\t\t\t\t4 => Scanner class       |...slowest\n");
	
	printf("\n\n\n\t\t-detect \t[ Finds mismatching testCase between your bruteForce and optimized solution ]\n\n");
	printf("\t\t\t-detect <bruteForce filename> <optimized filename>\n");
	
	printf("\n*******************************************************************************************************************\n");
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
