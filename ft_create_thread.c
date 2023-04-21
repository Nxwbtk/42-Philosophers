/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:26:57 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/21 00:22:26 by bsirikam         ###   ########.fr       */
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
		if (tmp->count_eat == tmp->info.num_must_eat)
			return (0);
		ft_bed(tmp);
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
	while (tmp)
	{
		pthread_mutex_init(&(tmp)->fork, NULL);
		tmp->table = table;
		tmp->count_eat = 0;
		tmp->time = time;
		tmp->last_eat = 0;
		tmp->arrive_time = 0;
		tmp->after = 0;
		tmp->alive = salive;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_create_thread(t_philo *philo)
{
	int		i;
	int		k;
	t_philo	*tmp;
	t_philo	*head;

	i = 1;
	k = 0;
	init_fork(philo);
	if (go_init(philo))
		return ;
	ft_init_time(philo);
	head = philo;
	tmp = philo;
	while (k < 2)
	{
		tmp = head;
		while (i <= tmp->info.num_philo && tmp != NULL)
		{
			if (tmp->id == i)
			{
				tmp->last_eat = tmp->before;
				pthread_create(&(tmp)->philo_thread, NULL, start, (void *)(tmp));
				usleep(5);
				i += 2;
			}
			if (tmp->next)
				tmp = tmp->next;
		}
		i = 2;
		k++;
	}
	pthread_create(&(philo)->alive->p_alive, NULL, &ft_time, philo);
	tmp = philo;
	while (tmp)
	{
		pthread_join(tmp->philo_thread, NULL);
		tmp = tmp->next;
	}
}
