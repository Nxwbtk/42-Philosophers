/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:26:57 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/29 18:26:16 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)(philo);
	if (pthread_mutex_lock(&(tmp)->fork) != 0)
		return (NULL);
	printf("philo %d locked left fork\n", tmp->id);
	if (pthread_mutex_lock(tmp->rfork) != 0)
		return (NULL);
	printf("philo %d locked right fork\n", tmp->id);
	printf("philo %d eating\n", tmp->id);
	usleep(tmp->info.time_to_eat);
	if (pthread_mutex_unlock(&(tmp)->fork) != 0)
		return (NULL);
	printf("philo %d left fork unlocked\n", tmp->id);
	if (pthread_mutex_unlock(tmp->rfork) != 0)
		return (NULL);
	printf("philo %d right fork unlocked\n", tmp->id);
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
	while (1)
	{
		gettimeofday(&(tmp)->t_time, NULL);
		printf("%ld\n", tmp->t_time.tv_sec);
		pthread_create(&(tmp)->philo_thread, NULL, start, (void *)(tmp));
		usleep(30);
		// printf("philo %d done\n", tmp->id);
		// pthread_join((tmp)->philo_thread, NULL);
		if ((tmp)->next == NULL)
		{
			tmp = philo;
			continue ;
		}
		tmp = tmp->next;
	}
}
