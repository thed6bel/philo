/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:02:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/28 10:28:29 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
		usleep(philo->share->data.time_to_eat * 1000);
	ft_unlock(philo);
}

void	ft_sleeping(t_philo *philo)
{
	ft_protect_print(philo, "%d %d is sleeping\n");
	if (ft_protect_check(philo))
		usleep(philo->share->data.time_to_sleep * 1000);
}

void	ft_thinking(t_philo *philo)
{
	ft_protect_print(philo, "%d %d is thinking\n");
	if (philo->id % 2 != 0 && philo->share->data.time_to_eat >= \
		philo->share->data.time_to_sleep)
		usleep((philo->share->data.time_to_eat - \
			philo->share->data.time_to_sleep + 1) * 1000);
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
