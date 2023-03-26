/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:26:57 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/26 18:23:15 by bsirikam         ###   ########.fr       */
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
	if (tmp->next)
		pthread_mutex_lock(&(tmp)->next->fork);
	printf("ID = %d\n", tmp->id);
	// while (i < 5)
	// {
	// 	printf("j = %d i = %d\n", j, i);
	// 	i++;
	// }
	// j++;
	pthread_mutex_unlock(&(tmp)->fork);
	if (tmp->next)
		pthread_mutex_unlock(&(tmp)->next->fork);
	return (NULL);
}

void	ft_create_thread(t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	i = 0;
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
