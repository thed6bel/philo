/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:31:43 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/02 18:33:32 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	get_timestamp(struct timeval start)
{
	int				timestamp;
	struct timeval	end;

	gettimeofday(&end, NULL);
	timestamp = ((end.tv_sec - start.tv_sec)
			+ 1e-6 * (end.tv_usec - start.tv_usec)) * 1000;
	return (timestamp);
}

int	ft_atoi2(const char *nptr, int *n)
{
	int						i;
	int						signe;
	int						nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
		if (nptr[i] == '-' || nptr[i] == '+')
			return (0);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nbr = nptr[i++] - '0' + (nbr * 10);
	if ((((unsigned long long)nbr > 9223372036854775808ULL) && signe == -1) || \
		(((unsigned long long)nbr > 9223372036854775807) && signe == 1))
		return (0);
	*n = ((int)nbr * signe);
	return (1);
}

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
			if (data.nb_philo > INT_MAX || data.time_dead > 2147483647
				|| data.time_eat > INT_MAX || data.time_sleep > INT_MAX \
				|| data.need_eat > INT_MAX)
				return (0);
			if (data.nb_philo <= 0 || data.time_dead <= -1
				|| data.time_eat <= -1 || data.time_sleep <= -1 || \
				(!data.need_eat && data.need_eat <= 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
