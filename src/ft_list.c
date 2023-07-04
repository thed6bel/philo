/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:19:46 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/04 14:11:55 by hucorrei         ###   ########.fr       */
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
	t_philo			*buff[3];
	struct timeval	time;
	int				i;

	i = 1;
	if (size <= 0)
		return (NULL);
	buff[2] = malloc(sizeof(t_philo));
	if (!buff[2])
		ft_error("Error malloc init failed\n");
	buff[0] = buff[2];
	buff[1] = buff[2];
	gettimeofday(&time, NULL);
	ft_set_philo(buff[2], i, time, shared);
	while (i <= size)
	{
		buff[2] = malloc(sizeof(t_philo));
		if (!buff[2])
			ft_error("Error malloc init failed\n");
		buff[1]->next = buff[2];
		buff[1] = buff[2];
		ft_set_philo(buff[1], ++i, time, shared);
	}
	balised(buff[2], buff[0]);
	return (buff[0]);
}
