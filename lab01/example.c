#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void *f(void *arg) {
  	long id = *(long*)arg;
	for (int i = 1; i <= 100; ++i) {
  		printf("Hello World din thread-ul %ld %d!\n", id, i);
	}
  	pthread_exit(NULL);
}

void *my_f1 (void *arg) {
	long id = *(long*)arg;
	printf("We are in the first function with thread id : %ld\n", id);
}

void *my_f2(void *arg) {
	long id = *(long*)arg;
	printf("We are in the second function with thread id : %ld\n", id);
}

int main(int argc, char *argv[]) {
	long cores = sysconf(_SC_NPROCESSORS_CONF);
	#define NUM_THREADS cores
	pthread_t threads[NUM_THREADS];
  	int r;
  	long id;
  	void *status;
	long ids[NUM_THREADS];

  	for (id = 0; id < NUM_THREADS; id++) {
		ids[id] = id; 
		r = pthread_create(&threads[id], NULL, f, &ids[id]);
		if (r) {
	  		printf("Eroare la crearea thread-ului %ld\n", id);
	  		exit(-1);
		}
  	}

  	for (id = 0; id < NUM_THREADS; id++) {
		r = pthread_join(threads[id], &status);

		if (r) {
	  		printf("Eroare la asteptarea thread-ului %ld\n", id);
	  		exit(-1);
		}
  	}

	printf("########################## FINAL ############################\n\n");

	pthread_t t1, t2;
	long id1 = 1, id2 = 2;
	int r1 = pthread_create(&t1, NULL, my_f1, &id1);
	int r2 = pthread_create(&t2, NULL, my_f2, &id2);

  	pthread_exit(NULL);
}
