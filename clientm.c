#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 25


int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
void die(char *str) {
	perror(str);
	exit(1);
}

int main(void) {
int arr[25];

int m=25;
clock_t st = clock();
	int shmid;
	key_t key;
	int *shm, *s;
    // OPENING SHARED SEGMENT
	key = 2311;
	fflush(stdin);
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");
	s=shm;
	for(int i=0;i<m;i++)
	{
		arr[i]=*s;
		*s++;

	}
    // CLCULATING TIME
clock_t et = clock();
clock_t ctt = et - st;
double tis = ctt / (double) CLOCKS_PER_SEC;

	
	printf("\n");
	
int n = sizeof(arr) / sizeof(arr[0]);
        int x;
    printf("\nenter the number to find\n");
    scanf("%d",&x);

    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",
                            result);
       
*shm = '*';

	printf("\n\ntotal time for reading is: %lf\n\n",tis);
	exit(0);
}

//	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
//		die("shmget");
//	if((shm = shmat(shmid, NULL, 0)) == (int*) -1)
//clock_t et = clock();
//clock_t ctt = et - st;
//double tis = ctt / (double) CLOCKS_PER_SEC;
