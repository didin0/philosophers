/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:58:16 by mabbadi           #+#    #+#             */
/*   Updated: 2024/01/17 18:30:26 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	sum;
	int		sign;
	int		i;

	i = 0;
	sum = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		sum = sum * 10 + *str - '0';
		if (sum < 0 && sign == 1)
			return (-1);
		if (sum < 0 && sign == -1)
			return (0);
		str++;
	}
	return (sign * sum);
}

void	print_message(char *str, t_philo *philosopher)
{
	// printf("%d",*philosopher->dead_flag);
	if (*philosopher->dead_flag == 0)
	{
		pthread_mutex_lock(philosopher->mutex);
		printf("%d %d %s\n", get_time() - philosopher->start_time ,
			(int)philosopher->id, str);
		pthread_mutex_unlock(philosopher->mutex);
	}
}

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_sleep(int time, t_philo *philosophers)
{
	int start;

	start = get_time();
	while ((get_time() - start) < time
		&& philosophers->dead_flag == 0)
		usleep(50);
}