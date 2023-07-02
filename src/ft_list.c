/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:19:46 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/02 15:19:53 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	balised(t_philo *last, t_philo *first)
{
	last->balise = 1;
	last->next = first;
	last->count = -1;
	last->shared = NULL;
	last->index = -1;
}

t_philo	*ft_set_list(int size, t_share *shared)
{
	t_philo			*philo;
	t_philo			*buff[2];
	struct timeval	time;
	int				i;

	i = 1;
	if (size <= 0)
		return (NULL);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		ft_error("Error malloc init failed\n");
	buff[0] = philo;
	buff[1] = philo;
	gettimeofday(&time, NULL);
	ft_set_philo(philo, i, time, shared);
	while (i <= size)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			ft_error("Error malloc init failed\n");
		buff[1]->next = philo;
		buff[1] = philo;
		ft_set_philo(buff[1], ++i, time, shared);
	}
	balised(philo, buff[0]);
	return (buff[0]);
}
