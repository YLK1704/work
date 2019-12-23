#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define BUFFER_SIZE 5
#define END_FLAG (-1)


struct Products {
    int buffer[BUFFER_SIZE];
    
    pthread_mutex_t locker;
   
    pthread_cond_t notEmpty;
  
    pthread_cond_t notFull;
    int posReadFrom;
    int posWriteTo;
};

struct Products products;

int BufferIsFull(struct Products* products) {
    if ((products->posWriteTo +1) % BUFFER_SIZE == products->posReadFrom) {
        return (1);
    }
    return (0);
}

int BufferIsEmpty(struct Products* products) {
    if (products->posWriteTo == products->posReadFrom) {
        return (1);
    }
    return (0);
}

void* ProducerThread(void* data) {
    int i;int num;
    for (i = 0;; ++i) {
		num=((int)random())%1000;
        printf("the producer: %d\n", num);
		pthread_mutex_lock(&products.locker);
		while (BufferIsFull(&products)) {
		    pthread_cond_wait(&products.notFull, &products.locker);
		}
		products.buffer[products.posWriteTo] = num;
		products.posWriteTo++;
		if (products.posWriteTo >= BUFFER_SIZE)
		    products.posWriteTo = 0;
		pthread_cond_signal(&products.notEmpty);
		 
		pthread_mutex_unlock(&products.locker);
    }
    return NULL;
}

void* ConsumerThread(void* data) {
    int item;
    while (1) {
		pthread_mutex_lock(&products.locker);
		while (BufferIsEmpty(&products)) {
		    pthread_cond_wait(&products.notEmpty, &products.locker);
		}//01234
		item = products.buffer[products.posReadFrom];
		products.posReadFrom++;  
		if (products.posReadFrom >= BUFFER_SIZE)
			 products.posReadFrom = 0;
		pthread_cond_signal(&products.notFull);
		
		pthread_mutex_unlock(&products.locker);

        if (END_FLAG == item)
            break;
        printf("the consumer: %d\n", item);
    }
    return (NULL);
}

int main(int argc, char* argv[]) {
    pthread_t producer;
    pthread_t consumer;
    int result;
    pthread_create(&producer, NULL, &ProducerThread, NULL);
    pthread_create(&consumer, NULL, &ConsumerThread, NULL);
    pthread_join(producer, (void *) &result);
    pthread_join(consumer, (void *) &result);
    exit(EXIT_SUCCESS);
}



