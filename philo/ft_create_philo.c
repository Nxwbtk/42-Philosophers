/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:44:30 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/08 16:25:45 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*lst_last(t_philo *philo)
{
	while (philo && philo->next)
		philo = philo->next;
	return (philo);
}

void	ft_add_back(t_philo **philo, t_philo *new)
{
	t_philo	*last;

	if (philo && new)
	{
		if (!(*philo))
			*philo = new;
		else
		{
			last = lst_last(*philo);
			last->next = new;
		}
	}
}

void	ft_assign(t_philo *philo, t_info *info)
{
	t_philo	*tmp;
	int		i;

	i = 1;
	tmp = philo;
	while (tmp)
	{
		tmp->info.num_philo = info->num_philo;
		tmp->info.time_to_eat = info->time_to_eat;
		tmp->info.time_to_sleep = info->time_to_sleep;
		tmp->info.time_to_die = info->time_to_die;
		tmp->info.num_must_eat = info->num_must_eat;
		tmp = tmp->next;
	}
	tmp = philo;
	while (tmp)
	{
		tmp->id = i;
		i++;
		tmp = tmp->next;
	}
}

void	ft_create_philo(t_philo **philo, t_info *info)
{
	t_philo	*new;
	int		i;

	i = 0;
	while (i < info->num_philo)
	{
		new = p_init();
		ft_add_back(philo, new);
		i++;
	}
	ft_assign(*philo, info);
}
