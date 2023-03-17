/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:19:46 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/17 11:06:12 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_share	*ft_setup_share(t_data data)
{
	t_share	*n;

	n = malloc(sizeof(t_share));
	//protection
	n->dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	//protection
	n->protect = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	//protection
	n->is_dead = malloc(sizeof(int));
	//protection
	n->data = data;
	n->is_dead = 0;
	if (pthread_mutex_init(n->dead, NULL) != 0)
		//protection
	if (pthread_mutex_init(n->protect, NULL) != 0)
		//protection
	return (n);
}

t_philo *ft_list_philo(int n, t_share *share)
{
	t_philo			*philo;
	struct timeval	time;
	int				i;

	i = 0;
	philo = malloc(sizeof(t_philo));
	//protection
	gettimeofday(&time, NULL);
	ft_setup_philo();
}