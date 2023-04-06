/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:43 by iszitoun          #+#    #+#             */
/*   Updated: 2023/04/06 16:46:13 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (!ft_isdigit(str[i]))
		return (-1);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > LONG_MAX && sign == -1)
		return (0);
	else if (result > LONG_MAX && sign == 1)
		return (-1);
	return (sign * result);
}

int	ft_strlen (const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	meals_completed(t_s3 *m3)
{
	int	i;
	int	meals;

	i = 0;
	meals = 0;
	while (i < m3->args.num_of_philo)
	{
		pthread_mutex_lock(&m3[i].status);
		if (m3[i].meals == m3->args.num_of_times_each_philo_must_eat)
			meals++;
		pthread_mutex_unlock(&m3[i].status);
		i++;
	}
	if (meals == m3->args.num_of_philo)
		return (1);
	return (0);
}

int	rip_philo(t_s3 *m3)
{
	int	i;

	i = 0;
	while (i < m3->args.num_of_philo)
	{
		pthread_mutex_lock(&m3[i].status);
		if (get_time(m3[i].last_meal) > m3[i].args.time_to_die)
		{
			pthread_mutex_unlock(&m3[i].status);
			pthread_mutex_lock(m3[i].write);
			printf("%ld ms %d %s\n", get_time(m3[i].begin), m3[i].id,
				"died");
			return (1);
		}
		pthread_mutex_unlock(&m3[i].status);
		i++;
	}
	return (0);
}
