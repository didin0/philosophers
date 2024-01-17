/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:03:42 by mabbadi           #+#    #+#             */
/*   Updated: 2024/01/17 19:05:06 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//////////////////////////////////////////////////////
void	philosophers_is_sleeping(t_philo *philosophers)
{
	print_message("is sleeping", philosophers);
	ft_sleep(philosophers->time_to_sleep, philosophers);
}

void	philosophers_is_thinking(t_philo *philosophers)
{
	print_message("is thinking", philosophers);
}
//////////////////////////////////////////////////////

int	philo_fork(t_philo *philo)
{
	if(philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	if(philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (pthread_mutex_unlock(philo->right_fork), 1);
		}
			print_message("has taken a fork", philo);
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (pthread_mutex_unlock(philo->left_fork), 1);
		}
			print_message("has taken a fork", philo);
	}
	return (0);
}

void philosophers_is_eating(t_philo *philosophers)
{
	print_message("is eating", philosophers);
	pthread_mutex_lock(philosophers->mutex);
	philosophers->last_meal = get_time() - philosophers->start_time;
	philosophers->time_to_die = philosophers->last_meal + philosophers->time_to_die;
	pthread_mutex_unlock(philosophers->mutex);
}


void *routinetest(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	int i = 0;
	while(i < 2)
	{
		//  printf("\nphilo[%d] start_time : %d\n\n", i, philo[i].start_time);
		philo_fork(philo);
		philosophers_is_thinking(philo);
		philosophers_is_sleeping(philo);
		philosophers_is_eating(philo);
		i++;
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


	return (0);
}
