/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:05:15 by mabbadi           #+#    #+#             */
/*   Updated: 2024/01/15 18:14:18 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_philo
{
	int					id;
	int					last_meal;
	int					is_eating;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_meals;
	pthread_t			thread_id;
	struct s_data	*data;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}	t_philo;

typedef struct s_data
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_meals;
	pthread_mutex_t	*fork;
	t_philo			*philos;
} t_data;

int	is_numeric(int count);
int	string_is_numeric(char *str);
int	all_arguments_are_numbers(char **argv);
int	check_argument(int argc, char **argv);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
#endif