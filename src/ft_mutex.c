/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:58:35 by thed6bel          #+#    #+#             */
/*   Updated: 2023/07/04 14:44:07 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_protect_check(t_philo *philo)
{
	int		value;

	value = 1;
	pthread_mutex_lock(philo->shared->dead);
	if (*(philo->shared->is_dead) == 1)
		value = 0;
	pthread_mutex_unlock(philo->shared->dead);
	return (value);
}

void	ft_protect_write(t_philo *philo, char *str)
{
	if (ft_protect_check(philo))
	{
		pthread_mutex_lock(philo->shared->write_protect);
		printf(str, get_timestamp(philo->tmstp), philo->index);
		pthread_mutex_unlock(philo->shared->write_protect);
	}
}

void	ft_lock(t_philo *philo)
{
	if (philo->index % 2 != 0)
	{
		pthread_mutex_lock(&(philo->fork));
		ft_protect_write(philo, "%d %d has taken a fork\n");
		if (philo->next->balise != 1 && philo->shared->data.nb_philo != 0)
			pthread_mutex_lock(&(philo->next->fork));
		else
			pthread_mutex_lock(&(philo->next->next->fork));
		ft_protect_write(philo, "%d %d has taken a fork\n");
	}
	else
	{
		if (philo->next->balise != 1)
			pthread_mutex_lock(&(philo->next->fork));
		else
			pthread_mutex_lock(&(philo->next->next->fork));
		ft_protect_write(philo, "%d %d has taken a fork\n");
		pthread_mutex_lock(&(philo->fork));
		ft_protect_write(philo, "%d %d has taken a fork\n");
	}
}

void	ft_unlock(t_philo *philo)
{
	if (philo->index % 2 == 0 && philo->next->balise != 1)
	{
		pthread_mutex_unlock(&(philo->fork));
		usleep(100);
		pthread_mutex_unlock(&(philo->next->fork));
	}
	else if (philo->index % 2 != 0 && philo->next->balise != 1)
	{
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
	}
	else if (philo->next->balise == 1 && philo->index % 2 != 0)
	{
		pthread_mutex_unlock(&(philo->next->next->fork));
		pthread_mutex_unlock(&(philo->fork));
	}
	else if (philo->next->balise == 1 && philo->index % 2 == 0)
	{
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->next->fork));
	}
}
