/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:24:21 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/09 01:43:28 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checkdie(t_philo *philo)
{
	if (philo->info.num_must_eat > 0)
	{
		if (philo->after >= philo->info.num_must_eat)
			return (1);
	}
	if (philo->arrive_time >= philo->info.time_to_die)
		return (1);
	else if (philo->arrive_time < philo->info.time_to_die)
	{
		philo->arrive_time = 0;
		return (0);
	}
	return (0);
}
