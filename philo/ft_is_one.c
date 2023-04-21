/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:44:55 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/17 22:49:35 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_one(t_philo *philo)
{
	if (philo->info.num_philo == 1)
	{
		printf("0 ms philo %d taken left fork\n", philo->id);
		usleep(philo->info.time_to_die * 1000);
		printf("%d ms philo %d is death\n", philo->info.time_to_die, philo->id);
		return (1);
	}
	return (0);
}