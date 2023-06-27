/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:19:46 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/27 13:55:39 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_set_last(t_philo *last, t_philo *first)
{
	last->balise = 1;
	last->next = first;
	last->count = -1;
	last->share = NULL;
	last->id = -1;
}

t_philo	*ft_list_philo(int n, t_share *share)
{
	t_philo			*philo;
	t_philo			*buff[2];
	struct timeval	time;
	int				i;

	i = 1;
	if (n <= 0)
		return (NULL);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		ft_error("Error malloc init\n");
	buff[0] = philo;
	buff[1] = philo;
	gettimeofday(&time, NULL);
	ft_setup_philo(philo, i, time, share);
	while (i <= n)
	{
		philo = malloc(sizeof(t_philo));
		buff[1]->next = philo;
		buff[1] = philo;
		ft_setup_philo(buff[1], ++i, time, share);
	}
	ft_set_last(philo, buff[0]);
	return (buff[0]);
}
