/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heraclito.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:15:49 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/11 19:17:11 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

static void		ft_think(t_aristoteles *aristoteles);
static void		ft_eat(t_aristoteles *aristoteles);
static void		ft_sleep(t_aristoteles *aristoteles);

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
	while (aristoteles->spinoza.meals)
	{
		if (aristoteles->id % 2 == 0)
		{
			while (!(aristoteles->has_fork))
			{}
			ft_eat(aristoteles);
			ft_sleep(aristoteles);
			ft_think(aristoteles);
		}
		else
		{
			while (!(aristoteles->has_fork))
				{}
			ft_eat(aristoteles);
			ft_sleep(aristoteles);
			ft_think(aristoteles);
		}
		if (aristoteles->spinoza.meals > 0)
			aristoteles->spinoza.meals = aristoteles->spinoza.meals - 1;
	}
	return (NULL);
}

//El philo devora el plato de comida
static void		ft_eat(t_aristoteles *aristoteles)
{
	aristoteles->right->has_fork = false;
	ft_log(aristoteles->id, 1);
	aristoteles->has_fork = false;
	ft_log(aristoteles->id, 2);
	usleep(aristoteles->spinoza.time_to_die * 1000);
}

//El philo espera pacientemente a la comida
static void		ft_think(t_aristoteles *aristoteles)
{
	ft_log(aristoteles->id, 4);
}

//El philo entra en modo reposo
static void		ft_sleep(t_aristoteles *aristoteles)
{
	aristoteles->has_fork = true;
	aristoteles->right->has_fork = true;
	ft_log(aristoteles->id, 3);
	usleep(aristoteles->spinoza.time_to_sleep * 1000);
}
