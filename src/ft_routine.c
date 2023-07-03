/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:02:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/03 11:53:10 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*ft_timer(t_philo *philo, unsigned int time)
{
	unsigned int	i;

	i = 0;
	while (i < time && ft_protect_check(philo))
	{
		usleep(20000);
		pthread_mutex_lock(philo->shared->dead);
		if (*(philo->shared->is_dead) == 1)
		{
			pthread_mutex_unlock(philo->shared->dead);
			return (NULL);
		}
		pthread_mutex_unlock(philo->shared->dead);
		i += 20000;
	}
	return (NULL);
}

void	ft_eating(t_philo *philo)
{
	ft_lock(philo);
	//printf("test ft_eating\n");
	//usleep(100);
	//pthread_mutex_lock(philo->shared->dead);
	philo->last_meal = get_timestamp(philo->tmstp);
	//pthread_mutex_unlock(philo->shared->dead);
	ft_protect_write(philo, "%d %d is eating\n");
	pthread_mutex_lock(&(philo->count_protect));
	philo->count += 1;
	pthread_mutex_unlock(&(philo->count_protect));
	if (ft_protect_check(philo))
		ft_usleep(philo->shared->data.time_eat + 1);
	//usleep(philo->shared->data.time_eat * 1000);
	ft_unlock(philo);
}

void	ft_sleeping(t_philo *philo)
{
	ft_protect_write(philo, "%d %d is sleeping\n");
	if (ft_protect_check(philo))
	{
		if (philo->shared->data.time_sleep == 0)
			usleep(0);
		else
			//usleep(philo->shared->data.time_sleep * 1000);
			ft_usleep(philo->shared->data.time_sleep + 1);
	}
}

void	ft_thinking(t_philo *philo)
{
	ft_protect_write(philo, "%d %d is thinking\n");
	// if (philo->index % 2 != 0 && philo->shared->data.time_eat
	// 	>= philo->shared->data.time_sleep)
	// 	usleep(((philo->shared->data.time_eat - philo->shared->data.time_sleep + 1)
	// 		* 1000) / 2);
	usleep(100);
}

void	*ft_routine(void *philo)
{
	t_philo		*buff;

	buff = (t_philo *)philo;
	if (buff->index % 2 == 0)
		usleep((buff->shared->data.time_eat * 100) / 2);
	while (ft_protect_check(buff))
	{
		if (ft_protect_check(philo))
			ft_eating(buff);
		if (ft_protect_check(philo))
			ft_sleeping(buff);
		if (ft_protect_check(philo))
			ft_thinking(buff);
		//usleep(100);
	}
	return (philo);
}
