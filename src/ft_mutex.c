/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:58:35 by thed6bel          #+#    #+#             */
/*   Updated: 2023/06/28 18:50:34 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_protect_check(t_philo *philo)
{
	int	i;

	i = 1;
	pthread_mutex_lock(philo->share->dead);
	if (*(philo->share->is_dead) == 1)
		i = 0;
	pthread_mutex_unlock(philo->share->dead);
	return (i);
}

void	ft_protect_print(t_philo *philo, char *str)
{
	if (ft_protect_check(philo))
	{
		pthread_mutex_lock(philo->share->print_protect);
		printf(str, get_time(philo->t_stp), philo->id);
		pthread_mutex_unlock(philo->share->print_protect);
	}
}

void	ft_lock(t_philo *philo)
{
	if (philo->share->data.nbr_philo == 1)
	{
		ft_protect_print(philo, "%d %d has taken a fork\n");
		ft_exit_and_free1philo(philo);
	}
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&(philo->fork));
		ft_protect_print(philo, "%d %d has taken a fork\n");
		if (philo->next->balise != 1)
			pthread_mutex_lock(&(philo->next->fork));
		else
			pthread_mutex_lock(&(philo->next->next->fork));
		ft_protect_print(philo, "%d %d has taken a fork\n");
	}
	else
	{
		if (philo->next->balise != 1)
			pthread_mutex_lock(&(philo->next->fork));
		else
			pthread_mutex_lock(&(philo->next->next->fork));
		ft_protect_print(philo, "%d %d has taken a fork\n");
		pthread_mutex_lock(&(philo->fork));
		ft_protect_print(philo, "%d %d has taken a fork\n");
	}
}

void	ft_unlock(t_philo *philo)
{
	if (philo->id % 2 == 0 && philo->next->balise != 1)
	{
		pthread_mutex_unlock(&(philo->fork));
		//usleep(100);
		pthread_mutex_unlock(&(philo->next->fork));
	}
	else if (philo->id % 2 != 0 && philo->next->balise != 1)
	{
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
	}
	else if (philo->next->balise == 1 && philo->id % 2 != 0)
	{
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->next->fork));
	}
	else if (philo->next->balise == 1 && philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->next->fork));
	}
}
