#include <bits/pthread_types.h>
#include<iostream>
#include <pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t room;
sem_t chopsticks[5];

void * philosopher(void *);
void eat(int);

int main(){
    int i,a[5];
    pthread_t tid[5];

    sem_init(&room,0,4);

    for(i=0;i<5;i++){
        sem_init(&chopsticks[i],0,1);
    }
    for(i=0;i<5;i++){
        a[i]=i;
        pthread_create(&tid[i],NULL,philosopher, (void *)&a[i]);
    }
    for(i=0;i<5;i++){
        pthread_join(tid[i],NULL);
    }
}

void * philosopher(void * num){
    int phil=*(int *)num;

    sem_wait(&room);
    std::cout<<"\nPhilosopher "<< phil<<" has entered room";
    sem_wait(&chopsticks[phil]);
    sem_wait(&chopsticks[(phil+1)%5]);

    eat(phil);
    sleep(2);
    std::cout<<"\nPhilosopher "<<phil<<" has finished eating.";

    sem_post(&chopsticks[(phil+1)%5]);
    sem_post(&chopsticks[phil]);
    sem_post(&room);
    return 0;
}

void eat(int phil){

    std::cout<<"\nPhilosopher "<<phil<<" is eating";
}
