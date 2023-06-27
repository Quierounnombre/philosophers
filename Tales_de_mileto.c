/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tales_de_mileto.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:37:47 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 13:08:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

static t_bool	check_meals(t_aristoteles *aris);

/*
@par Tales de mileto esta considerado el primer filosofo documentado en la
historia humana, nativo de Mileto, una polis griega ubicada en la anatolia, se 
le atribuyen multiples aportaciones, pero lo más importante es aplicar el 
uso de la razón para encontrar una respuesta a las grandes preguntas.

Aun así el hecho de que no se perserve ningún documento directo suyo, hace que
sea dificil atribuirle correctamente todos sus hallazgos
@brief Basicamente es una abstracción del main, pero con otro nombre ^^
*/
static void	tales_de_mileto(int argc, char **argv)
{
	t_spinoza		*spinoza;
	pthread_mutex_t	write;
	t_aristoteles	*aris;

	spinoza = NULL;
	aris = NULL;
	if (affinius(&spinoza))
	{
		if (!pthread_mutex_init(&write, NULL))
		{
			if (diogenes(argc, argv, spinoza))
			{
				if (plato(spinoza, &aris, &write))
				{
					pitagoras(aris);
					while (*(aris->should_close) && check_meals(aris))
					{
					}
					free(aris->should_close);
				}
			}
			pthread_mutex_destroy(&write);
		}
		free(spinoza);
	}
}

static t_bool	check_meals(t_aristoteles *aris)
{
	t_aristoteles	*ptr;

	ptr = aris;
	if (aris->spinoza.n_philos > 1)
	{
		if (ptr->spinoza.meals)
			return (true);
		ptr = ptr->right;
		while (ptr != aris)
		{
			if (ptr->spinoza.meals)
				return (true);
			ptr = ptr->right;
		}
	}
	else
		return (true);
	return (false);
}

/*
static void	leaks(void)
{
	system("leaks -q philo");
}
*/

int	main(int argc, char **argv)
{
	tales_de_mileto(argc, argv);
}

	//atexit(leaks);