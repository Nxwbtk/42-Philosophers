/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:36:49 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/10 22:23:51 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	lock_ban(philo);
	pthread_mutex_unlock(philo->table);
	printf("%ld ms philo %d is eating\n", gettime() - philo->before, philo->id);
	usleep(philo->info.time_to_eat * 1000);
	unlock_ban(philo);
}

void	ft_bed(t_philo *philo)
{
	printf("%ld ms philo %d is sleeping\n", gettime() - philo->before \
	, philo->id);
	usleep(philo->info.time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	printf("%ld ms philo %d is thinking\n", gettime() - philo->before \
	, philo->id);
}