/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:27:54 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/07 17:55:08 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *chnb)
{
	int	i;
	int	count;
	int	result;

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
	return (result * count);
}

int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
