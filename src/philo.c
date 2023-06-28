/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:12:01 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/28 18:58:43 by thed6bel         ###   ########.fr       */
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
		//usleep(100); arsene a ajouter un delais mais pourquoi?
		buffer = buffer->next;
	}
}

void	ft_exit_and_free(t_philo *philo)
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
		ft_error("Error destroy mutex[ft_exit_and_free1]\n");
	if (pthread_mutex_destroy(philo->share->dead) != 0)
		ft_error("Error destroy mutex[ft_exit_and_free2]\n");
	free(philo->share->is_dead);
	free(philo->share->print_protect);
	free(philo->share->dead);
	free(philo->share);
	while (philo->balise != 1)
	{
		buffer = philo->next;
		if (pthread_mutex_destroy(&philo->fork) != 0)
			printf("Error destroy mutex[ft_exit_and_free3]\n");
		if (pthread_mutex_destroy(&philo->count_protect) != 0)
			printf("Error destroy mutex[ft_exit_and_free4]\n");
		free(philo);
		philo = buffer;
	}
	free(philo);
}

void	ft_exit_and_free1philo(t_philo *philo)
{
	if (pthread_mutex_destroy(&philo->fork) != 0)
		printf("Error destroy mutex[ft_exit_and_free1philo1]\n");
	free(philo->share);
	if (pthread_mutex_destroy(&philo->count_protect) != 0)
		printf("Error destroy mutex[ft_exit_and_free1philo3]\n");
	free(philo);
	exit(0);
}

void	ft_philosopher(t_data data)
{
	t_philo			*philo;
	t_philo			*buff;
	t_share			*share;

	share = ft_setup_share(data);
	philo = ft_list_philo(data.nbr_philo, share);
	if (philo == NULL)
		ft_error("Error\n");
	buff = philo;
	if (data.nbr_philo >= 1)
		ft_make_threads(buff);
	ft_monitoring(buff);
	ft_exit_and_free(philo);
}
