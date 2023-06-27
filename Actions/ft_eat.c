/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:26:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 17:50:21 by vicgarci         ###   ########.fr       */
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
	int				time;

	time = 0;
	if (aris->id % 2)
		usleep(100);
	take_a_fork(aris);
	aris->init_time = kant();
	if (*(aris->should_close))
		ft_log_mutex(2, aris->write, aris->should_close, aris);
	while (time <= aris->spinoza.time_to_eat && *(aris->should_close))
	{
		time += T_PROGRES;
		ft_usleep(T_PROGRES);
	}
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
	if (*(aris->should_close))
		ft_log_mutex(1, aris->write, aris->should_close, aris);
	if (aris->id % 2 && *(aris->should_close))
		pthread_mutex_lock(&(aris->right->fork));
	else if (*(aris->should_close))
		pthread_mutex_lock(&(aris->fork));
	else
	{
		pthread_mutex_unlock(&(aris->fork));
		return ;
	}
	if (*(aris->should_close))
		ft_log_mutex(1, aris->write, aris->should_close, aris);
}
