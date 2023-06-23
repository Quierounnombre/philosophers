/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:26:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/23 15:40:26 by vicgarci         ###   ########.fr       */
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
	int		time;

	time = 0;
	if (aris->id % 2 && *(aris->should_close))
		pthread_mutex_lock(&(aris->right->fork));
	else if (*(aris->should_close))
		pthread_mutex_lock(&(aris->fork));
	ft_log(aris->id, 1);
	if (aris->id % 2 && *(aris->should_close))
		pthread_mutex_lock(&(aris->fork));
	else if (*(aris->should_close))
		pthread_mutex_lock(&(aris->right->fork));
	ft_log(aris->id, 1);
	ft_log(aris->id, 2);
	while (time < aris->spinoza.time_to_eat && *(aris->should_close))
	{
		if (ft_parlor_whit_dead(aris))
			time += T_PROGRES;
		else
			*(aris->should_close) = false;
	}
	aris->t_last_meal = 0;
}
