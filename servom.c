#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<time.h>

#define MAXSIZE 25
#define n 25

void die(char *str) {
	perror(str);
	exit(1);
}

int main(void) {
	int arr[25];
    int fd;


    int c;

	int shmid;
	key_t key;
	int *shm, *s;

	key = 2311;
	// OPENS A SHARED SEGMENT 
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (int*)-1)
		die("shmat");
	s = shm;
    printf("\nWaiting for the other process\n");
    
    FILE *ff;
    ff = fopen("shared.txt","r"); //open the file in which numbers are stored
       // printf("1");
    for (int c = 0 ; c < n  ; c++ )
  	{
        int num;
        //printf("2");
        fscanf(ff, "%d",&num);
        arr[c]=num;
  	}

  	   
 	
   

clock_t st = clock();	
	
	for(c = 0; c <= n; c++) 
	{	
		*s=arr[c];
		//printf("3");
	*s++;

	}

for (int c = 0 ; c < n  ; c++ )
        printf("%d \t",arr[c]);	

// CALCULATING TIME 
clock_t et = clock();
clock_t ctt = et - st;
double tis = ctt / (double) CLOCKS_PER_SEC;

// TO STOP THE SERVER FROM EXITING
	while(*shm != '*');
		
	printf("\n\ntotal time for writing is: %lf\n\n",tis);
	exit(0);
}
//	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
//		die("shmget");
//	if((shm = shmat(shmid, NULL, 0)) == (int*)-1)
//		die("shmat");
//	    FILE *ff;
//    ff = fopen("shared.txt","r");	
//	clock_t et = clock();
//clock_t ctt = et - st;
//double tis = ctt / (double) CLOCKS_PER_SEC;
//
//// TO STOP THE SERVER FROM EXITING
//	while(*shm != '*');	
		
		
