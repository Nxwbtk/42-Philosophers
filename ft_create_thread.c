/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:26:57 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/09 02:03:28 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime();

void	*start(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)(philo);
	while (1)
	{
		lock_ban(tmp);
		pthread_mutex_unlock(tmp->table);
		printf("%ld ms philo %d eating\n", tmp->after, tmp->id);
		usleep(tmp->info.time_to_eat * 1000);
		tmp->last_eat = gettime();
		tmp->after = gettime() - tmp->before;
		unlock_ban(tmp);
		printf("%ld ms philo %d is thinking\n", tmp->after, tmp->id);
		usleep(tmp->info.time_to_sleep * 1000);
		tmp->after = gettime() - tmp->before;
		printf("%ld ms philo %d is sleeping\n", tmp->after, tmp->id);
		tmp->arrive_time += gettime() - tmp->last_eat;
		// printf("arrive %d\n", tmp->arrive_time);
		// if (ft_checkdie(tmp))
		// 	break ;
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

long	gettime()
{
	long		res;
	struct timeval	t_time;

	gettimeofday(&t_time, NULL);
	res = (t_time.tv_sec * 1000) + (t_time.tv_usec / 1000);
	return (res);
}

void	go_init(t_philo *philo)
{
	t_philo			*tmp;
	pthread_mutex_t	*table;

	tmp = philo;
	while (tmp)
	{
		pthread_mutex_init(&(tmp)->fork, NULL);
		tmp = tmp->next;
	}
	table = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!table)
		return ;
	tmp = philo;
	pthread_mutex_init(table, NULL);
	while (tmp)
	{
		tmp->table = table;
		tmp = tmp->next;
	}
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
	head = philo;
	go_init(philo);
	tmp = philo;
	while (k < 2)
	{
		tmp = head;
		while (i <= tmp->info.num_philo && tmp != NULL)
		{
			if (tmp->id == i)
			{
				tmp->last_eat = 0;
				tmp->arrive_time = 0;
				tmp->after = 0;
				tmp->before = gettime();
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
	tmp = philo;
	while (tmp)
	{
		pthread_join(tmp->philo_thread, NULL);
		tmp = tmp->next;
	}
}
