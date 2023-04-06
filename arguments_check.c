/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:19:03 by iszitoun          #+#    #+#             */
/*   Updated: 2023/03/30 01:00:22 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char c)
{
	return (c == 32 || c == '\t' || c == '\n');	
}

int	isit_int(char *ptr)
{
	int	i;

	i = 0;
	if (ft_isspace(ptr[i]))
		i++;
	if (ptr[i] == '+')
		i++;
	if (!ptr[i] && i)
		exit(1);
	while (ptr[i])
	{
		if (!ft_isdigit(ptr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	int_check(char **ptr)
{
	int	i;

	i = 1;
	while (ptr[i])
	{
		if (!isit_int(ptr[i]))
			return (0);
		i++;
	}
	return (1);
}