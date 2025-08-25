#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <time.h>

#define MAXSIZE 25
#define n 25

void die(char *str) {
    perror(str);
    exit(1);
}

int main(void) {
    int arr[n];
    int c;

    int shmid;
    key_t key;
    int *shm, *s;

    key = 2311;

    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    if ((shm = shmat(shmid, NULL, 0)) == (int*)-1)
        die("shmat");

    printf("\nWaiting for the other process\n");

    FILE *ff;
    ff = fopen("shared.txt", "r");
    if (ff == NULL)
        die("fopen");

    for (c = 0; c < n; c++) {
        int num;
        fscanf(ff, "%d", &num);
        arr[c] = num;
    }
    fclose(ff);

    for (c = 0; c < n; c++)
        printf("%d \t", arr[c]);

    s = shm;

    clock_t st = clock();

    for (c = 0; c < n; c++) {
        *s = arr[c];
        s++;
    }

    clock_t et = clock();
    clock_t ctt = et - st;
    double tis = ctt / (double) CLOCKS_PER_SEC;

    // TO STOP THE SERVER FROM EXITING
    *shm = '*';
    while (*shm != '*');

    printf("\n\ntotal time for writing is: %lf\n\n", tis);
    exit(0);
}
