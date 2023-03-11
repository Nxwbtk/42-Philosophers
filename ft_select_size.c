/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:09:07 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/11 17:24:51 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_any(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_num(t_info *philo, int size)
{
	if (size == 4)
	{
		if (philo->num_philo <= 0 || philo->time_to_die <= 0 \
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0)
		{
			return (-1);
		}
	}
	if (size == 5)
	{
		if (philo->num_philo <= 0 || philo->time_to_die <= 0 \
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0 || \
		philo->num_must_eat <= 0)
		{
			return (-1);
		}
	}
	return (1);
}

int	get_number(t_info *philo, char **str2, int size)
{
	if (size == 4)
	{
		philo->num_philo = ft_atoi(str2[0]);
		philo->time_to_die = ft_atoi(str2[1]);
		philo->time_to_eat = ft_atoi(str2[2]);
		philo->time_to_sleep = ft_atoi(str2[3]);
		if (check_num(philo, 4) == -1)
			return (-1);
	}
	if (size == 5)
	{
		philo->num_philo = ft_atoi(str2[0]);
		philo->time_to_die = ft_atoi(str2[1]);
		philo->time_to_eat = ft_atoi(str2[2]);
		philo->time_to_sleep = ft_atoi(str2[3]);
		philo->num_must_eat = ft_atoi(str2[4]);
		if (check_num(philo, 5) == -1)
			return (-1);
	}
	return (1);
}

int	get_num(t_info *philo, char **av, int size)
{
	char	**str;
	char	**str2;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	str2 = (char **)malloc(sizeof(char *) * size);
	while (av[i])
	{
		j = 0;
		str = ft_split(av[i]);
		while (str[j])
			str2[k++] = ft_strdup(str[j++]);
		i++;
		free_av(str);
	}
	if (get_number(philo, str2, size) == -1)
	{
		free_any(str2, size);
		return (-1);
	}
	return (1);
}

int	select_size(int size, t_info *philo, char **av)
{
	if (size == 0 || (size != 4 && size != 5))
	{
		printf("Error: Invalid argument\n");
		return (-1);
	}
	if (size == 4)
	{
		if (get_num(philo, av, 4) == -1)
			return (-1);
	}
	if (size == 5)
	{
		if (get_num(philo, av, 5) == -1)
			return (-1);
	}

	return (1);
}
