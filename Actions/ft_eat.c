/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:26:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/26 11:28:22 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

static void	take_a_fork(t_aristoteles *aris);

/*
Los philosofos tienen que comer, gastan mucha energía al pensar tanto
@param aris lo mismo que aristoteles, pero me daba pereza, estructura de uso
general
*/
void	ft_eat(t_aristoteles *aris)
{
	int		time;

	time = 0;
	take_a_fork(aris);
	if (*(aris->should_close))
		ft_log(aris->id, 2);
	while (time < aris->spinoza.time_to_eat && *(aris->should_close))
	{
		if (ft_parlor_whit_dead(aris))
			time += T_PROGRES;
		else
		{
			*(aris->should_close) = false;
			return ;
		}
	}
	if (*(aris->should_close))
		aris->t_last_meal = 0;
}

//take forks
static void	take_a_fork(t_aristoteles *aris)
{
	if (aris->id % 2 && *(aris->should_close))
		pthread_mutex_lock(&(aris->fork));
	else if (*(aris->should_close))
		pthread_mutex_lock(&(aris->right->fork));
	else
	{
		pthread_mutex_unlock(&(aris->fork));
		return ;
	}
	ft_log(aris->id, 1);
	if (aris->id % 2 && *(aris->should_close))
		pthread_mutex_lock(&(aris->right->fork));
	else if (*(aris->should_close))
		pthread_mutex_lock(&(aris->fork));
	else
	{
		pthread_mutex_unlock(&(aris->fork));
		return ;
	}
	ft_log(aris->id, 1);
}
