#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
	
pthread_mutex_t mutex;
int a = 0;
void *f(void *arg)
{
	pthread_mutex_lock(&mutex);
	a += 2;
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
	
}

int main(int argc, char *argv[])
{
	int i, r;
	void *status;
	pthread_t threads[NUM_THREADS];
	int arguments[NUM_THREADS];
	pthread_mutex_init(&mutex, NULL);
	// int pthread_mutex_lock(pthread_mutex_t *mutex);
	// int pthread_mutex_unlock(pthread_mutex_t *mutex);
	
	for (i = 0; i < NUM_THREADS; i++) {
		arguments[i] = i;
		
		r = pthread_create(&threads[i], NULL, f, &arguments[i]);
		
		if (r) {
			printf("Eroare la crearea thread-ului %d\n", i);
			exit(-1);
		}
	}
	
	for (i = 0; i < NUM_THREADS; i++) {
		r = pthread_join(threads[i], &status);
		if (r) {
			printf("Eroare la asteptarea thread-ului %d\n", i);
			exit(-1);
		}
	}
	pthread_mutex_destroy(&mutex);
	printf("a = %d\n", a);

	return 0;
}
