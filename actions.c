/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:08:47 by mabbadi           #+#    #+#             */
/*   Updated: 2024/01/19 00:00:24 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophers_is_sleeping(t_philo *philosophers)
{
	print_message("is sleeping", philosophers);
	ft_sleep(philosophers->time_to_sleep, philosophers);
}

void	philosophers_is_thinking(t_philo *philosophers)
{
	print_message("is thinking", philosophers);
}

void	philosophers_is_eating(t_philo *philosophers)
{
	print_message("is eating", philosophers);
	pthread_mutex_lock(philosophers->mutex);
	philosophers->last_meal = get_time() - philosophers->start_time;
	philosophers->time_to_die = philosophers->last_meal
		+ philosophers->time_to_die;
	pthread_mutex_unlock(philosophers->mutex);
}

int	philo_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (!dead(philo))
		print_message("has taken a fork", philo);
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (pthread_mutex_unlock(philo->right_fork), 1);
		}
	if (!dead(philo))
		print_message("has taken a fork", philo);
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (pthread_mutex_unlock(philo->left_fork), 1);
		}
	if (!dead(philo))
		print_message("has taken a fork", philo);
	}
	return (0);
}
