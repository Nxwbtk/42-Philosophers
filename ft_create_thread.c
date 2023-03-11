#include "philo.h"

void	*test(void *t)
{
	printf("Hello\n");
	return (NULL);
}

void	ft_create_thread(t_philo *philo)
{
	int	i;

	i = 0;

	printf("Hello %d\n", philo->info.num_philo);
	while (i < philo->info.num_philo)
	{
		pthread_create(&(philo)->philo_thread, NULL, test, NULL);
		i++;
	}
}
