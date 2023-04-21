/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 04:37:27 by bsirikam          #+#    #+#             */
/*   Updated: 2023/04/21 00:00:15 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
}				t_info;

typedef struct s_alive
{
	int			alive;
	pthread_t	p_alive;
}				t_alive;

typedef struct s_time
{
	long	start_time;
}				t_keeptime;

typedef struct s_philo
{
	int				id;
	int				arrive_time;
	int				count_eat;
	long			before;
	long			after;
	long			last_eat;
	pthread_t		philo_thread;
	t_info			info;
	t_keeptime		*keeptime;
	pthread_mutex_t	fork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*table;
	pthread_mutex_t	*time;
	struct s_philo	*next;
	struct timeval	t_time;
	struct s_alive	*alive;
}				t_philo;

int		ft_isspace(char c);
int		ft_isdigit(char *s);
int		ft_atoi(const char *chnb);
int		ft_eat(t_philo *philo);
int		select_size(int size, t_info *philo, char **av);
int		ft_checkdie(t_philo *philo, int dsttime);
int		ft_one(t_philo *philo);
int		lock_ban(t_philo *philo);
long	gettime(void);
char	**ft_split(char *s);
char	*ft_strdup(char *s);
void	*ft_time(void *alive);
void	ft_bed(t_philo *philo);
void	free_av(char **av);
void	ft_sleep(int time_eat);
void	ft_create_philo(t_philo **philo, t_info *info);
void	ft_create_thread(t_philo *philo);
void	ft_free_lst(t_philo *philo);
void	unlock_ban(t_philo *philo);
void	ft_init_time(t_philo *philo);
void	die(t_philo *philo);
t_philo	*p_init(void);

#endif
