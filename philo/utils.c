#include "philo.h"

int	is_numeric(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *num)
{
	int	aux;
	int	neg;

	neg = 1;
	aux = 0;
	while (*num && (*num == ' ' || *num == '\n' || *num == '\t' ||
		*num == '\v' || *num == '\f' || *num == '\r'))
		num++;
	if (*num == '-')
	{
		num++;
		neg = -1;
	}
	if (*num == '+')
		num++;
	while (*num && *num >= '0' && *num <= '9')
	{
		aux = aux * 10 + (*num - 48);
		num++;
	}
	return (aux * neg);
}
