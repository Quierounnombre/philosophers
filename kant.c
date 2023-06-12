/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kant.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:38:41 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/12 16:48:05 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

/*
@par
KANT Or can i?

Fue un filosofo prusiano, desarrollador del criticismo(no el del cuñao del bar
ese todo sabemos que fue manolo. . .), esta corriente filosofica se basa en la
busqueda de los limites del conocimiento mediante una investigación sistematica
de las condiciones de posibilidad del pensamiento, en este caso al surgir como
critica al racionalismo y al empirismo una de estas "condiciones de posibilidad"
son las personas, pues ambas corrientes previas no tenian en cuenta a el
individuo que estaba realizando la acción de conocer.

En este caso kant gestiona el tiempo, no por que su filosofia tenga que ver o no
con el tiempo, sino por su reputación de ser como un reloj, LITERALMENTE, ajustaban
los relojes de konisgberg a la hora a la que pasaba kant, y en más de una ocasión
resulto estar en lo cierto.

@brief Kant calcula el tiempo que a pasado desde que inicio el programa hasta ahora
@return El tiempo en msegs
*/
unsigned long	kant(void)
{
	struct timeval			tv;
	static unsigned long	old_time;

	if (!(gettimeofday(&tv, NULL)))
	{
		if (!old_time)
			old_time = tv.tv_usec;
		else
			return (tv.tv_usec - old_time);
	}
	return (0);
}
