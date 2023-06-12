/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:26:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/12 16:47:33 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

void	ft_eat(t_aristoteles *aris)
{
	int		time;

	while (!(aris->has_fork) && !(aris->right->has_fork))
		ft_parlor_whit_dead(aris);
	time = 0;
	aris->right->has_fork = false;
	ft_log(aris->id, 1);
	aris->has_fork = false;
	ft_log(aris->id, 2);
	while (time < aris->spinoza.time_to_eat)
	{
		usleep(US_TO_MS);
		time++;
	}
	aris->t_last_meal = 0;
}
