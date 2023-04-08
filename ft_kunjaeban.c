/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kunjaeban.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:06:33 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/08 22:40:39 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_ban(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	pthread_mutex_lock(tmp->table);
	pthread_mutex_lock(&(tmp)->fork);
	printf("%ld ms philo %d taken left fork\n", tmp->after, tmp->id);
	pthread_mutex_lock(tmp->rfork);
	printf("%ld ms philo %d taken right fork\n", tmp->after, tmp->id);
}

void	unlock_ban(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	pthread_mutex_unlock(tmp->rfork);
	pthread_mutex_unlock(&(tmp)->fork);
}
