#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <stdbool.h>

#define READ 0
#define WRITE 1

/*
	fd1[]   for MCC1 (Main program)
	fd2[]   for MCC2 (Brute force)
	fdGen[] for M to read text of genIn and input to main prog and brute
	
	TO DO
	#
	#check for main pro and brute , if they go in infinite loop , firt thing put wait
	#put wait at all the appropriate positions
	#close all the fd at appropriate places
	#can add to check if exit status , using macros
*/


//This function is returning one extra character at the end(well it does not disturbs the flow)
char* getInput(){
	FILE *fp;
       int ch;
       char txt[500];
       int len=0;
       fp=fopen("./TestingSolution/genIn","r");

       while(ch!=EOF){
           ch=fgetc(fp);
           txt[len]=ch;
           len++;
         } 
     fclose(fp);
     //puts(txt);
     char* tt = txt;
     return tt;
}
void writeIntoFile(char* file,char* message){
	FILE *fp;

	fp = fopen(file, "w+");
	//fprintf(fp, "This is testing for fprintf...\n");
	fputs(message, fp);
	fclose(fp);
	
}
bool checkIfEqual(char* str1,char* str2){
	if(strcmp(str1,str2)==0){
		return true;
	}
	return false;
}

int main(int argc,char* argv[]){

	
	int status;

	int byteRead;
	char* temp;
	char message[100]="",message2[100]=""; //initialize so that last last there is no unwanted character due to buffer
	
	int fd1Gen[2];
	pipe(fd1Gen);
	
	int fd2Gen[2];
	pipe(fd2Gen);
	
	int fdR1[2];
	pipe(fdR1);
	
	int fdR2[2];
	pipe(fdR2);
	
	if(fork()!=0){
		//main parent(M)
		printf("Main Parent(M) \n");
		
		
		close(fd1Gen[READ]);
		close(fd2Gen[READ]);
	
		
		
		char* yo1 = getInput();
		write(fd1Gen[WRITE],yo1,20000000);
		char* yo2 = getInput();
		write(fd2Gen[WRITE],yo2,20000000);
		
		
		char ans1[100];
		char ans2[100];
		
		wait(&status);
		
		read(fdR1[READ],ans1,100);
		printf("So the answer 1 is : %s\n",ans1);
		
		read(fdR2[READ],ans2,100);
		printf("So the answer 2 is : %s\n",ans2);
		
		writeIntoFile("./TestingSolution/out1",ans1);
		writeIntoFile("./TestingSolution/out2",ans2);
		
		
		/*bool isEqual = checkIfEqual(ans1,ans2);
		if(isEqual==true){
			printf("output match\n");
		}
		else{
			printf("output doesnt match\n");
		}*/
		
	}
	else{
		//main parent child(MC)
		
		int fd1[2];
		pipe(fd1);
		
		if(fork()!=0){
			//main parent child(MC)
			printf("Main Parent Child (MC)\n");
			
			
			int fd2[2];
			pipe(fd2);
			
			
			//wait(&status);
			//reading from main program
			byteRead = read(fd1[READ],message2,100);
			
			close(fdR1[READ]);
			write(fdR1[WRITE],message2,100);
			
			printf("main sent : %s\n",message2);
			
			
			if(fork()==0){
				//MCC2
				printf("MCC2 \n");
				
				//for whatever brute will output will go to mc
				close(fd2[READ]);
				dup2(fd2[WRITE],1);
				
				//for getting input(from M) of all the values from genIn
				close(fd2Gen[WRITE]);
				dup2(fd2Gen[READ],0);
				
				execlp("java","java",argv[2],NULL);
				printf("I should not be printed");
			}
			else{
				//main parent child(MC) continued....
				
				//reading from brute
				byteRead = read(fd2[READ],message,100);
				
				close(fdR2[READ]);
				write(fdR2[WRITE],message,100);
				
				printf("brute sent : %s\n",message);	
				
			}
			
		}
		else{
			//MCC1
			printf("MCC1 \n");
			
	
				
				//for whatever brute will output will to to mc
				close(fd1[READ]);
				dup2(fd1[WRITE],1);
				
				//for getting input(from M) of all the values from genIn
				close(fd1Gen[WRITE]);
				dup2(fd1Gen[READ],0);
				
				execlp("java","java",argv[1],NULL);
				printf("I should not be printed");
				
			
		}
	}
}
