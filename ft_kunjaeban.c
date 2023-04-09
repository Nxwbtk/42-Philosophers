/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kunjaeban.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:06:33 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/09 18:57:47 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_ban(t_philo *philo)
{
	pthread_mutex_lock(philo->table);
	pthread_mutex_lock(&(philo)->fork);
	printf("%ld ms philo %d taken left fork\n", gettime() - philo->before, philo->id);
	pthread_mutex_lock(philo->rfork);
	printf("%ld ms philo %d taken right fork\n", gettime() - philo->before, philo->id);
}

void	unlock_ban(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(&(philo)->fork);
}
