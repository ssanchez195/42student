#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo t_philo;

typedef struct s_god
{
	int				philo_count;
	int				times_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_is_dead;
	long			start_time;
	pthread_mutex_t die_mutex;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	prints_lock;
	pthread_mutex_t	eat_mutex;
	t_philo			*philo;
}	t_god;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				times_eaten;
	long long			start_time;
	long long			last_eat;
	pthread_t		thread;
	t_god			*god;
}	t_philo;


// Function declarations
int	check_arguments(char **argv);
int	start_simulation(t_god *god, t_philo *philo);
int	is_numeric(char *argv);
int	ft_atoi(char *num);
int	god_checks_time(t_philo *philo, t_god *god);
long long	get_current_ms(void);
void	ft_usleep(t_philo *philo, long long max_action_time);
void	god_args(char **argv, t_god *god);
void	save_philos_info(t_philo *philo, t_god *god);
void	*philo_sequence(void *info);
void	god_sees_everything(t_god *god, t_philo *philo);
void	philo_eats(t_philo *philo, t_god *god);
void	philo_sleeps(t_philo *philo, t_god *god);
void	philo_thinks(t_philo *philo);
void	max_action_time(t_philo *philo, int action_time);
void	print_message(t_philo *philo, t_god *god, char *message, int id);

#endif