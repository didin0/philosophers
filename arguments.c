/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:11:15 by mabbadi           #+#    #+#             */
/*   Updated: 2024/01/14 19:13:26 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numeric(int count)
{
	if (count >= 48 && count <= 57)
		return (1);
	else
		return (0);
}

int	string_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_numeric(str[i]) == 0)
			return (0);
	}
	return (1);
}

int	all_arguments_are_numbers(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (string_is_numeric(argv[i]))
			;
		else
			return (0);
	}
	return (1);
}

int	check_argument(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	else if (!all_arguments_are_numbers(argv))
		return (0);
	else
		return (1);
}
