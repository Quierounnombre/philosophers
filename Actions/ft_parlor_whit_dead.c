/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parlor_whit_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:35:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 16:46:59 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

/*
Gestiona la espera y cuenta si el filosofo debería morir
@param aristoteles estructura de uso general
*/
t_bool	ft_parlor_whit_dead(t_aristoteles *aristoteles)
{
	if (aristoteles->t_last_meal < aristoteles->spinoza.time_to_die
		&& *(aristoteles->should_close))
	{
		ft_usleep(T_PROGRES);
		aristoteles->t_last_meal += T_PROGRES;
		return (true);
	}
	if (*(aristoteles->should_close))
	{
		ft_log_mutex(5, aristoteles->write,
			aristoteles->should_close, aristoteles);
		*(aristoteles->should_close) = false;
	}
	return (false);
}
