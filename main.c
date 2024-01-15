/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:03:42 by mabbadi           #+#    #+#             */
/*   Updated: 2024/01/15 18:19:47 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, t_philo *philo, pthread_mutex_t *fork)
{
	int	i;
	int	nb;

	data->philos = philo;
	i = 0;
	nb = data->number_of_philosophers;
	while (i < nb)
	{
		philo[i].time_to_sleep = data->time_to_sleep;
		philo[i].time_to_die = data->time_to_die;
		philo[i].number_of_meals = data->number_of_meals;
		philo[i].time_to_eat = data->time_to_eat;
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = &fork[i + 1];
		i++;
	}
			printf("leftfork0 : %p\n", philo[0].left_fork);
			printf("leftright0 : %p\n", philo[0].right_fork);
}

int	init_data(t_data *data, char **argv, t_philo *philo, pthread_mutex_t *fork)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->number_of_meals = ft_atoi(argv[5]);
	else
		data->number_of_meals = -1;
	init_philo(data, philo, fork);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			philo[250];
	pthread_mutex_t	fork[250];

	if (check_argument(argc, argv))
	{
		if (init_data(&data, argv, philo, fork))
		{
			printf("leftfork0 : %p\n", data.philos[0].left_fork);
			printf("leftright0 : %p\n", data.philos[0].right_fork);
		}
	}
	return (0);
}
