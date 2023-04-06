/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:47:22 by iszitoun          #+#    #+#             */
/*   Updated: 2023/04/06 16:46:40 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_check(char **av)
{
	if (!ft_isdigit(*av[1]) || !ft_isdigit(*av[2]) || !ft_isdigit(*av[3])
		|| !ft_isdigit(*av[4]))
		return (0);
	return (1);
}

void	intialize_args(t_s1 *m, char **av, int ac)
{
	int	i;

	i = 1;
	m->num_of_philo = ft_atoi(av[i++]);
	m->time_to_die = ft_atoi(av[i++]);
	m->time_to_eat = ft_atoi(av[i++]);
	m->time_to_sleep = ft_atoi(av[i++]);
	if (ac == 6)
		m->num_of_times_each_philo_must_eat = ft_atoi(av[i]);
}

void	util_init(t_s3 *m3, t_s1 m, time_t begin)
{
	int	i;

	i = 0;
	while (i < m.num_of_philo)
	{
		(m3)[i].id = i + 1;
		(m3)[i].meals = 0;
		(m3)[i].args = m;
		(m3)[i].begin = begin;
		(m3)[i].last_meal = begin;
		i++;
	}
}

time_t	get_time(time_t start)
{
	struct timeval	tv;
	time_t			ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start;
	return (ms);
}

void	time_to_sleep(int sleep_time)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(100);
		gettimeofday(&end, NULL);
		if (((end.tv_sec * 1000) + (end.tv_usec / 1000)) - ((start.tv_sec
					* 1000) + (start.tv_usec / 1000)) >= sleep_time)
			break ;
	}
}
