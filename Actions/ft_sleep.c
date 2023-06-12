/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:29:53 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/12 16:40:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

/*
Gestiona el proceso de dormir de los philos
@param aris estructura de uso general del philosophers
*/
void	ft_sleep(t_aristoteles *aris)
{
	int	sleep_time;

	sleep_time = 0;
	aris->has_fork = true;
	aris->right->has_fork = true;
	ft_log(aris->id, 3);
	while (sleep_time < aris->spinoza.time_to_sleep)
	{
		if (ft_parlor_whit_dead(aris))
			sleep_time++;
	}
}