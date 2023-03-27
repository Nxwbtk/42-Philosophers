/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:26:57 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/27 23:45:14 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *t)
{
	int	i = 0;
	static	int	j;
	t_philo	*tmp;
	pthread_mutex_t	mutex;

	tmp = (t_philo *)(t);
	pthread_mutex_lock(&(tmp)->fork);
	if (!(tmp)->next)
	{
		// tmp = (t_philo *)(t);
		pthread_mutex_lock(&(tmp)->fork);
	}
	printf("ID = %d\n", tmp->id);
	pthread_mutex_unlock(&(tmp)->fork);
	pthread_mutex_unlock(&(tmp)->next->fork);
	return (NULL);
}

void	init_fork(t_philo *philo)
{
	t_philo	*tmp;
	t_philo	*head;

	tmp = philo;
	head = tmp;
	while (tmp && tmp->next)
	{
		tmp->rfork = &(tmp)->next->fork;
		tmp = tmp->next;
	}
	tmp->rfork = &(head)->fork;
}

void	ft_create_thread(t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	init_fork(philo);
	tmp = philo;
	while (tmp)
	{
		pthread_mutex_init(&(tmp)->fork, NULL);
		tmp = tmp->next;
	}
	tmp = philo;
	while (tmp)
	{
		pthread_create(&(tmp)->philo_thread, NULL, test, (void *)(tmp));
		usleep(30);
		tmp = tmp->next;
	}
}
