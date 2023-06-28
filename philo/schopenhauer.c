/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schopenhauer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:25:08 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/28 11:24:58 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

static void	ft_die(t_aristoteles *aris);

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
	if (aris->spinoza.n_philos == 1)
	{
		ft_usleep(aris->spinoza.time_to_die + 1);
		ft_die(aris);
		return (NULL);
	}
	while (*(aris->should_close))
	{
		if (!aris->spinoza.meals)
			break ;
		ft_usleep(T_PROGRES);
		aris->t_last_meal = kant() - aris->init_time;
		if (aris->spinoza.time_to_die <= aris->t_last_meal)
		{
			ft_die(aris);
			break ;
		}
	}
	return (NULL);
}

static void	ft_die(t_aristoteles *aris)
{
	ft_log_mutex(5, aris->write, aris->should_close, aris);
	*(aris->should_close) = false;
}
