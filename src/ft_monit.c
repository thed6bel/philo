/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:27:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/28 10:26:45 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*ft_check_value(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->balise != 1 && ft_protect_check(philo))
	{
		pthread_mutex_lock(philo->share->dead);
		i = get_time(philo->t_stp);
		if ((i - philo->last_eat) > philo->share->data.time_to_die + 1)
		{
			*(philo->share->is_dead) = 1;
			pthread_mutex_lock(philo->share->print_protect);
			printf("%d %d is dead\n", get_time(philo->t_stp), philo->id);
			pthread_mutex_unlock(philo->share->print_protect);
		}
		pthread_mutex_unlock(philo->share->dead);
		philo = philo->next;
	}
	return (philo);
}

int	ft_monitoring_eat(t_philo *philo)
{
	if (philo->share->data.nbr_time_must_eat < 0)
		return (0);
	while (philo->balise != 1)
	{
		pthread_mutex_lock(&philo->count_protect);
		if (philo->count < philo->share->data.nbr_time_must_eat)
		{
			pthread_mutex_unlock(&philo->count_protect);
			return (0);
		}
		pthread_mutex_unlock(&philo->count_protect);
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
			pthread_mutex_lock(philo->share->dead);
			*(start->share->is_dead) = 1;
			pthread_mutex_unlock(philo->share->dead);
			//usleep(2000);
			pthread_mutex_lock(philo->share->print_protect);
			printf("every philosopher have eaten %lld times\n", \
				philo->share->data.nbr_time_must_eat);
			pthread_mutex_unlock(philo->share->print_protect);
		}
		philo = ft_check_value(philo);
		if (philo->balise == 1)
			philo = philo->next;
	}
}
