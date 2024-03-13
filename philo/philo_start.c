#include "philo.h"

int	check_arguments(char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200 || is_numeric(argv[1]))
		return (write (1, "Numero de filosofos incorrectos", 31), 1);
	if (ft_atoi(argv[2]) <= 0 || is_numeric(argv[2]) == 1)
		return (write(1, "Tiempo de muerte incorrecto", 28), 1);
	if (ft_atoi(argv[3]) <= 0 || is_numeric(argv[3]) == 1)
		return (write (1, "Tiempo de comer incorrecto", 27), 1);
	if (ft_atoi(argv[4]) <= 0 || is_numeric(argv[4]) == 1)
		return (write (1, "Tiempo de dormir incorrecto", 28), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || is_numeric(argv[5]) == 1))
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

//Puede que haya que arreglar si solo hay 1 filosofo. No toma tenedores, ni muere

void	save_philos_info(t_philo *philo, t_god *god)
{
	int	i;

	i = 0;
	while (i < god->philo_count)
	{
		philo[i].start_time = get_current_ms();
		//printf("Tiempo de inicio del filosofo %d: %llu\n", i + 1, philo[i].start_time);
		philo[i].id = i + 1;
		philo[i].left_fork = i;
		if (i == god->philo_count - 1)
			philo[i].right_fork = 0;
		else
			philo[i].right_fork = (i + 1) % god->philo_count;
		philo[i].times_eaten = 0;
		i++;
	}
}

int	start_simulation(t_god *god, t_philo *philo)
{
	int				i;

	i = 0;
	/*if (philo->god->philo_count == 1)
	{
		usleep (philo->god->time_to_die * 1000);
		printf("El filosofo 1 ha muerto\n");
		return (0);
	}*/
	pthread_mutex_init(&god->die_mutex, NULL);
	pthread_mutex_init(&god->prints_lock, NULL);
	while (i != god->philo_count)
	{
		philo[i].god = god;
		pthread_mutex_init(&god->forks[i], NULL);
		if (pthread_create(&philo[i].thread, NULL, philo_sequence, &philo[i]) != 0)
			return (printf("Error al crear el hilo del filosofo%d\n", i + 1), 1);
		i++;
	}
	return (0);
}

void	god_sees_everything(t_god *god, t_philo *philo)
{
	int 	i;

	i = 1;
	while (1)
	{
		if (i == god->philo_count)
			i = 0;
		else
			i = 1;
		if (get_current_ms() - philo[i].last_eat > god->time_to_die)
		{
			pthread_mutex_lock(&god->die_mutex);
			god->philo_is_dead = 1;
		}
		if (god->philo_is_dead == 1)
		{
			pthread_mutex_unlock(&god->die_mutex);
			break ;
		}
		usleep(5 * 1000);
	}
}

void	*philo_sequence(void *info)
{
	t_philo	*philo;
	t_god	*god;

	philo = (t_philo *)info;
	god = philo->god;
	if (god->times_must_eat == 0)
		return (0);
	philo->last_eat = get_current_ms();
	if (philo->id % 2 == 0)
		ft_usleep(philo, 50);
	while (god->philo_is_dead == 0)
	{
		//printf("Los milisegundos son: %lu\n", get_current_ms());
		philo_eats(philo, god);
		philo_sleeps(philo, god);
		philo_thinks(philo);
	}
	if (god->philo_is_dead == 1)
		write(1, "HolaEstoyMUERTOOOO", 18);
	return (NULL);
}


void	print_message(t_philo *philo, t_god *god, char *message, int id)
{
	pthread_mutex_lock(&god->prints_lock);
	if (philo->god->philo_is_dead == 0)
		printf("%llu %d %s\n", get_current_ms() - philo->start_time, id, message);
	pthread_mutex_unlock(&god->prints_lock);
}

void	philo_eats(t_philo *philo, t_god *god)
{
	pthread_mutex_lock(&(god->forks[philo->left_fork]));
	print_message(philo, god, "has taken a fork", philo->id);
	pthread_mutex_lock(&(god->forks[philo->right_fork]));
	print_message(philo, god, "has taken a fork", philo->id);
	print_message(philo, god, "is eating", philo->id);
	ft_usleep(philo, god->time_to_eat);
	//printf("El filosofo %d ha terminado de comer con un tiempo de:%lu\n", philo->id, get_current_ms());
	philo->last_eat = get_current_ms();
	philo->times_eaten++;
	pthread_mutex_unlock(&(god->forks[philo->left_fork]));
	pthread_mutex_unlock(&(god->forks[philo->right_fork]));
}

void	philo_sleeps(t_philo *philo, t_god *god)
{
	print_message(philo, god, "is sleeping", philo->id);
	ft_usleep(philo, god->time_to_sleep);
}

void	philo_thinks(t_philo *philo)
{
	print_message(philo, philo->god, "is thinking", philo->id);
	ft_usleep(philo, philo->god->time_to_sleep / 2);
}

long	get_current_ms(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(t_philo *philo, long long max_action_time)
{
	long	time_up;

	time_up = get_current_ms() + max_action_time;
	//printf("El filosofo %d tiene un time_up de %lu\n", philo->id, time_up - get_current_ms());
	while (philo->god->philo_is_dead == 0)
	{
		if (get_current_ms() >= time_up)
			break;
		usleep(20 * 1000);
	}
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
		save_philos_info(philo, god);
		if (start_simulation(god, philo))
			return (write(1, "Error al inicializar los hilos", 31), 1);
		god_sees_everything(god, philo);
		//printf("El current time es %llu\n", get_current_ms() - philo->start_time);
		//printf("El filosofo que salio del hilo fue el %d\n", philo->id);
		//printf("El filosofo %d tiene un valor de philo_is_dead de %i\n", philo->id, god->philo_is_dead);
	}
	else
	{
		write(1, "El numero de argumentos no es el correcto", 42);
		return (0);
	}
}