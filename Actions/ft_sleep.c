/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:29:53 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/20 17:38:53 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

/*
Gestiona el proceso de dormir de los philos
@param aris estructura de uso general del philosophers
*/
void	ft_sleep(t_aristoteles *aris)
{
	int	sleep_time;

	pthread_mutex_unlock(&(aris->fork));
	pthread_mutex_unlock(&(aris->right->fork));
	sleep_time = 0;
	ft_log(aris->id, 3);
	while (sleep_time < aris->spinoza.time_to_sleep && *(aris->should_close))
	{
		if (ft_parlor_whit_dead(aris))
			sleep_time++;
		else
			*(aris->should_close) = false;
	}
}
