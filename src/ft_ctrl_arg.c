/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:15:36 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/19 15:00:00 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_ctrl_arg(char **argv, t_data data)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			if (data.nbr_philo > INT_MAX || data.time_to_die > INT_MAX
				|| data.time_to_eat > INT_MAX || data.time_to_sleep > INT_MAX)
				return (0);
			if (data.nbr_philo <= 0 || data.time_to_die <= 0
				|| data.time_to_eat <= 0 || data.time_to_sleep <= 0)
				return (0);
			j++;
		}
		i++;
	}
	//ft_philosopher(data);
	return (1);
}

