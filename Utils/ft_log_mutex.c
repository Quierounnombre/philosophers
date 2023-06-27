/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:48:01 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 11:32:58 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

/*
Gestiona el mutex del lock
*/

void	ft_log_mutex(int philo, int action, pthread_mutex_t *write,
						t_p_int *should_close)
{
	pthread_mutex_lock(write);
	usleep(100);
	if (*should_close)
	{
		ft_log(philo, action);
		pthread_mutex_unlock(write);
	}
}
