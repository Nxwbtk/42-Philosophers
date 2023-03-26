/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 04:37:27 by bsirikam          #+#    #+#             */
/*   Updated: 2023/03/26 16:23:54 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_info
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
}				t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		philo_thread;
	t_info			info;
	pthread_mutex_t	fork;
	struct s_philo	*next;
}				t_philo;

int		ft_isspace(char c);
int		ft_isdigit(char *s);
int		ft_atoi(const char *chnb);
int		select_size(int size, t_info *philo, char **av);
char	**ft_split(char *s);
char	*ft_strdup(char *s);
void	free_av(char **av);
void	ft_create_philo(t_philo **philo, t_info *info);
void	ft_create_thread(t_philo *philo);
void	ft_free_lst(t_philo *philo);
t_philo	*p_init(void);

#endif
