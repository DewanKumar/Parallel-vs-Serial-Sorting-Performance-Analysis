#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#define maxdigits 10
int main(void) {
int arr[25];
    int fd;
    char * myfifo = "/tmp/myfifo";

    int n=25;
    
   mkfifo(myfifo, 0666);

    printf("\nWaiting for the other process\n");
    
    FILE *ff;
    ff = fopen("shared.txt","r"); //open the file in which numbers are stored

    for (int c = 0 ; c < n  ; c++ )
  	{
        int num;
        fscanf(ff, "%d",&num);
        arr[c]=num;
  	}
  	for (int c = 0 ; c < n  ; c++ )
        printf("%d \t",arr[c]);	
        clock_t st = clock();	
    // OPENS PIPE 
  fd = open(myfifo, O_WRONLY);
    
    write(fd,arr,sizeof(arr));  //writes the data
    
    close(fd); //CLOSES PIPE
    
clock_t et = clock();



    unlink(myfifo);
    clock_t ctt = (et - st);
double tis = ctt / (double) CLOCKS_PER_SEC;
    printf("\n\ntotal time is : %lf\n\n",tis);
return 0;
}
//  mkfifo(myfifo, 0666);
//        clock_t st = clock();	
//    // OPENS PIPE 
//  fd = open(myfifo, O_WRONLY);
//    
//    write(fd,arr,sizeof(arr));  //writes the data
//    
//    close(fd); //CLOSES PIPE
//    
//clock_t et = clock();
//
//
//
//    unlink(myfifo);
