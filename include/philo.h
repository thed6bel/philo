/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:26:14 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/19 17:32:22 by thed6bel         ###   ########.fr       */
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
	int			nbr_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	nbr_time_must_eat;//si trop long n_t_m_e comme nom
}				t_data;

typedef	struct s_share
{
	t_data			data;
	int				*is_dead;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*protect;
}				t_share;

typedef	struct s_philo
{
	int				balise;
	int				last_eat;
	int				id;
	unsigned int	count;
	t_share			*share;
	pthread_t		thread;
	struct timeval	t_stp;
	pthread_mutex_t	fork;
	pthread_mutex_t	m_count;
	struct s_philo	*next;
}				t_philo;

void	ft_error(char *message);
long	ft_strlen(const char *str);
long	ft_atoi(const char *nptr);
int 	ft_ctrl_arg(char **argv, t_data data);
void	ft_philosopher(t_data philo);
t_share	*ft_setup_share(t_data data);
t_philo *ft_list_philo(int n, t_share *share);


# endif