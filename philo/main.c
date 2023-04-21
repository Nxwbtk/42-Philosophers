/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:25:51 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/22 02:22:44 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*init(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->num_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->num_must_eat = 0;
	return (info);
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	check_argv(char **av)
{
	int		i;
	int		j;
	int		count;
	char	**str;

	i = 1;
	count = 0;
	while (av[i])
	{
		j = 0;
		str = ft_split(av[i]);
		while (str[j])
		{
			if (!ft_isdigit(str[j]))
			{
				free_av(str);
				return (0);
			}
			count++;
			j++;
		}
		free_av(str);
		i++;
	}
	return (count);
}

t_philo	*p_init(void)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->next = NULL;
	return (philo);
}

int	main(int ac, char *av[])
{
	t_info	*info;
	t_philo	*philo;
	int		size;

	philo = NULL;
	if (ac < 2)
		return (0);
	info = init();
	if (!info)
		return (0);
	size = check_argv(av);
	if (select_size(size, info, av) == -1)
	{
		free(info);
		return (0);
	}
	ft_create_philo(&philo, info);
	ft_create_thread(philo);
}
