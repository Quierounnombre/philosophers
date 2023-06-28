/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:31:36 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 16:01:21 by vicgarci         ###   ########.fr       */
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
		ft_log_mutex(4, aris->write, aris->should_close, aris);
}
