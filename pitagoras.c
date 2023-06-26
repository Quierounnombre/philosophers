/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pitagoras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:36:54 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/26 11:42:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

static void	make_thread(pthread_t *new_thread, t_aristoteles *ptr);

/*
@par
Pitagoras, fue un filosofo griego, pero es conocido sobretodo a nivel popular
por sus aportaciones al campo de las matematicas.

Su cosmovisión bebe de muchas fuentes, pero viene a ser una suerte de germen
cientifico, con influencias matematicas y religiosas, fue particularmente
la escuela que monto en base a esta visión general.

@brief Esta función crea y gestiona todos los hilos
@param aristoteles, estructura con todos los philos
*/
void	pitagoras(t_aristoteles *aristoteles)
{
	t_aristoteles	*ptr;
	int				start_id;

	ptr = aristoteles;
	start_id = aristoteles->id;
	make_thread(&(ptr->thread), ptr);
	if (ptr->right && ptr->right != ptr)
	{
		ptr = ptr->right;
		while (start_id != ptr->id)
		{
			make_thread(&(ptr->thread), ptr);
			ptr = ptr->right;
		}
	}
}

//Make a thread and store it in aristoteles
static void	make_thread(pthread_t *new_thread, t_aristoteles *ptr)
{
	pthread_create(new_thread, NULL, heraclito, ptr);
	pthread_detach(ptr->thread);
}
