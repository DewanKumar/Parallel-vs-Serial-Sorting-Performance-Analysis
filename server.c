#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<time.h>

#define MAXSIZE 25
#define n 25

void die(char *str) {/// error handling 
	perror(str);
	exit(1);
}
int main(void) {
	int arr[25];
    int fd;


    int c;

	int shmid; // shmid and the key are the variables for shared memory 
	key_t key; // also a variable for shared memory 
	int *shm, *s; // these are pointers for shared memory access 

	key = 2211; /// this is a key value that is same in both server and client but should be unique ham change kar saktay hai masla nae hai koi bhi 
	// OPENING SHARED SEGMENT
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0) 
	// sucess ful pay id etuen karta hai 
	// yaha ham shm get function ko call karrhay hai agr succesfully call nae howa toh -1 return karta hai 0666 read and write permission hoti hai for all users 
		die("shmget");// agr fail hota hai toh die function to say error 
	if((shm = shmat(shmid, NULL, 0)) == (int*)-1)
	
	// shamat ka function shared memory segment ko attach karti hai adress pay 
	//NULL q kiya meinnay isliya k computer khud assign kare usssya adress kaha rakhna hai 
	// 0 mera flags hota hai yaha 
	
	// shamat retun kiya kare ga  that would be starting address of the shared memory 
	// agr fail hota hai toh (int*)-1 yeh return karta hai 
	
	
		die("shmat");
		
		
	s = shm;
//	yaha s mein meinnay starting adress of the shred memory assign karde hia 
	
    printf("\nWaiting for the other process\n");
    // READING FROM THE FILE
    FILE *ff;
    ff = fopen("numbers.txt","r"); //open the file in which numbers are stored
       // printf("1");
    for (int c = 0 ; c < n  ; c++ )
  	{
        int num;
        //printf("2");
        fscanf(ff, "%d",&num);
        arr[c]=num;
  	}

  	   
 	for (int c = 0 ; c < n  ; c++ )
        printf("%d \t",arr[c]);	
   

clock_t st = clock();	// abhi clock ka kiya time hai ussay meinnay start var mein store karwaya 
	/* this loop is only k array ki value shared memory mein ja rhi hai ya nae aur harr baar mein array ki value daal rha hoo jo meinnay file say read kari thi */	for(c = 0; c <= n; c++) 
	{	
		*s=arr[c];
		//printf("3");
	*s++;

	}
// CALCULATING TIME
clock_t et = clock(); // execute honay k baad clock ka kiya time hai woh meinnay et mein store karwaya 
clock_t ctt = et - st;// kitna time laga yaha mujhay loop execute karanay k baad shared memory mein likhnay k baad 
double tis = ctt / (double) CLOCKS_PER_SEC;// seconds mein convert kanay k liyay use hoga yeh 




	while(*shm != '*');// whole logic y not semaphores 
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
for (int c = 0 ; c < n  ; c++ )
        printf("%d \t",arr[c]);		
	printf("\n\ntotal time for writing is: %lf\n\n",tis);
	exit(0);
}


/*
deadlocks 
real time guarenty nae deta
resource extra use
complexity 


*/
