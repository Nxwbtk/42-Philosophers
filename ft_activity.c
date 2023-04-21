/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:36:49 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/20 23:05:48 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	if (lock_ban(philo))
		return (1);
	pthread_mutex_unlock(philo->table);
	printf("%ld ms philo %d is eating\n", gettime() - philo->before, philo->id);
	philo->after = 0;
	philo->last_eat = gettime();
	philo->count_eat++;
	usleep(philo->info.time_to_eat * 1000);
	if (philo->alive->alive == 0)
		return (1);
	unlock_ban(philo);
	philo->after += gettime() - philo->last_eat;
	philo->last_eat = gettime();
	return (0);
}

void	ft_bed(t_philo *philo)
{
	printf("%ld ms philo %d is sleeping\n", gettime() - philo->before \
	, philo->id);
	usleep(philo->info.time_to_sleep * 1000);
	philo->after += gettime() - philo->last_eat;
	philo->last_eat = gettime();
	printf("%ld ms philo %d is thinking\n", gettime() - philo->before \
	, philo->id);
}

void	die(t_philo *philo)
{
	printf("HELLO FROM DIE\n");
	pthread_mutex_lock(philo->time);
}