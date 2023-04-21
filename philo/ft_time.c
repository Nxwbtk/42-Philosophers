/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:58:34 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 00:20:25 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_time(void *alive)
{
	t_philo	*philo;

	philo = (t_philo *)alive;
	while (1)
	{
		ft_checkdie(philo);
		if (philo->alive->alive == 0)
			break ;
	}
	return (NULL);
}