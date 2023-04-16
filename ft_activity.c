/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:36:49 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/16 19:27:51 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	if (ft_checkdie(philo))
		return (1);
	philo->last_eat = gettime();
	philo->after = 0;
	lock_ban(philo);
	pthread_mutex_unlock(philo->table);
	printf("%ld ms philo %d is eating\n", gettime() - philo->before, philo->id);
	usleep(philo->info.time_to_eat * 1000);
	unlock_ban(philo);
	philo->after += gettime() - philo->last_eat;
	philo->last_eat = gettime();
	if (ft_checkdie(philo))
		return (1);
	return (0);
}

int	ft_bed(t_philo *philo)
{
	if (ft_checkdie(philo))
		return (1);
	printf("%ld ms philo %d is sleeping\n", gettime() - philo->before \
	, philo->id);
	usleep(philo->info.time_to_sleep * 1000);
	philo->after += gettime() - philo->last_eat;
	philo->last_eat = gettime();
	return (0);
}

int	ft_think(t_philo *philo)
{
	printf("%ld ms philo %d is thinking\n", gettime() - philo->before \
	, philo->id);
	if (ft_checkdie(philo))
		return (1);
	return (0);
}

void	die(t_philo *philo)
{
	printf("HELLO FROM DIE\n");
	pthread_mutex_lock(philo->time);
}