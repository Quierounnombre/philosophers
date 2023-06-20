/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:26:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/20 16:53:24 by vicgarci         ###   ########.fr       */
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
	if (aris->id % 2)
		pthread_mutex_lock(&(aris->right->fork));
	else
		pthread_mutex_lock(&(aris->fork));
	ft_log(aris->id, 1);
	if (aris->id % 2)
		pthread_mutex_lock(&(aris->fork));
	else
		pthread_mutex_lock(&(aris->right->fork));
	ft_log(aris->id, 1);
	ft_log(aris->id, 2);
	while (time < aris->spinoza.time_to_eat && aris->should_close)
	{
		usleep(US_TO_MS);
		time++;
	}
	aris->t_last_meal = 0;
}
