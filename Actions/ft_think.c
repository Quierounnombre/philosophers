/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:31:36 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/26 16:06:07 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

/*
Gestiona el proceso de pensamiento de los philos
@param aris estructura de uso general
*/
void	ft_think(t_aristoteles *aris)
{
	int		time;

	time = 0;
	if (*(aris->should_close))
		ft_log_mutex(aris->id, 4, aris->write);
	while (ft_parlor_whit_dead(aris)
		&& time < aris->spinoza.time_to_eat
		&& *(aris->should_close))
		time += T_PROGRES;
	if (time > aris->spinoza.time_to_die)
		*(aris->should_close) = false;
}
