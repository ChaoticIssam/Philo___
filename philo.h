#ifndef PHILO_H_
# define PHILO_H_

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_s1
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
}					t_s1;

typedef struct s_s2
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_s2;

typedef struct s_s3
{
	int				id;
	pthread_t		philo;
	int				meals;
	t_s1			args;
	t_s2			fork;
	time_t			last_meal;
	time_t			begin;
	pthread_mutex_t	*write;
	pthread_mutex_t	status;
}					t_s3;

int					isit_int(char *ptr);
int					int_check(char **ptr);

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					meals_completed(t_s3 *m3);
int					rip_philo(t_s3 *m3);

int					args_check(char **av);
void				intialize_args(t_s1 *m, char **av, int ac);
void				util_init(t_s3 *m3, t_s1 m, time_t begin);
time_t				get_time(time_t start);

void				eating(t_s3 *m3);
void				sleeping(t_s3 *m3);
void				*routine(void *m2);
void				time_to_sleep(int sleep_time);

void				print_msg(t_s3 *m3, char *msg);
int					error_msg(char *msg, int size, int x);
void				my_usleep(long t);

#endif