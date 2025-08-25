#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 27

void die(char *str) {
    perror(str);
    exit(1);
}

int main(void) {
    int shmid;
    key_t key;
    int *shm, *s;
    clock_t ct = clock();
    key = 2620;

    if ((shmid = shmget(key, MAXSIZE * sizeof(int), 0666)) < 0)
        die("shmget");
    if ((shm = (int *) shmat(shmid, NULL, 0)) == (int *) -1)
        die("shmat");

    printf("RESULTANT MATRIX!!\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", *(shm + i * 2 + j)); // access the data in shared memory
        }
        printf("\n");
    }

    if (shmdt(shm) == -1) // detach shared memory segment
        die("shmdt");

    ct = clock() - ct;
    double timeTaken = (double) ct / CLOCKS_PER_SEC;
    printf("Time Taken: %f\n", timeTaken);
    exit(0);
}



