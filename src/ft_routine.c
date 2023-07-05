/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:02:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/05 09:58:05 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eating(t_philo *philo)
{
	ft_lock(philo);
	pthread_mutex_lock(philo->shared->dead);
	philo->last_meal = get_timestamp(philo->tmstp);
	pthread_mutex_unlock(philo->shared->dead);
	ft_protect_write(philo, "%d %d is eating\n");
	pthread_mutex_lock(&(philo->count_protect));
	philo->count += 1;
	pthread_mutex_unlock(&(philo->count_protect));
	if (ft_protect_check(philo))
		ft_usleep(philo->shared->data.time_eat);
	ft_unlock(philo);
}

void	ft_sleeping(t_philo *philo)
{
	ft_protect_write(philo, "%d %d is sleeping\n");
	if (ft_protect_check(philo))
	{
		if (philo->shared->data.time_sleep == 0)
			return ;
		else
			ft_usleep(philo->shared->data.time_sleep);
	}
}

void	ft_thinking(t_philo *philo)
{
	ft_protect_write(philo, "%d %d is thinking\n");
	if (philo->index % 2 != 0 && philo->shared->data.time_eat
		>= philo->shared->data.time_sleep)
		ft_usleep((philo->shared->data.time_eat - \
			philo->shared->data.time_sleep + 1));
}

void	*ft_routine(void *philo)
{
	t_philo		*buff;

	buff = (t_philo *)philo;
	if (buff->index % 2 == 0)
		ft_usleep((buff->shared->data.time_eat) / 2);
	while (ft_protect_check(buff))
	{
		if (ft_protect_check(philo))
			ft_eating(buff);
		if (ft_protect_check(philo))
			ft_sleeping(buff);
		if (ft_protect_check(philo))
			ft_thinking(buff);
	}
	return (philo);
}
