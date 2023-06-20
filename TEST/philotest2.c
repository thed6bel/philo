#include <stdio.h>
#include <pthread.h>

#define N 5

pthread_mutex_t forks[N];

void *philosopher(void *arg)
{
    int philosopher_id = *(int*)arg;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % N;
    
    // Philosophes impairs
    if (philosopher_id % 2 == 1)
	{
        pthread_mutex_lock(&forks[left_fork]);
        pthread_mutex_lock(&forks[right_fork]);
        printf("eat philo %d\n", philosopher_id +1);
        // Manger
        
        pthread_mutex_unlock(&forks[right_fork]);
        pthread_mutex_unlock(&forks[left_fork]);
    }
    // Philosophes pairs
    else {
        pthread_mutex_lock(&forks[right_fork]);
        pthread_mutex_lock(&forks[left_fork]);
        printf("eat philo %d\n", philosopher_id +1);
        // Manger
        
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);
    }
    
    // Réflexion
    
    pthread_exit(NULL);
}

int main()
{
    pthread_t philosophers[N];
    int philosopher_ids[N];
    
    for (int i = 0; i < N; i++)
        pthread_mutex_init(&forks[i], NULL);
    
    for (int i = 0; i < N; i++)
	{
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }
    
    for (int i = 0; i < N; i++)
	{
        pthread_join(philosophers[i], NULL);
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
