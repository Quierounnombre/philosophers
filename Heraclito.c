/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heraclito.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:15:49 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 13:08:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

static void	flow(t_aristoteles *aristoteles);
static void	wait_to_die(t_aristoteles *aris);

/*
@par
Heraclito, tambien llamado el oscuro(en sentido animico) por una serie de 
errores de traducción, fue un presocratico nativo de efeso y gran parte
de su obra esta escrita mediante aforismos.

Su filosofia defiende el cambio constante, el ser esta en un estado constante
de creación y destrucción, a un movimiento constante entre todas las cosas.

@brief Función para los hilos, recibe un puntero que castea a aristoteles y lo
utiliza para seguir el proceso del philosophers
@param ptr puntero generico, se castea a aristoteles
@param en principio devuelve NULL, solo necesario para que pthread lo acepte
*/
void	*heraclito(void *ptr)
{
	t_aristoteles	*aristoteles;

	aristoteles = ptr;
	while (!(*(aristoteles->should_close)))
		usleep(US_TO_MS);
	if (aristoteles->spinoza.n_philos == 1)
		wait_to_die(aristoteles);
	else
	{
		while (aristoteles->spinoza.meals && *(aristoteles->should_close))
			flow(aristoteles);
	}
	usleep(US_TO_MS);
	pthread_mutex_destroy(&(aristoteles->fork));
	pthread_join(aristoteles->thread, NULL);
	free(aristoteles);
	return (NULL);
}

static void	flow(t_aristoteles *aristoteles)
{
	if (*(aristoteles->should_close))
		ft_eat(aristoteles);
	if (*(aristoteles->should_close))
		ft_sleep(aristoteles);
	if (*(aristoteles->should_close))
		ft_think(aristoteles);
	if (aristoteles->spinoza.meals > 0 && *(aristoteles->should_close))
		aristoteles->spinoza.meals = aristoteles->spinoza.meals - 1;
}

static void	wait_to_die(t_aristoteles *aris)
{
	ft_log_mutex(0, 1, aris->write, aris->should_close);
	while (ft_parlor_whit_dead(aris))
	{
	}
	*(aris->should_close) = false;
}
