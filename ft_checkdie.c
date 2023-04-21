/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:24:21 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/21 08:52:43 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checkdie(t_philo *philo, int dsttime)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp)
	{
		if (tmp->after - tmp->last_eat > tmp->info.time_to_die && tmp->count_eat < tmp->info.num_must_eat)
		{
			pthread_mutex_lock(&(tmp)->time);
			printf("%ld ms philo %d is death\n", gettime() - tmp->before, tmp->id);
			tmp->alive->alive = 0;
			pthread_mutex_destroy(&(tmp)->time);
			return (1);
		}
	}
	return (0);
}
