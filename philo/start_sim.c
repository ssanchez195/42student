#include "philo.h"

int	check_arguments(char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200 || is_numeric(argv[1]))
		return (write (1, "Numero de filosofos incorrectos", 31), 1);
	if (ft_atoi(argv[2]) <= 0 || is_numeric(argv[2]) == 1)
		return (write (1, "Tiempo de muerte incorrecto", 28), 1);
	if (ft_atoi(argv[3]) <= 0 || is_numeric(argv[3]) == 1)
		return (write (1, "Tiempo de comer incorrecto", 27), 1);
	if (ft_atoi(argv[4]) <= 0 || is_numeric(argv[4]) == 1)
		return (write (1, "Tiempo de dormir incorrecto", 28), 1);
	if (argv[5] && (ft_atoi(argv[5]) <= 0 || is_numeric(argv[5]) == 1))
		return (write (1, "Numero de comidas por filosofo incorrecto", 42), 1);
	return (0);
}

void	god_args(char **argv, t_god *god)
{
	god->philo_count = ft_atoi(argv[1]);
	god->time_to_die = ft_atoi(argv[2]);
	god->time_to_eat = ft_atoi(argv[3]);
	god->time_to_sleep = ft_atoi(argv[4]);
	god->philo_is_dead = 0;
	if (!argv[5])
		god->times_must_eat = -1;
	else
		god->times_must_eat = ft_atoi(argv[5]);
}

void	save_philos_info(t_philo *philo, t_god *god)
{
	int	i;

	i = 0;
	while (i < god->philo_count)
	{
		philo[i].id = i + 1;
		philo[i].last_eat = 0;
		philo[i].left_fork = i;
		if (i == god->philo_count - 1)
			philo[i].right_fork = 0;
		else
			philo[i].right_fork = (i + 1) % god->philo_count;
		philo[i].times_eaten = 0;
		philo[i].god = god;
		i++;
	}
}

int	start_simulation(t_god *god, t_philo *philo)
{
	int				i;

	i = 0;
	while (i < god->philo_count)
	{
		philo[i].last_eat = get_current_ms();
		if (pthread_create(&philo[i].thread, NULL, philo_sequence, &philo[i]) != 0)
		{
			printf("Error al crear el hilo del filosofo -> %d\n", i + 1);
			return (1);
		}
		philo[i].start_time = get_current_ms();
		i++;
	}
	god->start_time = philo[0].start_time;
	god_sees_everything(god, philo);
	return (0);
}
