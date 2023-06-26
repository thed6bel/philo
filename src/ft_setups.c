/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:08:34 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/23 14:44:24 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_setup_philo(t_philo *philo, int id, struct timeval time, t_share *s)
{
	philo->balise = 0;
	philo->id = id;
	philo->share = s;
	philo->t_stp = time;
	philo->count = 0;
	philo->last_eat = 0;
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->count_protect, NULL);
}

t_share	*ft_setup_share(t_data data)
{
	t_share	*n;

	n = malloc(sizeof(t_share));
	if (!n)
		return (NULL);
	n->dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!n->dead)
	{
		free(n);
		return (NULL);
	}
	n->print_protect = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!n->print_protect)
	{
		free(n->dead);
		free(n);
		return (NULL);
	}
	n->is_dead = malloc(sizeof(int));
	if (!n->is_dead)
	{
		free(n->dead);
		free(n->print_protect);
		free(n);
		return (NULL);
	}
	n->data = data;
	*(n->is_dead) = 0;
	if (pthread_mutex_init(n->dead, NULL) != 0)
		ft_error("Error: mutex init failed");
	if (pthread_mutex_init(n->print_protect, NULL) != 0)
		ft_error("Error: mutex init failed");
	return (n);
}
