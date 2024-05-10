#include "philo.h"

int	init_mutexes(t_god *god)
{
	int	i;

	i = 0;
	while (i < god->philo_count)
	{
		if (pthread_mutex_init(&god->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&god->die_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&god->prints_lock, NULL))
		return (1);
	if (pthread_mutex_init(&god->eat_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&god->start_time_lock, NULL))
		return (1);
	return (0);
}

void thread_destroy(t_philo *philo, t_god *god)
{
	int i;

	i = 0;
	while (i < god->philo_count)
		pthread_join(philo[i++].thread, NULL);
	i = 0;
	while (i < god->philo_count)
		pthread_mutex_destroy(&(god->forks[i++]));
	pthread_mutex_destroy(&(god->start_time_lock));
	pthread_mutex_destroy(&(god->die_mutex));
	pthread_mutex_destroy(&(god->prints_lock));
	pthread_mutex_destroy(&(god->eat_mutex));
}


void lock_forks(t_god *god, int left_fork, int right_fork)
{
    if (left_fork < right_fork)
    {
        pthread_mutex_lock(&(god->forks[left_fork]));
        pthread_mutex_lock(&(god->forks[right_fork]));
    }
    else
    {
        pthread_mutex_lock(&(god->forks[right_fork]));
        pthread_mutex_lock(&(god->forks[left_fork]));
    }
}

void unlock_forks(t_god *god, int left_fork, int right_fork)
{
    if (left_fork < right_fork)
    {
        pthread_mutex_unlock(&(god->forks[right_fork]));
        pthread_mutex_unlock(&(god->forks[left_fork]));
    }
    else
    {
        pthread_mutex_unlock(&(god->forks[left_fork]));
        pthread_mutex_unlock(&(god->forks[right_fork]));
    }
}