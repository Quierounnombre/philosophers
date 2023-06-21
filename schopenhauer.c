/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schopenhauer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:25:08 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/21 15:05:19 by vicgarci         ###   ########.fr       */
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

@brief schopenhauer Es el que limpia la estructura atistoteles
@param aris la estructura a limpiar, importante recordar que es una lista
circular
*/
void	schopenhauer(t_aristoteles *aris)
{
	t_aristoteles	*tmp;
	t_aristoteles	*last;
	t_aristoteles	*head;

	if (aris->right != aris)
	{
		last = aris;
		while (last->right != aris)
			last = last->right;
		tmp = aris;
		while (tmp != last->right)
		{
			head = tmp;
			tmp = tmp->right;
			pthread_mutex_destroy(&(head->fork));
			free(head);
		}
	}
	else
	{
		pthread_mutex_destroy(&(aris->fork));
		free(aris);
	}
}
