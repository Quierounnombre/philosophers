/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:26:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/18 01:22:31 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

/*
Los philosofos tienen que comer, gastan mucha energía al pensar tanto
@param aris lo mismo que aristoteles, pero me daba pereza, estructura de uso
general
*/
void	ft_eat(t_aristoteles *aris)
{
	int	time;

	while (!(aris->has_fork) && !(aris->right->has_fork))
		ft_parlor_whit_dead(aris);
	time = 0;
	aris->right->has_fork = false;
	ft_log(aris->id, 1);
	aris->has_fork = false;
	ft_log(aris->id, 2);
	while (time + T_PROGRES < aris->spinoza.time_to_eat)
	{
		usleep(US_TO_MS * T_PROGRES);
		time += T_PROGRES;
	}
	usleep(US_TO_MS * (aris->spinoza.time_to_eat - time));
	aris->t_last_meal = 0;
}
