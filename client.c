#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 25
#define n 25

void die(char *str) {
	perror(str);
	exit(1);
}

int main(void) {
int arr[25];


clock_t st = clock();
	int shmid;
	key_t key;
	int *shm, *s;

	key = 2211;
	fflush(stdin);
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (int*)-1)
		die("shmat");
	s=shm;
	for(int i=0;i<n;i++)
	{
		arr[i]=*s;
		*s++;

	}
clock_t et = clock();
clock_t ctt = et - st;
double tis = ctt / (double) CLOCKS_PER_SEC;

	*shm = '*';
	printf("\n");
	/* insertion sort lagaye hai */
for(int i=1;i<n;i++)  
{
int var=arr[i];
int temp=i;	
for(int j=i-1;j>=0;j--)
{
			
  if(arr[j]>var)
  {
  arr[temp]=arr[j];
  arr[j]=var;  
  temp--;		
   }
 }
 
}

// insertion sort algorithm ends
      /* insaano ki tarah yaha tum print kardo */                             
 	for (int c = 0 ; c < n  ; c++ )
        printf("%d \t",arr[c]);	

       


	printf("\n\ntotal time for reading is: %lf\n\n",tis);
	exit(0);
}
