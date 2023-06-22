/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:08:34 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/22 14:55:48 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *ft_setup_philo(long long nbr_philo, t_share share)
{
	
}

t_share	*ft_setup_share(t_data data)
{
	t_share	*n;

	n = malloc(sizeof(t_share));
	//protection
	n->dead = malloc(sizeof(pthread_mutex_t));
	//protection
	n->protect = malloc(sizeof(pthread_mutex_t));
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
