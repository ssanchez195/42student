#include "philo.h"

long long	get_current_ms(void)
{
	struct timeval		tv;
	time_t 				time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	ft_usleep(t_philo *philo, long long max_action_time)
{
    long	time_up;

    time_up = get_current_ms() + max_action_time;
    while (1)
    {
        pthread_mutex_lock(&philo->god->eat_mutex);
        if (philo->god->philo_is_dead == 1)
        {
            pthread_mutex_unlock(&philo->god->eat_mutex);
            break;
        }
        pthread_mutex_unlock(&philo->god->eat_mutex);
        if (get_current_ms() >= time_up)
            break;
        usleep(50);
    }
}