/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:36:23 by hucorrei          #+#    #+#             */
/*   Updated: 2023/04/17 14:43:45 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	philo_data;

	if (argc == 5)
		philo_data.nbr_time_must_eat = -1;
	else if (argc == 6)
		philo_data.nbr_time_must_eat = ft_atoi(argv[5]);
	if (argc == 5 || argc == 6)
	{
		philo_data.nbr_philo = ft_atoi(argv[1]);
		philo_data.time_to_die = ft_atoi(argv[2]);
		philo_data.time_to_eat = ft_atoi(argv[3]);
		philo_data.time_to_sleep = ft_atoi(argv[4]);
		if (!ft_ctrl_arg(argv, philo_data))
			ft_error("Invalide argument\n");
		//ft_philosopher(philo_data);
	}
	else
		ft_error("Invalid argument\n");
	return (0);
}
