/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:08:34 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/27 12:51:33 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_setup_philo(t_philo *philo, int id, struct timeval t, t_share *s)
{
	philo->balise = 0;
	philo->id = id;
	philo->share = s;
	philo->t_stp = t;
	philo->count = 0;
	philo->last_eat = 0;
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->count_protect, NULL);
}

t_share	*ft_setup_share(t_data data)
{
	t_share	*ret;

	ret = malloc(sizeof(t_share));
	ret->dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	ret->print_protect = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	ret->is_dead = malloc(sizeof(int));
	ret->data = data;
	*(ret->is_dead) = 0;
	pthread_mutex_init(ret->dead, NULL);
	pthread_mutex_init(ret->print_protect, NULL);
	return (ret);
}

// a controler!!

char	*ft_free_setup_share(t_share *share)
{
	if (!share->dead)
	{
		free(share);
		//pthread_mutex_destroy(share->dead);//a verifier
		return (NULL);
	}
	if (!share->print_protect)
	{
		free(share->dead);
		free(share);
		// pthread_mutex_destroy(share->dead);//a verifier
		// pthread_mutex_destroy(share->print_protect);//a verifier
		return (NULL);
	}
	if (!share->is_dead)
	{
		free(share->dead);
		free(share->print_protect);
		free(share);
		// pthread_mutex_destroy(share->dead);//a verifier
		// pthread_mutex_destroy(share->print_protect);//a verifier
		return (NULL);
	}
}
