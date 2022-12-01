#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
    schelet pentru exercitiul 5
*/


void *f(void *args) {

} 


int* arr;
int array_size;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("Specificati dimensiunea array-ului\n");
        exit(-1);
    }

    array_size = atoi(argv[1]);

    arr = malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < array_size; i++) {
        printf("%d", arr[i]);
        if (i != array_size - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    long cores = sysconf(_SC_NPROCESSORS_CONF);

    // TODO: aceasta operatie va fi paralelizata
    pthread_t t1[cores];

    for (int i = 0; i < cores; ++i) {
        int start = array_size / , end = 0;
        int r = pthread_create(&t1[i], NULL, f, )
    }


  	for (int i = 0; i < array_size; i++) {
        arr[i] += 100;
    }

    for (int i = 0; i < array_size; i++) {
        printf("%d", arr[i]);
        if (i != array_size - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

  	pthread_exit(NULL);
}
