/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diogenes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:38:01 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/02 12:47:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laplace.h"

static t_bool	parse_argc(const char **argv);
static int		ft_atoi(const char *str);

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
		return (false);
	if (parse_argc((const char **)argv))
		return (false);
	spinoza->n_philos = ft_atoi(argv[1]);
	spinoza->time_to_die = ft_atoi(argv[2]);
	spinoza->time_to_eat = ft_atoi(argv[3]);
	spinoza->time_to_sleep = ft_atoi(argv[4]);
	if (argc == MAX_ARGCS)
		spinoza->meals = ft_atoi(argv[5]);
	return (true);
}

//------------------------------------------------------------------------

static t_bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

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
			if (!ft_isdigit(argv[i][j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

//------------------------------------------------------------------------

static int	ft_atoi(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = (i * 10) + (*str - '0');
		str++;
	}
	return (i * neg);
}
