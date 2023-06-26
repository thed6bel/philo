/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:12:01 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/23 11:17:24 by thed6bel         ###   ########.fr       */
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
	ft_monit_threads(buffer);
	ft_exit_and_free(philo);
}
