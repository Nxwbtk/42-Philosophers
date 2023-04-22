/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:44:55 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 12:10:10 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_one(t_philo *philo)
{
	if (philo->info.num_philo == 1)
	{
		printf("0 ms philo %d taken left fork\n", philo->id);
		my_sleep(philo->info.time_to_die, philo);
		pthread_mutex_lock(philo->time);
		printf("%d ms philo %d is death\n", philo->info.time_to_die, philo->id);
		philo->alive->alive = 0;
		pthread_mutex_unlock(philo->time);
		return (1);
	}
	return (0);
}
