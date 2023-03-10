/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:26:57 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/12 02:27:13 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *t)
{
	printf("Hello\n");
	return (NULL);
}

void	ft_create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info.num_philo)
	{
		pthread_create(&(philo)->philo_thread, NULL, test, NULL);
		i++;
	}
}
