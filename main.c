/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:03:42 by mabbadi           #+#    #+#             */
/*   Updated: 2024/01/19 00:27:28 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//////////////////////////////////////////////////////

void	*monitoring(void *arg, t_philo *philo)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		if (dead(philo) == 0)
		{
			usleep(100);
			return (pthread_mutex_unlock(&data->mutex), NULL);
		}
		pthread_mutex_unlock(&data->mutex);
		usleep(200);
	}
}

//////////////////////////////////////////////////////

int	check_last_meal(t_philo *philo)
{
	if (get_time() - philo->start_time > philo->time_to_die)
	{
		philo[0].dead_flag = 1;
		printf("%d %d died\n", get_time() - philo->start_time, philo->id);
		return (0);
	}
	else
		return (1);
}

int	hungry(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < (*philo->number_of_philosophers))
	{
		if (check_last_meal(&philo[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int dead(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	if (philo->dead_flag == 1)
	{
		pthread_mutex_unlock(philo->mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex);
	return (0);
}

void *routinetest(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	while(philo->dead_flag == 0)
	{
		if (dead(philo))
			return (0);
		philo_fork(philo);
		if (dead(philo))
			return (0);
		philosophers_is_eating(philo);
		if (dead(philo))
			return (0);
		philosophers_is_sleeping(philo);
		if (dead(philo))
			return (0);
		philosophers_is_thinking(philo);
	}
	return (NULL);
}

void test(t_data *data, char **argv, t_philo *philo, pthread_mutex_t *fork)
{
	init_data(data, argv, philo, fork);
	int i = 0;
	while( i < data->number_of_philosophers)
	{
		pthread_create(&philo[i].thread_id, NULL, (void *)&routinetest, &philo[i]);
		i++;
	}
	i = 0;
	while( i < data->number_of_philosophers)
	{ 
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&data->mutex);
}

int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			philo[250];
	pthread_mutex_t	fork[250];

	test(&data, argv, philo, fork);
	monitoring(&data, philo);


	return (0);
}
