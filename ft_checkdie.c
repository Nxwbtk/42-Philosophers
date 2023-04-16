/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:24:21 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/15 17:10:39 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checkdie(t_philo *philo)
{
	if (philo->after > philo->info.time_to_die)
	{
		printf("%ld ms philo %d die\n", philo->after, philo->id);
		return (1);
	}
	return (0);
}
