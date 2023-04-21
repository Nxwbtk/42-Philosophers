/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:13:29 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 01:41:58 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_lst(t_philo *philo)
{
	t_philo	*tmp;

	while (philo)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
	free(philo);
}

void	detach(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (philo)
	{
		pthread_detach(philo->philo_thread);
		philo = philo->next;
	}
	pthread_detach(tmp->alive->p_alive);
	pthread_mutex_destroy(tmp->time);
	philo = tmp;
	while (philo)
	{
		pthread_mutex_destroy(&(philo)->fork);
		philo = philo->next;
	}
}