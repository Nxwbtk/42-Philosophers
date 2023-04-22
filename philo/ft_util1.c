/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:25:39 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 11:15:42 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mal(t_philo *tmp)
{
	tmp->count_eat = 0;
	tmp->last_eat = 0;
	tmp->arrive_time = 0;
	tmp->after = 0;
}

void	mal(t_philo *tmp, pthread_mutex_t *tab, pthread_mutex_t *t, t_alive *s)
{
	tmp->table = tab;
	tmp->time = t;
	tmp->alive = s;
}

void	li(t_philo *tmp, pthread_mutex_t *tab, pthread_mutex_t *t, t_alive *s)
{
	while (tmp)
	{
		pthread_mutex_init(&(tmp)->fork, NULL);
		mal(tmp, tab, t, s);
		ft_mal(tmp);
		tmp = tmp->next;
	}
}

void	loop_create(t_philo *philo, int i, int k)
{
	t_philo	*tmp;
	t_philo	*head;

	head = philo;
	tmp = philo;
	while (k < 2)
	{
		tmp = head;
		while (i <= tmp->info.num_philo && tmp != NULL)
		{
			if (tmp->id == i)
			{
				pthread_create(&(tmp)->philo_thread, NULL, start, \
				(void *)(tmp));
				my_sleep(5);
				i += 2;
			}
			if (tmp->next)
				tmp = tmp->next;
		}
		i = 2;
		k++;
	}
}

void	my_sleep(int time)
{
	long	now;

	now = gettime();
	while (gettime() - now < (long)time)
	{
		usleep(1);
	}
}
