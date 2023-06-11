/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diogenes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:38:01 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/11 14:44:28 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

static t_bool	parse_argc(const char **argv);
static t_bool	check_overflow(const char *argv);

/*
@par diogenes se caracteriza por su peculiar vida y filosofia, es uno de los
cinicos más notados debido a su vida austera, sus riñas con emperadores y
por la comodidad de su barril.

Su filosofia consiste en mirar a la vida desde un punto de vista muy crudo
y directo, destaca por el total rechazo a las riquezas, dado que no según los
cinicos no era necesario nada externo, pues el hombre ya tiene lo necesario
para ser feliz, rechazando de esta manera no solo las riquezas sino las
convenciones sociales, lo cual era... curioso cuanto menos.

@brief diogenes es quien se encarga del parseo, recibe a un spinoza y lo carga
con los datos necesarios.
@param argc el numero de argumentos
@param argv los argumentos del programa
@param spinoza la estructura con toda la información aa cargar
@return false si falla, true si todo va bien
*/
t_bool	diogenes(int argc, char **argv, t_spinoza *spinoza)
{
	if (argc < MIN_ARGCS || argc > MAX_ARGCS)
		return (print_error_msg(ERROR_MSG_N_ARGS));
	if (parse_argc((const char **)argv))
		return (print_error_msg(ERROR_MSG_INCORRECT_PARSE));
	spinoza->n_philos = ft_atoi(argv[1]);
	spinoza->time_to_die = ft_atoi(argv[2]);
	spinoza->time_to_eat = ft_atoi(argv[3]);
	spinoza->time_to_sleep = ft_atoi(argv[4]);
	if (argc == MAX_ARGCS)
		spinoza->meals = ft_atoi(argv[5]);
	else
		spinoza->meals = -1;
	return (true);
}

//------------------------------------------------------------------------

static t_bool	parse_argc(const char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (true);
			j++;
		}
		j = 0;
		if (check_overflow(argv[i]))
			return (true);
		i++;
	}
	return (false);
}

//------------------------------------------------------------------------

static t_bool	check_overflow(const char *argv)
{
	char	*s;

	s = ft_itoa(ft_atoi(argv));
	if (s)
	{
		if (ft_strlen(s) != ft_strlen(argv))
		{
			free(s);
			return (true);
		}
		free(s);
	}	
	return (false);
}
