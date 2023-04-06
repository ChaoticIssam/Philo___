/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:49:22 by iszitoun          #+#    #+#             */
/*   Updated: 2023/04/06 16:36:36 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_s3 *m3)
{
	pthread_mutex_lock(m3->fork.right);
	print_msg(m3, "has taken a fork");
	pthread_mutex_lock(m3->fork.left);
	print_msg(m3, "has taken a fork");
	print_msg(m3, "is eating");
	pthread_mutex_lock(&m3->status);
	m3->last_meal = get_time(0);
	m3->meals++;
	pthread_mutex_unlock(&m3->status);
	time_to_sleep(m3->args.time_to_sleep);
	pthread_mutex_unlock(m3->fork.right);
	pthread_mutex_unlock(m3->fork.left);
}

void	sleeping(t_s3 *m3)
{
	print_msg(m3, "is sleeping");
	time_to_sleep(m3->args.time_to_sleep);
}