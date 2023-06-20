/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:26:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/20 14:18:56 by vicgarci         ###   ########.fr       */
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

	time = 0;
	pthread_mutex_lock(&(aris->right->fork));
	ft_log(aris->id, 1);
	pthread_mutex_lock(&(aris->fork));
	ft_log(aris->id, 1);
	ft_log(aris->id, 2);
	while (time + T_PROGRES < aris->spinoza.time_to_eat)
	{
		usleep(US_TO_MS * T_PROGRES);
		time += T_PROGRES;
	}
	usleep(US_TO_MS * (aris->spinoza.time_to_eat - time));
	aris->t_last_meal = 0;
}
