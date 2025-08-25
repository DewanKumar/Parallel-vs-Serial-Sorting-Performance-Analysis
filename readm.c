#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>


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
int main(void) {
int pipe;
   int arr[25];


clock_t st = clock();
   
   // open a named pipe
   pipe = open("/tmp/myfifo", O_RDONLY);

   // actually read out the data and close the pipe
   read(pipe,arr,sizeof(arr));
   clock_t et = clock();
      close(pipe);
//int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
        int x;
    printf("\nenter the number to find\n");
    scanf("%d",&x);

    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",
                            result);
/*for(int i=0;i<5;i++)
{
if (arr[i]==n){
check=1;
}
}
check==1?printf("found"):printf("not found");
//printf("%d",n);*/
//write(1, buffer, sizeof(buffer));
//printf("\n");


clock_t ctt = (et - st);
double tis = ctt / (double) CLOCKS_PER_SEC;
    printf("\n\ntotal time is : %lf\n\n",tis);
return 0;
}


//
//int binarySearch(int arr[], int l, int r, int x)
//{
//    if (r >= l) {
//        int mid = l + (r - l) / 2;
//        if (arr[mid] == x)
//            return mid;
//        if (arr[mid] > x)
//            return binarySearch(arr, l, mid - 1, x);
//        return binarySearch(arr, mid + 1, r, x);
//    }
////    return -1;
//}
