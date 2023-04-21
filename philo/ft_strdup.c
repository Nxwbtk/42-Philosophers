/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:11:47 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/08 23:14:40 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*sc;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	sc = malloc(sizeof(char) * s_len + 1);
	if (!sc)
		return (NULL);
	while (s[i])
	{
		sc[i] = s[i];
		i++;
	}
	sc[i] = '\0';
	return (sc);
}
