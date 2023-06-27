/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plato.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:44:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 13:08:25 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

static t_bool	free_error(t_aristoteles **aristoteles, t_p_int *close);
static void		teach_aristoteles(t_spinoza *spinoza,
					t_aristoteles *aristoteles, t_p_int *close,
					pthread_mutex_t *write);
static void		add_aristoteles_to_lst(t_aristoteles **aristoteles,
					t_aristoteles *new_aristoteles);
static void		close_the_circle(t_aristoteles *aristoteles);

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
@param write mute para el log
@return Verdadero, si ha logrado alocar la memoria para N-aristoteles
*/
t_bool	plato(t_spinoza *spinoza, t_aristoteles **aristoteles,
				pthread_mutex_t *write)
{
	t_aristoteles	*local_aristoteles;
	t_p_int			*close;
	int				n_aris;

	local_aristoteles = NULL;
	n_aris = spinoza->n_philos;
	close = malloc(sizeof(t_p_int));
	if (close)
	{
		*close = false;
		while (n_aris)
		{
			local_aristoteles = (t_aristoteles *)malloc(sizeof(t_aristoteles));
			if (!local_aristoteles)
				return (free_error(aristoteles, close));
			if (pthread_mutex_init(&(local_aristoteles->fork), NULL))
				return (free_error(aristoteles, close));
			teach_aristoteles(spinoza, local_aristoteles, close, write);
			add_aristoteles_to_lst(aristoteles, local_aristoteles);
			n_aris--;
		}
	}
	close_the_circle(*aristoteles);
	return (true);
}

//Carga a aristoteles con las cosas necesarias
static void	teach_aristoteles(t_spinoza *spinoza, t_aristoteles *aristoteles,
t_p_int *close, pthread_mutex_t *write)
{
	static unsigned int		new_id;

	aristoteles->id = new_id;
	aristoteles->spinoza = *spinoza;
	aristoteles->right = NULL;
	aristoteles->thread = 0;
	aristoteles->t_last_meal = (int)kant();
	aristoteles->should_close = close;
	aristoteles->write = write;
	new_id++;
}

//En caso de que malloc falle libera todo
static t_bool	free_error(t_aristoteles **aristoteles, t_p_int *close)
{
	t_aristoteles	*local_aris;
	t_aristoteles	*next_aris;

	local_aris = *aristoteles;
	next_aris = NULL;
	free(close);
	while (local_aris)
	{
		if (local_aris->right)
			pthread_mutex_destroy(&(local_aris->fork));
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
		while (loking_for->right)
			loking_for = loking_for->right;
		loking_for->right = new_aristoteles;
	}
}

//Cierra el circulo de aristoteles
static void	close_the_circle(t_aristoteles *aristoteles)
{
	t_aristoteles	*loking_for;

	loking_for = aristoteles;
	while (loking_for->right)
		loking_for = loking_for->right;
	loking_for->right = aristoteles;
}
