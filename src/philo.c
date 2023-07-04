/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:12:01 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/04 14:58:47 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_thread(t_philo *philo)
{
	t_philo		*buff;

	buff = philo;
	while (buff->balise != 1)
	{
		pthread_create(&(buff->thread), NULL, &ft_routine, buff);
		usleep(philo->index * 50);
		buff = buff->next;
	}
}

static void	ft_free_exit_thread(t_philo *philo)
{
	free(philo->shared->dead);
	free(philo->shared->write_protect);
	free(philo->shared->is_dead);
	free(philo->shared);
}

void	ft_exit_thread(t_philo *philo)
{
	t_philo		*buff;

	buff = philo;
	while (buff->balise != 1)
	{
		if (!(buff->index == 1 && buff->next->balise == 1))
			pthread_join(buff->thread, NULL);
		buff = buff->next;
	}
	if (pthread_mutex_destroy(philo->shared->write_protect) != 0)
		ft_error("Error destroy mutex\n");
	if (pthread_mutex_destroy(philo->shared->dead) != 0)
		ft_error("Error destroy mutex\n");
	ft_free_exit_thread(philo);
	while (philo->balise != 1)
	{
		buff = philo->next;
		if (pthread_mutex_destroy(&(philo->count_protect)) != 0)
			ft_error("Error destroy mutex\n");
		free(philo);
		philo = buff;
	}
	free(philo);
}

void	ft_philosopher(t_data data)
{
	t_philo		*philo;
	t_philo		*buff;
	t_share		*shared;

	shared = ft_set_shared(data);
	philo = ft_set_list(data.nb_philo, shared);
	if (philo == NULL)
		return ;
	buff = philo;
	if (data.nb_philo >= 1)
		ft_thread(buff);
	ft_monitoring(buff);
	ft_exit_thread(philo);
}
