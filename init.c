/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:38:32 by mabbadi           #+#    #+#             */
/*   Updated: 2024/01/17 18:22:23 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, t_philo *philo, pthread_mutex_t *fork)
{
	long	i;
	int	nb;

	data->philos = philo;
	data->philos->data = data;
	i = 0;
	nb = data->number_of_philosophers;
	while (i < nb)
	{
		philo[i].id = (i + 1);
		philo[i].time_to_sleep = data->time_to_sleep;
		philo[i].time_to_die = data->time_to_die;
		philo[i].number_of_meals = data->number_of_meals;
		philo[i].time_to_eat = data->time_to_eat;
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = &fork[i + 1];
		philo[i].dead_flag = &data->dead_flag;
		philo[i].mutex = &data->mutex;
		philo[i].start_time = get_time();
		i++;
	}
}

int	init_data(t_data *data, char **argv, t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_init(&data->fork, NULL);
	pthread_mutex_init(&data->mutex, NULL);
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dead_flag = 0;
	if (argv[5])
		data->number_of_meals = ft_atoi(argv[5]);
	else
		data->number_of_meals = -1;
	init_philo(data, philo, fork);
	return (1);
}