/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:12:01 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/27 10:49:50 by thed6bel         ###   ########.fr       */
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
		//usleep(philo->id * 100); a verifier si besoin!!
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
	pthread_mutex_destroy(philo->share->print_protect);
	pthread_mutex_destroy(philo->share->dead);
	free(philo->share->is_dead);
	free(philo->share->print_protect);
	free(philo->share->dead);
	free(philo->share);
	while (philo->balise != 1)
	{
		buffer = philo->next;
		pthread_mutex_destroy(&philo->fork);
		pthread_mutex_destroy(&philo->count_protect);
		free(philo);
		philo = buffer;
	}
	free(philo);
	//ft_free_list(philo);//peut etre faire un ft a part
}

void	ft_philosopher(t_data data)
{
	t_philo	*philo;
	t_philo	*buffer;
	t_share	*share;

	share = ft_setup_share(data);// init malloc
	philo = ft_list_philo(data.nbr_philo, share);
	if (!philo)
		ft_error("Error");
	buffer = philo;
	ft_make_threads(buffer);
	ft_monitoring(buffer);
	ft_exit_and_free(philo);
}
