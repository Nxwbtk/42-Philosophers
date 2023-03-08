/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:25:51 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/08 23:40:39 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init(void)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->num_philo = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->num_must_eat = 0;
	return (philo);
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

int	main(int ac, char *av[])
{
	t_philo	*philo;
	int		size;

	if (ac < 2)
		return (0);
	philo = init();
	if (!philo)
		return (0);
	size = check_argv(av);
	select_size(size, philo, av);
	free(philo);
}
