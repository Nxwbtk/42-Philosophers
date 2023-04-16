/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:26:57 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/16 19:32:07 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void);

void	*start(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)(philo);
	while (1)
	{
		if (ft_eat(tmp))
		{
			// die(tmp);
			printf("DIEEE\n");
			pthread_mutex_lock(tmp->time);
			break ;
		}
		if (ft_bed(tmp))
		{
			// die(tmp);
			printf("DIEEE\n");
			pthread_mutex_lock(tmp->time);
			break ;
		}
		if (ft_think(tmp))
		{
			// die(tmp);
			printf("DIEEE\n");
			pthread_mutex_lock(tmp->time);
			break ;
		}
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

void	go_init(t_philo *philo)
{
	t_philo			*tmp;
	pthread_mutex_t	*table;
	pthread_mutex_t	*time;

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
	time = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(time, NULL);
	tmp = philo;
	while (tmp)
	{
		tmp->time = time;
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
	go_init(philo);
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
				tmp->last_eat = 0;
				tmp->arrive_time = 0;
				tmp->after = 0;
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
	tmp = philo;
	while (tmp)
	{
		pthread_join(tmp->philo_thread, NULL);
		tmp = tmp->next;
	}
}
