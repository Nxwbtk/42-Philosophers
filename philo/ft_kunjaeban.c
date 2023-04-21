/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kunjaeban.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:06:33 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 01:52:05 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_ban(t_philo *philo)
{
	pthread_mutex_lock(philo->table);
	if (philo->alive->alive == 0)
		return (1);
	pthread_mutex_lock(&(philo)->fork);
	if (philo->alive->alive == 0)
		return (1);
	printf("%ld ms philo %d taken left fork\n", gettime() - philo->before, philo->id);
	pthread_mutex_lock(philo->rfork);
	if (philo->alive->alive == 0)
		return (1);
	printf("%ld ms philo %d taken right fork\n", gettime() - philo->before, philo->id);
	return (0);
}

void	unlock_ban(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(&(philo)->fork);
}
