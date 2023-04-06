/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:34:56 by iszitoun          #+#    #+#             */
/*   Updated: 2023/04/06 16:47:05 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *m3)
{
	t_s3	*x;
	x = (t_s3 *)m3;

	while (1)
	{
		eating(x);
		sleeping(x);
		print_msg(m3, "is thinking");
	}
	return NULL;
	

}

void	create_threads(t_s3	*m3)
{
	int	i;

	i = 0;
	while (i < m3->args.num_of_philo)
	{
		pthread_create(&m3[i].philo, NULL, routine, &m3[i]);
		usleep(100);
		i++;
	}

}

void	mutex_init(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (pthread_mutex_init(&(forks[i]), NULL))
			printf("failed\n");
		i++;
	}
	
}

int	philo_init(t_s3 *m3, t_s1 m, time_t begin)
{
	pthread_mutex_t	*forks;
	int				i;
	pthread_mutex_t	*mtx_write;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * m.num_of_philo);
	mtx_write = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mtx_write, NULL);
	mutex_init(forks, m.num_of_philo);
	while (i < m.num_of_philo)
	{
		(m3[i]).fork.right = &(forks[i]);
		(m3[i]).fork.left = &(forks[(i + 1) % m.num_of_philo]);
		(m3[i]).write = mtx_write;
		if (pthread_mutex_init(&(m3)[i].status, NULL))
			return(error_msg("FAIL INIT\n", 14, 1));
		i++;
	}
	util_init(m3, m, begin);
	return (0);
	
}

int check(char **av)
{
	int i = 1;

	while (av[i])
	{
		if (ft_atoi(av[i]) == 0)
			return 0;
		i++;
	}
	return 1;
}

int	main(int ac, char **av)
{
	t_s1 m;
	t_s3 *m3;
	time_t	begin;
	int i = 0;

	begin = get_time(0);
	if ((ac != 6 && ac != 5) || !int_check(av) || !args_check(av))
	{
		error_msg("Check your arguments\n", 21, 1);
		return (1);
	}
	intialize_args(&m, av, ac);
	m3 = malloc(sizeof(t_s3) * m.num_of_philo);
	philo_init(m3, m, begin);
	create_threads(m3);
	while (i < ft_atoi(av[1]))
		pthread_detach(m3[i++].philo);
	while (1)
	{
		if (rip_philo(m3))
			break ;
		if (meals_completed(m3) && ac == 6)
			break ;
	}
}
