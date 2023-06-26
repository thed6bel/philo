/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:36:23 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/23 09:39:30 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	philo_data;

	if (argc == 5 || argc == 6)
	{
		if (argc == 5)
			philo_data.nbr_time_must_eat = -1;
		if (!(ft_atoi2(argv[1], &philo_data.nbr_philo)) || !(ft_atoi2(argv[2], \
			&philo_data.time_to_die)) || !(ft_atoi2(argv[3], \
			&philo_data.time_to_eat)) || !(ft_atoi2(argv[4], \
			&philo_data.time_to_sleep)))
		{
			ft_error("Invalid argument1\n");
		}
		if (argc == 6 && !(ft_atoi2(argv[5], &philo_data.nbr_time_must_eat)))
			ft_error("Invalid argument2\n");
		if (!ft_ctrl_arg(argv, philo_data))
			ft_error("Invalide argument3\n");
		else
			ft_philosopher(philo_data);
	}
	else
		ft_error("Invalid argument4\n");
	return (0);
}
