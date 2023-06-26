/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:26:14 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/23 14:43:23 by thed6bel         ###   ########.fr       */
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
	long long	nbr_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	nbr_time_must_eat;
}				t_data;

typedef struct s_share
{
	t_data			data;
	int				*is_dead;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*print_protect;
}				t_share;

typedef struct s_philo
{
	int				balise;//pour la fin de la liste
	int				last_eat;
	int				id;
	int				count;
	t_share			*share;
	pthread_t		thread;
	struct timeval	t_stp;
	pthread_mutex_t	fork;
	pthread_mutex_t	count_protect;
	struct s_philo	*next;
}				t_philo;

// ft_ctrl_arg.c
int		ft_ctrl_arg(char **argv, t_data data);

// ft_list.c
t_philo	*ft_list_philo(int n, t_share *share);

// ft_monit.c
void	ft_monitoring(t_philo *philo);

// ft_routine.c
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	*ft_routine(void *arg);

// ft_setup.c
t_share	*ft_setup_share(t_data data);
void	*ft_setup_philo(t_philo *philo, int index, struct timeval time, t_shared *share);

// ft_tools.c
void	ft_error(char *message);
long	ft_strlen(const char *str);
int		ft_atoi2(const char *nptr, long long int *n);

// philo.c
void	ft_philosopher(t_data philo);

#endif