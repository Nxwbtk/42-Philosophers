/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:24:21 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 03:00:12 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checkdie(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp)
	{
		if ((gettime() - tmp->before) - tmp->last_eat > tmp->info.time_to_die \
		&& (tmp->count_eat < tmp->info.num_must_eat || \
		tmp->info.num_must_eat == 0))
		{
			pthread_mutex_lock(tmp->time);
			printf("%ld ms philo %d is death\n", gettime() - tmp->before, \
			tmp->id);
			tmp->alive->alive = 0;
			pthread_mutex_unlock(tmp->time);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
