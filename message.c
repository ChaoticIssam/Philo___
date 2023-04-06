/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:23:27 by iszitoun          #+#    #+#             */
/*   Updated: 2023/04/06 16:17:18 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_s3 *m3, char *msg)
{
	pthread_mutex_lock(m3->write);
	printf("%ld ms %d %s\n", get_time(m3->begin), m3->id, msg);
	pthread_mutex_unlock(m3->write);
}

int	error_msg(char *msg, int size, int x)
{
	write(2, msg, size);
	return (x);
}
