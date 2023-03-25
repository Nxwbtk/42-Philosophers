/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:22:48 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/09 14:31:29 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' \
	|| c == '\r')
		return (1);
	return (0);
}

char	**ft_split(char *s)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * 5000);
	if (!res)
		return (NULL);
	while (s[i] && ft_isspace(s[i]))
		i++;
	while (s[i])
	{
		k = 0;
		res[j] = (char *)malloc(sizeof(char) * 5000);
		while (s[i] && !ft_isspace(s[i]))
			res[j][k++] = s[i++];
		res[j][k] = '\0';
		j++;
		while (s[i] && ft_isspace(s[i]))
			i++;
	}
	res[j] = NULL;
	return (res);
}
