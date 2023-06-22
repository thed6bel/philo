/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:27:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/22 13:54:30 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
/*
void	ft_monitoring(t_philo *philo)
{
	t_philo	*start;

	start = philo;
	while (protect_check(philo))
	{
		if (monitoring_eat(start))
		{
			pthread_mutex_lock(philo->share->dead);
			*(start->share->is_dead) = 1;
			pthread_mutex_unlock(philo->share->dead);
			usleep(2000);
			pthread_mutex_lock(philo->share->protect);
			printf("END\n");
			pthread_mutex_unlock(philo->share->protect);
		}
		philo = ft_check_value(philo);
		if (philo->balise == 1)
			philo = philo->next;
	}
}


*/