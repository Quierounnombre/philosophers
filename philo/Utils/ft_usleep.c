/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:29:54 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 14:33:25 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

static unsigned long	ft_calc_time(struct timeval tv);

/*
@brief espera la cantidad de milisegundos estipulada
@param wait_time tiempo de espera
*/
void	ft_usleep(unsigned long wait_time)
{
	struct timeval	tv_init;
	struct timeval	tv;
	unsigned long	time;

	time = 0;
	if (!gettimeofday(&tv, NULL) && !gettimeofday(&tv_init, NULL))
	{
		while (time < wait_time)
		{
			usleep(100);
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
