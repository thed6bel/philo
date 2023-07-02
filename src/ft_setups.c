/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:08:34 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/02 15:21:56 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_set_philo(t_philo *philo, int index, struct timeval time, t_share *s)
{
	philo->balise = 0;
	philo->index = index;
	philo->count = 0;
	philo->last_meal = 0;
	philo->shared = s;
	philo->tmstp = time;
	pthread_mutex_init(&(philo->fork), NULL);
	pthread_mutex_init(&(philo->count_protect), NULL);
}

t_share	*ft_set_shared(t_data arg)
{
	t_share	*ret;

	ret = malloc(sizeof(t_share));
	if (!ret)
		return (NULL);
	ret->dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!ret->dead)
	{
		free(ret);
		return (NULL);
	}
	ret->write_protect = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!ret->write_protect)
	{
		free(ret->dead);
		free(ret);
		return (NULL);
	}
	ret->is_dead = malloc(sizeof(int));
	if (!ret->is_dead)
	{
		free(ret->dead);
		free(ret->write_protect);
		free(ret);
		return (NULL);
	}
	ret->data = arg;
	*(ret->is_dead) = 0;
	pthread_mutex_init(ret->dead, NULL);
	pthread_mutex_init(ret->write_protect, NULL);
	return (ret);
}

// a controler!!

void	ft_free_setup_share(t_share *share)
{
	if (!share->dead)
	{
		free(share);
		//pthread_mutex_destroy(share->dead);//a verifier
		ft_error("Error: malloc init failed\n");
	}
	else if (!share->write_protect)
	{
		free(share->dead);
		free(share);
		// pthread_mutex_destroy(share->dead);//a verifier
		// pthread_mutex_destroy(share->print_protect);//a verifier
		ft_error("Error: malloc init failed\n");
	}
	else if (!share->is_dead)
	{
		free(share->dead);
		free(share->write_protect);
		free(share);
		// pthread_mutex_destroy(share->dead);//a verifier
		// pthread_mutex_destroy(share->print_protect);//a verifier
		ft_error("Error: malloc init failed\n");
	}
}
