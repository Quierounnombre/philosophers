/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Affinius.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:56:51 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/01 15:43:01 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

/*
@par Conexto: Affinius fue el maestro de espinoza, y le inspiro a crear su racionalismo, este
creo una vertiente del racionalismo donde todo son conatos/modos de dios, es
decir todo forma parte de un todo, del cual solo representan una cara.

@brief Esta función recive un puntero a spinoza y crea un conato de este el cual
inicializa
@param spinoza la estructura a iniciar
@return true en caso de que todo vaya bien, false en caso de error
*/
t_bool	affinius(t_spinoza **spinoza)
{
	t_spinoza	*conato_spinoza;

	conato_spinoza = NULL;
	conato_spinoza = (t_spinoza *)malloc(sizeof(t_spinoza));
	if (conato_spinoza)
	{
		return (true);
	}
	return (false);
}
