#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_NUMBER_PEOPLE 5
//need to make sure I take the number of people going across the bridge as an input
sem_t north_full_sem;
sem_t south_full_sem;
sem_t can_go_north_sem;
sem_t can_go_south_sem;
pthread_mutex_t increment_mutex;
//this mutex will control the incrementing of 
pthread_mutex_t mutex;
//will need two counting variables one for north and one for south so we can tell when the first person passed from each side
int SIZE;
int southTotal;
int northTotal;
int currently_going_north;
int currently_going_south;
//each south thread will handle this function and act like 1 dude going to the north each
void *north(void *thread_n){
	int random = *(int * )thread_n;
	sleep(random);
	pthread_mutex_lock(&mutex);
	sem_wait(&north_full_sem);
	//making sure that if someone is going south we can't go north, this is because the north sem will be already at 0 if someone is going south
	//but it will be 1 if no one is going south
	sem_wait(&can_go_north_sem);
	sem_post(&can_go_north_sem);
	currently_going_north++;
	if(currently_going_north == 1){
		sem_wait(&can_go_south_sem);
	}
	pthread_mutex_unlock(&mutex);

	//need to create the critcal section which will increment north and south total respectively
	sleep(random);	
	pthread_mutex_lock(&increment_mutex);
	northTotal++;
	printf("Total number of people passed north :%d currently there are %d people on the bridge\n", northTotal, currently_going_north + currently_going_south);
	if(northTotal == 1){
		printf("first person crossing bridge to north\n");
	}
	if(currently_going_north == 1){
		sem_post(&can_go_south_sem);
	}
	currently_going_north--;
	sem_post(&north_full_sem);
	pthread_mutex_unlock(&increment_mutex);	
	pthread_exit(0);
}
//each south thread will handle this function and act like 1 dude going to the south each
void *south(void *thread_n){
	int random = *(int *)thread_n;
	sleep(random);	
	pthread_mutex_lock(&mutex);
	sem_wait(&south_full_sem);	
	sem_wait(&can_go_south_sem);
	sem_post(&can_go_south_sem);
	currently_going_south++;
	if(currently_going_south == 1){
		sem_wait(&can_go_north_sem);
	}
	pthread_mutex_unlock(&mutex);

	//need to create the critcal section which will increment north and south total respectively
	sleep(random);
	pthread_mutex_lock(&increment_mutex);
	southTotal++;
	printf("Total number of people passed south :%d currently there are %d people on the bridge\n", southTotal, currently_going_north +  currently_going_south);
	if(southTotal == 1){
		printf("first person crossing bridge to south\n");
	}
	if(currently_going_south == 1){
		sem_post(&can_go_north_sem);
	}
	currently_going_south--;
	sem_post(&south_full_sem);
	pthread_mutex_unlock(&increment_mutex);	
	pthread_exit(0);
}

int main(){
	int size = 0;
        printf("Maximum number of people who can cross the bridge: ");
        scanf("%d", &size);
        SIZE = size * 2;
	//intialize counting variables
	southTotal = 0;
	northTotal = 0;
	currently_going_north = 0;
	currently_going_south = 0;
	//initialize semaphores
	sem_init(&north_full_sem, 0, MAX_NUMBER_PEOPLE);
	sem_init(&south_full_sem, 0, MAX_NUMBER_PEOPLE);
	sem_init(&can_go_north_sem, 0, 1);
	sem_init(&can_go_south_sem, 0, 1);
	//initalize mutex
	pthread_mutex_init(&increment_mutex, NULL);
	pthread_mutex_init(&mutex, NULL);
	pthread_t thread[SIZE];
	int i = 0;
	int random = 0;
	for (i = 0; i < SIZE; ) {
		//may not need thread_numb in this implementation
		random = rand() % 3;
		pthread_create(thread + i, // pthread_t *t
				NULL, // const pthread_attr_t *attr
				north, // void *(*start_routine) (void *)
				&random );  // void *arg
		i++;
		random = rand() % 3;
		pthread_create(thread + i, // pthread_t *t
				NULL, // const pthread_attr_t *attr
				south, // void *(*start_routine) (void *)
				&random);  // void *arg
		i++;	
	}

	for (i = 0; i < SIZE; i++)
		pthread_join(thread[i], NULL);

	pthread_mutex_destroy(&increment_mutex);
	pthread_mutex_destroy(&mutex);
	sem_destroy(&north_full_sem);
	sem_destroy(&can_go_north_sem);
	sem_destroy(&south_full_sem);
	sem_destroy(&can_go_south_sem);
	printf("I executed without any issues!");
	return 0;
}
