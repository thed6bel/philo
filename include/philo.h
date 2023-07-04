/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:26:14 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/04 14:39:38 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_data
{
	int		nb_philo;
	int		time_dead;
	int		time_eat;
	int		time_sleep;
	int		need_eat;
}	t_data;

typedef struct s_share
{
	t_data				data;
	int					*is_dead;
	pthread_mutex_t		*dead;
	pthread_mutex_t		*write_protect;
}	t_share;

typedef struct s_philo
{
	int					balise;
	int					index;
	int					count;
	int					last_meal;
	t_share				*shared;
	pthread_t			thread;
	struct timeval		tmstp;
	pthread_mutex_t		fork;
	pthread_mutex_t		count_protect;
	struct s_philo		*next;
}	t_philo;

// ft_list.c
t_philo	*ft_set_list(int size, t_share *shared);

// ft_monit.c
void	ft_monitoring(t_philo *philo);

// ft_mutex.c
void	ft_unlock(t_philo *philo);
void	ft_lock(t_philo *philo);
void	ft_protect_write(t_philo *philo, char *str);
int		ft_protect_check(t_philo *philo);

// ft_routine.c
void	ft_eating(t_philo *philo);
void	ft_sleeping(t_philo *philo);
void	ft_thinking(t_philo *philo);
void	*ft_routine(void *philo);

// ft_setup.c
t_share	*ft_set_shared(t_data arg);
void	ft_set_philo(t_philo *philo, int index, struct timeval time, t_share *s);
void	ft_free_setup_share(t_share *share);

// ft_tools.c
void	ft_error(char *message);
int		ft_strlen(char *str);
int		get_timestamp(struct timeval start);
int		ft_atoi2(const char *nptr, int *n);
int		ft_ctrl_arg(char **argv, t_data data);

// philo.c
void	ft_philosopher(t_data data);
void	ft_exit_thread(t_philo *philo);
void	ft_exit_and_free1philo(t_philo *philo);

// ft_time.c
int			ft_usleep(useconds_t usec);

#endif