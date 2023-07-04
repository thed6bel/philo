/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:27:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/04 13:14:25 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_philo	*ft_check_value(t_philo *philo)
{
	int		time;

	time = 0;
	while (philo->balise != 1 && ft_protect_check(philo))
	{
		pthread_mutex_lock(philo->shared->dead);
		time = get_timestamp(philo->tmstp);
		if ((time - philo->last_meal) > (philo->shared->data.time_dead))
		{
			*(philo->shared->is_dead) = 1;
			pthread_mutex_lock(philo->shared->write_protect);
			printf("%d %d died\n", get_timestamp(philo->tmstp),
				philo->index);
			pthread_mutex_unlock(philo->shared->write_protect);
		}
		pthread_mutex_unlock(philo->shared->dead);
		philo = philo->next;
	}
	return (philo);
}

static int	ft_monitoring_eat(t_philo *philo)
{
	if (philo->shared->data.need_eat < 0)
		return (0);
	while (philo->balise != 1)
	{
		pthread_mutex_lock(&(philo->count_protect));
		if (philo->count < philo->shared->data.need_eat)
		{
			pthread_mutex_unlock(&(philo->count_protect));
			return (0);
		}
		pthread_mutex_unlock(&(philo->count_protect));
		philo = philo->next;
	}
	return (1);
}

void	ft_monitoring(t_philo *philo)
{
	t_philo	*start;

	start = philo;
	while (ft_protect_check(philo))
	{
		if (ft_monitoring_eat(start))
		{
			pthread_mutex_lock(philo->shared->dead);
			*(start->shared->is_dead) = 1;
			pthread_mutex_unlock(philo->shared->dead);
			usleep(100);
			pthread_mutex_lock(philo->shared->write_protect);
			printf("every philosopher have eaten %d times\n", \
				philo->shared->data.need_eat);
			pthread_mutex_unlock(philo->shared->write_protect);
		}
		philo = ft_check_value(philo);
		if (philo->balise == 1)
			philo = philo->next;
	}
}
