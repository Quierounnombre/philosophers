/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parlor_whit_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:35:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/22 16:06:15 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

static unsigned long	ft_calc_time(struct timeval tv);
static void				ft_usleep(unsigned long wait_time);

/*
Gestiona la espera y cuenta si el filosofo debería morir
@param aristoteles estructura de uso general
*/
t_bool	ft_parlor_whit_dead(t_aristoteles *aristoteles)
{
	if (aristoteles->t_last_meal < aristoteles->spinoza.time_to_die)
	{
		ft_usleep(T_PROGRES);
		aristoteles->t_last_meal += T_PROGRES;
		return (true);
	}
	ft_log(aristoteles->id, 5);
	return (false);
}

static void	ft_usleep(unsigned long wait_time)
{
	struct timeval	tv_init;
	struct timeval	tv;
	unsigned long	time;

	time = 0;
	if (!gettimeofday(&tv, NULL) && !gettimeofday(&tv_init, NULL))
	{
		while (time < wait_time)
		{
			usleep(US_TO_MS);
			time = ft_calc_time(tv) - ft_calc_time(tv_init);
			if (gettimeofday(&tv, NULL))
				break ;
		}
	}
}

static unsigned long	ft_calc_time(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec * 0.001);
}
