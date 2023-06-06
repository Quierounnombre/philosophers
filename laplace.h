/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laplace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:39:34 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/06 15:36:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAPLACE_H
# define LAPLACE_H

/*
La place fue un matematico frances, que vivio durante la epoca napoleonica,
el cual es conecido por por sus aportes a la fisica, matematica y astronomia,
aun así es tambien conocido por sostener filosoficamente el determinismo 
cientifico, es conocido por presentar el genio(tambien llamado demonio) de
laplace, que viene de la mano de la fisica clasica.

Consiste en, dado que todos los movimiento de los objetos son predecibles
mediantes diferentes tipos de operaciones fisicas y matematicas, desde el
movimiento de levantarte por las mañanas hasta la orbita solar, dado un genío
dotado tal que sea capaz de calcularlo todo, tanto el pasado,
presente y futuro serían claros a su intelecto, no notando diferencia entre
ellos.
*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "democrito.h"

t_bool	affinius(t_spinoza **spinoza);
t_bool	diogenes(int argc, char **argv, t_spinoza *spinoza);
t_bool	plato(t_spinoza *spinoza, t_aristoteles **aristoteles);

//UTILS
char	*ft_itoa(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
t_bool	print_error_msg(char *error);

#endif