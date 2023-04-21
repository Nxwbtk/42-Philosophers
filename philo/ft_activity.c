/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:36:49 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 05:12:13 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	if (lock_ban(philo))
		return (1);
	pthread_mutex_unlock(philo->table);
	printf("%ld ms philo %d is eating\n", gettime() - philo->before, philo->id);
	philo->last_eat = gettime() - philo->before;
	philo->count_eat++;
	my_sleep(philo->info.time_to_eat);
	unlock_ban(philo);
	if (philo->alive->alive == 0)
		return (1);
	return (0);
}

int	ft_bed(t_philo *philo)
{
	if (philo->alive->alive == 0)
		return (1);
	printf("%ld ms philo %d is sleeping\n", gettime() - philo->before \
	, philo->id);
	my_sleep(philo->info.time_to_sleep);
	if (philo->alive->alive == 0)
		return (1);
	printf("%ld ms philo %d is thinking\n", gettime() - philo->before \
	, philo->id);
	return (0);
}
