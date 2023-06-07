/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:12:01 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/06 13:56:57 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_make_threads(t_philo *philo)
{

	
}

static void	ft_exit_and_free(t_philo *philo)
{

	//ont attend de voir pour les free et destroy!
	//mutex_destroy
}

void	ft_philosopher(t_data data)
{
	t_philo	*philo;
	t_philo	*buffer;
	t_share	*share;

	share = ft_setup_share(data);
	philo = ft_list_philo(data.nbr_philo, share);
	buffer = philo;
	if (data.nbr_philo >= 1)
		ft_make_threads(buffer);
	//ft_monit_threads(buffer);
	//ft_exit_and_free(philo);
}
