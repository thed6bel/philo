/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:12:01 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:08:36 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_make_threads(t_philo *philo)
{
	t_philo	*buffer;

	buffer = philo;
	while (buffer->balise != 1)
	{
		pthread_create(&(buffer->thread), NULL, &ft_routine, buffer);
		//usleep(philo->id * 100);
		buffer = buffer->next;
	}
}

static void	ft_exit_and_free(t_philo *philo)
{
	t_philo	*buffer;

	buffer = philo;
	while (buffer->balise != 1)
	{
		if (!(buffer->id == 1 && buffer->next->balise == 1))
			pthread_join(buffer->thread, NULL);
		buffer = buffer->next;
	}
	if (pthread_mutex_destroy(philo->share->print_protect) != 0)
		ft_error("Error destroy mutex");
	if (pthread_mutex_destroy(philo->share->dead) != 0)
		ft_error("Error destroy mutex");
	free(philo->share->is_dead);
	free(philo->share->print_protect);
	free(philo->share->dead);
	free(philo->share);
	while (philo->balise != 1)
	{
		buffer = philo->next;
		if (pthread_mutex_destroy(&philo->fork) != 0)
			ft_error("Error destroy mutex");
		if (pthread_mutex_destroy(&philo->count_protect) != 0)
			ft_error("Error destroy mutex");
		free(philo);
		philo = buffer;
	}
	free(philo);
	//ft_free_list(philo);//peut etre faire un ft a part
}

void	ft_philosopher(t_data data)
{
	t_philo			*philo;
	t_philo			*buff;
	t_share			*share;

	share = ft_setup_share(data);
	philo = ft_list_philo(data.nbr_philo, share);
	if (philo == NULL)
		ft_error("Error");
	buff = philo;
	if (data.nbr_philo > 1)
		ft_make_threads(buff);
	ft_monitoring(buff);
	ft_exit_and_free(philo);
}
