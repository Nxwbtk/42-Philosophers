/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:36:49 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/09 18:07:24 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	lock_ban(philo);
	pthread_mutex_unlock(philo->table);
	pthread_mutex_lock(philo->time);
	philo->after = gettime() - philo->before;
	printf("%ld ms philo %d is eating\n", philo->after, philo->id);
	pthread_mutex_unlock(philo->time);
	unlock_ban(philo);
}
