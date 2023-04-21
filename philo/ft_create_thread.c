/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:26:57 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 03:11:54 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void);

void	*start(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)(philo);
	if (ft_one(tmp))
		return (0);
	while (1)
	{
		if (ft_eat(tmp))
			return (0);
		if (tmp->count_eat == tmp->info.num_must_eat && \
		tmp->info.num_must_eat != 0)
		{
			return (0);
		}
		if (ft_bed(tmp))
			return (0);
	}
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

long	gettime(void)
{
	long			res;
	struct timeval	t_time;

	gettimeofday(&t_time, NULL);
	res = (t_time.tv_sec * 1000) + (t_time.tv_usec / 1000);
	return (res);
}

int	go_init(t_philo *philo)
{
	t_philo			*tmp;
	pthread_mutex_t	*table;
	pthread_mutex_t	*time;
	t_alive			*salive;

	tmp = philo;
	table = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!table)
		return (1);
	pthread_mutex_init(table, NULL);
	time = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!time)
		return (1);
	salive = (t_alive *)malloc(sizeof(t_alive));
	if (!salive)
		return (1);
	pthread_mutex_init(time, NULL);
	salive->alive = 1;
	li(tmp, table, time, salive);
	return (0);
}

void	ft_create_thread(t_philo *philo)
{
	t_philo	*tmp;
	int		i;
	int		k;

	init_fork(philo);
	if (go_init(philo))
		return ;
	ft_init_time(philo);
	i = 1;
	k = 0;
	loop_create(philo, i, k);
	pthread_create(&(philo)->alive->p_alive, NULL, &ft_time, philo);
	tmp = philo;
	while (tmp)
	{
		pthread_join(tmp->philo_thread, NULL);
		tmp = tmp->next;
	}
	philo->alive->alive = 1;
	pthread_join(philo->alive->p_alive, NULL);
	tmp = philo;
	detach(tmp);
}
