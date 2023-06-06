/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plato.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:44:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/06 15:42:40 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

static t_bool	free_error(t_aristoteles **aristoteles);
static void		teach_aristoteles(t_spinoza *spinoza,
					t_aristoteles *aristoteles, int new_id);
static void		add_aristoteles_to_lst(t_aristoteles **aristoteles,
					t_aristoteles *new_aristoteles);

/*
@par Platón es una las mentes más importantes de occidente, discipulo de
socrates, maestro de aristoteles, platón creo un a filosofía centrada en la
razón, siendo sus ideas criticas en la creación de religiones como la cristiana
a posterior, que según algunos autores es "platónn descafeinado"

@brief Esta función crea una cantidad n de estructuras aristoteles,
la cual esta indicada en spinoza, carga el puntero aristoteles con
el primer elemento de la lista circular de los aristoteles
@param spinoza estructura de uso general
@param aristoteles el puntero al primer elemento dde la listaa circular
@return Verdadero, si ha logrado alocar la memoria para N-aristoteles
*/
t_bool	plato(t_spinoza *spinoza, t_aristoteles **aristoteles)
{
	t_aristoteles	*local_aristoteles;
	int				n_aris;

	local_aristoteles = NULL;
	n_aris = spinoza->n_philos;
	while (n_aris)
	{
		local_aristoteles = (t_aristoteles *)malloc(sizeof(t_aristoteles));
		if (!local_aristoteles)
			return (free_error(aristoteles));
		teach_aristoteles(spinoza, local_aristoteles, -1);
		add_aristoteles_to_lst(aristoteles, local_aristoteles);
		n_aris--;
	}
	(*aristoteles)->right = local_aristoteles;
	return (true);
}

//Carga a aristoteles con las cosas necesarias
static void	teach_aristoteles(t_spinoza *spinoza, t_aristoteles *aristoteles,
	int new_id)
{
	aristoteles->id = new_id;
	aristoteles->spinoza = *spinoza;
	aristoteles->right = NULL;
	aristoteles->has_fork = true;
}

//En caso de que malloc falle libera todo
static t_bool	free_error(t_aristoteles **aristoteles)
{
	t_aristoteles	*local_aris;
	t_aristoteles	*next_aris;

	local_aris = *aristoteles;
	next_aris = NULL;
	while (local_aris)
	{
		if (local_aris->right)
			next_aris = local_aris->right;
		free(local_aris);
		local_aris = next_aris;
	}
	return (false);
}

//Introduce aristoteles a sus amigos
static void	add_aristoteles_to_lst(t_aristoteles **aristoteles,
				t_aristoteles *new_aristoteles)
{
	t_aristoteles	*loking_for;

	loking_for = (*aristoteles);
	if (!loking_for)
		(*aristoteles) = new_aristoteles;
	else
	{
		while (loking_for)
			loking_for = loking_for->right;
		loking_for->right = new_aristoteles;
	}
}