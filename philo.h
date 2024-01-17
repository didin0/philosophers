/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:05:15 by mabbadi           #+#    #+#             */
/*   Updated: 2024/01/17 18:21:48 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>


typedef struct s_philo
{
	int 	*dead_flag;
	long int				id;
	int					last_meal;
	int					is_eating;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_meals;
	int					start_time;
	pthread_t			thread_id;
	struct s_data	*data;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*mutex;
}	t_philo;

typedef struct s_data
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_meals;
	int					dead_flag;
	int					start_time;
	pthread_mutex_t	fork;
	pthread_mutex_t	mutex;
	t_philo			*philos;
} t_data;

int	is_numeric(int count);
int	string_is_numeric(char *str);
int	all_arguments_are_numbers(char **argv);
int	check_argument(int argc, char **argv);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void	init_philo(t_data *data, t_philo *philo, pthread_mutex_t *fork);
int	init_data(t_data *data, char **argv, t_philo *philo, pthread_mutex_t *fork);
void	ft_sleep(int time, t_philo *philosophers);
int	get_time(void);
void	print_message(char *str, t_philo *philosopher);
void *routine(void *arguments);

#endif