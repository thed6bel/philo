/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:31:43 by hucorrei          #+#    #+#             */
/*   Updated: 2023/06/21 14:46:43 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_error(char *message)
{
	write (2, message, ft_strlen(message));
	exit (1);
}

long	ft_strlen(const char *str)
{
	long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi2(const char *nptr, long long int *n)
{
	int						i;
	int						signe;
	unsigned long long int	nbr;

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
	if (((nbr > 9223372036854775808ULL) && signe == -1) || \
		((nbr > 9223372036854775807) && signe == 1))
		return (0);
	*n = (long long int)(nbr * signe);
	return (1);
}
