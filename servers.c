#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAXSIZE 27

void die(char *str) {
    perror(str);
    exit(1);
}

int main(void) {
    clock_t ct = clock();
    int arr1[2][2];
    int arr2[2][2];
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            arr1[row][col] = rand() % 50;
            printf("%d\t", arr1[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            arr2[row][col] = rand() % 50;
            printf("%d\t", arr2[row][col]);
        }
        printf("\n");
    }
    char c;
    int shmid;
    key_t key;
    int *shm, *s;
    int temps[4];
    int temp;
    int count = 0;
    key = 2620;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            temp = 0;
            for (int k = 0; k < 2; ++k) {
                temp += arr1[i][k] * arr2[k][j];
            }
            temps[count] = temp;
            count++;
        }
    }
    // OPENS SHARED SEGMENT
    if ((shmid = shmget(key, MAXSIZE * sizeof(int), IPC_CREAT | 0666)) < 0)
        die("shmget");
    if ((shm = (int *) shmat(shmid, NULL, 0)) == (int *) -1)
        die("shmat");
    s = shm;
    for (c = 0; c < count; c++) {
        *s = temps[c];
        s++;
    }
    *s = '*';
    // TIME CALCULATION
    ct = clock() - ct;
    double timeTaken = (double) ct / CLOCKS_PER_SEC;
    printf("Time Taken:%f\n", timeTaken);
    exit(0);
}

 
