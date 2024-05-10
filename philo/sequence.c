#include "philo.h"

void	*philo_sequence(void *info)
{
	t_philo	*philo;
	t_god	*god;
	int		times_eaten;

	philo = (t_philo *)info;
	god = philo->god;
	if (lone_philo(philo, god) == 1)
		return (NULL);
	if (philo->id % 2 == 0)
		ft_usleep(philo, 10);
	pthread_mutex_lock(&god->die_mutex);
	while (god->philo_is_dead == 0)
	{
		philo_eats(philo, god);
		philo_sleeps(philo, god);
        pthread_mutex_lock(&god->eat_mutex);
		pthread_mutex_lock(&god->die_mutex);
        times_eaten = philo->times_eaten;
        pthread_mutex_unlock(&god->eat_mutex);
		if (times_eaten == god->times_must_eat)
			break ;
		philo_thinks(philo);
	}
	pthread_mutex_unlock(&god->die_mutex);
	return (NULL);
}

void philo_eats(t_philo *philo, t_god *god)
{
    int left_fork = philo->left_fork;
    int right_fork = philo->right_fork;

	pthread_mutex_unlock(&god->die_mutex);
    lock_forks(god, left_fork, right_fork);
    print_message(philo, god, "has taken a fork", philo->id);
	print_message(philo, god, "has taken a fork", philo->id);
    print_message(philo, god, "is eating", philo->id);
    pthread_mutex_lock(&god->eat_mutex);
    philo->last_eat = get_current_ms();
    pthread_mutex_unlock(&god->eat_mutex);
    ft_usleep(philo, god->time_to_eat);
    pthread_mutex_lock(&god->eat_mutex);
    philo->times_eaten++;
    pthread_mutex_unlock(&god->eat_mutex);
    unlock_forks(god, left_fork, right_fork);
}

void	philo_sleeps(t_philo *philo, t_god *god)
{
	print_message(philo, god, "is sleeping", philo->id);
	ft_usleep(philo, god->time_to_sleep);
}

void	philo_thinks(t_philo *philo)
{
	print_message(philo, philo->god, "is thinking", philo->id);
}
