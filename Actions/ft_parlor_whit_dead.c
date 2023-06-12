/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parlor_whit_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:35:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/12 16:36:16 by vicgarci         ###   ########.fr       */
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
		usleep(US_TO_MS);
		aristoteles->t_last_meal++;
		return (true);
	}
	return (false);
}
