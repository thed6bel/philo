/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:02:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/28 17:08:34 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*ft_timer(t_philo *philo, long long time)
{
	unsigned long long	i;

	i = 0;
	while (i < time && ft_protect_check(philo))
	{
		usleep(1000);
		pthread_mutex_lock(philo->share->dead);
		if (*(philo->share->is_dead) == 1)  
		{
			pthread_mutex_unlock(philo->share->dead);
			return (NULL);
		}
		pthread_mutex_unlock(philo->share->dead);
		i += 1000;
	}
}

void	ft_eating(t_philo *philo)
{
	ft_lock(philo);
	pthread_mutex_lock(philo->share->dead);
	philo->last_eat = get_time(philo->t_stp);
	pthread_mutex_unlock(philo->share->dead);
	ft_protect_print(philo, "%d %d is eating\n");
	pthread_mutex_lock(&philo->count_protect);
	philo->count++;
	pthread_mutex_unlock(&philo->count_protect);
	if (ft_protect_check(philo))
		ft_timer(philo, philo->share->data.time_to_eat * 1000);
	ft_unlock(philo);
}

void	ft_sleeping(t_philo *philo)
{
	ft_protect_print(philo, "%d %d is sleeping\n");
	if (ft_protect_check(philo))
		ft_timer(philo, philo->share->data.time_to_sleep * 1000);
}

void	ft_thinking(t_philo *philo)
{
	ft_protect_print(philo, "%d %d is thinking\n");
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (ft_protect_check(philo))
	{
		if (ft_protect_check(philo))
			ft_eating(philo);
		if (ft_protect_check(philo))
			ft_sleeping(philo);
		if (ft_protect_check(philo))
			ft_thinking(philo);
	}
	return (arg);
}
