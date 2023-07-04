/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:36:23 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/04 14:53:58 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	philo_data;

	if (argc == 5 || argc == 6)
	{
		if (argc == 5)
			philo_data.need_eat = -1;
		if (!(ft_atoi2(argv[1], &philo_data.nb_philo)) || !(ft_atoi2(argv[2], \
			&philo_data.time_dead)) || !(ft_atoi2(argv[3], \
			&philo_data.time_eat)) || !(ft_atoi2(argv[4], \
			&philo_data.time_sleep)))
		{
			ft_error("Invalid argument\n");
		}
		if (argc == 6 && !(ft_atoi2(argv[5], &philo_data.need_eat)))
			ft_error("Invalid argument\n");
		if (!ft_ctrl_arg(argv, philo_data))
			ft_error("Invalide argument\n");
		else
			ft_philosopher(philo_data);
	}
	else
		ft_error("Invalid argument\n");
	return (0);
}
