#include "philo.h"

void	god_sees_everything(t_god *god, t_philo *philo)
{
	int 		i;
	int			times_eaten;
	long long	time;
		
	while (1)
	{
		pthread_mutex_lock(&god->eat_mutex);
        times_eaten = philo->times_eaten;
        pthread_mutex_unlock(&god->eat_mutex);
		if (god->times_must_eat != -1 && times_eaten == god->times_must_eat)
        	break ;
		i = 0;
		while(i < god->philo_count)
		{
			pthread_mutex_lock(&god->eat_mutex);
			time = get_current_ms() - philo[i].last_eat;
			if (time > god->time_to_die)
			{
				pthread_mutex_lock(&god->die_mutex);
				print_message(&philo[i], god, "died", philo[i].id);
				god->philo_is_dead = 1;
				pthread_mutex_unlock(&god->die_mutex);
				pthread_mutex_unlock(&god->eat_mutex);
				return ;
			}
			pthread_mutex_unlock(&god->eat_mutex);
			i++;
		}
		usleep(5 * 1000);
	}
}

int	lone_philo(t_philo *philo, t_god *god)
{
	if (god->philo_count == 1)
	{
		print_message(philo, god, "has taken a fork", philo->id);
		ft_usleep(philo, god->time_to_die);
		return (1);
	}
	return (0);
}

void	print_message(t_philo *philo, t_god *god, char *message, int id)
{
	pthread_mutex_lock(&god->prints_lock);
	if (philo->god->philo_is_dead == 0)
		printf("%lld %d %s\n", get_current_ms() - god->start_time, id, message);
	pthread_mutex_unlock(&god->prints_lock);
}

int main(int argc, char **argv)
{
	t_philo	*philo;
	t_god	*god;

	if (argc == 5 || argc == 6)
	{
		if (check_arguments(argv) == 1)
			return (write(1, "Los valores de los argumentos no son los correctos", 51), 1);
		philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		god = malloc(sizeof(t_god));
		god_args(argv, god);
		init_mutexes(god);
		save_philos_info(philo, god);
		if (start_simulation(god, philo))
			return (write(1, "Error al inicializar los hilos", 31), 1);
		thread_destroy(philo, god);
		free(philo);
		free(god);
	}
	else
	{
		write(1, "El numero de argumentos no es el correcto", 42);
		return (0);
	}
}