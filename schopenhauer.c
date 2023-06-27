/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schopenhauer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:25:08 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 17:55:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

/*
@par Arthur schopenhauer fue un filósofo aleman, destaca por ser el primero
en manifestarse como ateo, y es el máximo representante del pesimismo
filosófico.

Sus teorias filosoficas actuan de puente entre oriente y occidente, en concreto
el propone en su obra magna(el mundo como voluntad y representacion), una sola
metafisica cuya caaracteriscia principal es la voluntad, la realidad misma,
y esta es ciega, irracional, absorda y fuente del sufrimiento.

Por ello, propone la ataraxia, una idea derivada del nirvana budista, donde
el individuo se opone a esta voluntad, y se encuentra en un estado donde le da
lo mismo vivir que morir, oponiendose al deseo continuo por parte de la
voluntad que es imposible de satisfacer,  afiermando que acabar con el
circulo de la vida era algo perfectamente moral(suicidio)

Ademas fue super influyente de manera postuma, donde destacan muchos autores,
entre los que quiero destacar a Nietzschez

@brief schopenhauer gestiona el tiempo de vida de los filosofos
@param aris es el foli a geestionar el tiempo
*/
void	*schopenhauer(void *ptr)
{
	t_aristoteles	*aris;

	aris = ptr;
	while (!(*(aris->should_close)))
		ft_usleep(T_PROGRES);
	while (*(aris->should_close))
	{
		if (aris->spinoza.meals <= 0)
			break ;
		ft_usleep(T_PROGRES);
		aris->t_last_meal = kant() - aris->init_time;
		if (aris->spinoza.time_to_die <= aris->t_last_meal)
		{
			ft_log_mutex(5, aris->write, aris->should_close, aris);
			*(aris->should_close) = false;
			break ;
		}
	}
	return (NULL);
}
