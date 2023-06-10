/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tales_de_mileto.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:37:47 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/10 17:22:43 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

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
	t_aristoteles	*aristoteles;

	spinoza = NULL;
	aristoteles = NULL;
	if (affinius(&spinoza))
	{
		if (diogenes(argc, argv, spinoza))
		{
			if (plato(spinoza, &aristoteles))
			{
				pitagoras(aristoteles);
				printf("HEY\n");
			}
		}
		free(spinoza);
	}
}

int	main(int argc, char **argv)
{
	tales_de_mileto(argc, argv);
	//system("leaks philo");
}
