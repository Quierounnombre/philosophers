/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tales_de_mileto.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:37:47 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/05 10:25:44 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

/*
Tales de mileto esta considerado el primer filosofo documentado en la historia
humana, nativo de Mileto, una polis griega ubicada en la anatolia, se le
atribuyen multiples aportaciones, pero lo más importante es aplicar el uso de
la razón para encontrar una respuesta a las grandes preguntas.

Aun así el hecho de que no se perserve ningún documento directo suyo, hace que
sea dificil atribuirle correctamente todos sus hallazgos
*/
static void	tales_de_mileto(int argc, char **argv)
{
	t_spinoza	*spinoza;

	if (affinius(&spinoza))
	{
		if (diogenes(argc, argv, spinoza))
		{
			printf("philos -> %d\n", spinoza->n_philos);
			printf("t_die -> %d\n", spinoza->time_to_die);
			printf("t_e -> %d\n", spinoza->time_to_eat);
			printf("t_s -> %d\n", spinoza->time_to_sleep);
		}
		free(spinoza);
	}
}

int	main(int argc, char **argv)
{
	tales_de_mileto(argc, argv);
	//system("leaks philo");
}
