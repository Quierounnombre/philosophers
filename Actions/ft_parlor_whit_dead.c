/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parlor_whit_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:35:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/22 10:53:32 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

/*
Gestiona la espera y cuenta si el filosofo debería morir
@param aristoteles estructura de uso general
*/
t_bool	ft_parlor_whit_dead(t_aristoteles *aristoteles)
{
	if (aristoteles->t_last_meal < aristoteles->spinoza.time_to_die)
	{
		usleep(US_TO_MS * T_PROGRES);
		aristoteles->t_last_meal += T_PROGRES;
		return (true);
	}
	ft_log(aristoteles->id, 5);
	return (false);
}
