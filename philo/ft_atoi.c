/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:27:54 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 02:56:29 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_gern(long *result)
{
	if (*result > 2147483647 || *result < -2147483648)
	{
		printf("Error\n");
		*result = 0;
	}
}

int	ft_atoi(const char *chnb)
{
	int		i;
	long	count;
	long	result;

	i = 0;
	result = 0;
	count = 1;
	while (ft_isspace(chnb[i]))
		i++;
	if (chnb[i] == '-' || chnb[i] == '+')
	{
		if (chnb[i] == '-')
			count = count * -1;
		i++;
	}
	while (chnb[i] >= '0' && chnb[i] <= '9')
	{
		result = result * 10 + (chnb[i] - '0');
		i++;
	}
	check_gern(&result);
	return (result * count);
}

int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
