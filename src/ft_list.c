/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:19:46 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/27 09:30:49 by thed6bel         ###   ########.fr       */
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
	t_philo			*list;
	t_philo			*buffer[2];
	t_philo			*new_philo;
	struct timeval	time;
	int				i;

	i = 1;
	if (n <= 0)
		return (NULL);
	list = malloc(sizeof(t_philo));
	if (!list)
		return (NULL);
	buffer[0] = list;
	buffer[1] = list;
	gettimeofday(&time, NULL);
	ft_setup_philo(list, i, time, share);
	while (i <= n)
	{
		new_philo = malloc(sizeof(t_philo));
		if (!new_philo)
			return (NULL);
		buffer[1]->next = new_philo;
		buffer[1] = new_philo;
		ft_setup_philo(new_philo, ++i, time, share);
	}
	ft_set_last(list, buffer[0]);
	return (buffer[0]);
}
