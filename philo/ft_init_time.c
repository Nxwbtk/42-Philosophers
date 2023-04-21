/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:08:08 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 04:01:43 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_time(t_philo *philo)
{
	t_keeptime	*time;
	t_philo		*tmp;

	time = (t_keeptime *)malloc(sizeof(t_keeptime *));
	if (!time)
		return ;
	time->start_time = gettime();
	tmp = philo;
	while (tmp)
	{
		tmp->before = time->start_time;
		tmp = tmp->next;
	}
	free(time);
}
