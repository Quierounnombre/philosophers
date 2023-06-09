/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laplace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:39:34 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/27 15:59:12 by vicgarci         ###   ########.fr       */
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
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "democrito.h"

//philo

t_bool			affinius(t_spinoza **spinoza);
t_bool			diogenes(int argc, char **argv, t_spinoza *spinoza);
t_bool			plato(t_spinoza *spinoza, t_aristoteles **aristoteles,
					pthread_mutex_t *write);
void			*heraclito(void *ptr);
void			pitagoras(t_aristoteles *aristoteles);
void			*schopenhauer(void *ptr);

//ACTIONS

void			ft_eat(t_aristoteles *aris);
t_bool			ft_parlor_whit_dead(t_aristoteles *aristoteles);
void			ft_sleep(t_aristoteles *aris);
void			ft_think(t_aristoteles *aris);

//UTILS

void			ft_log(int philo, int action, unsigned long time);
char			*ft_itoa(int c);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
t_bool			print_error_msg(char *error);
unsigned long	kant(void);
void			ft_log_mutex(int action, pthread_mutex_t *write,
					t_p_int *should_close, t_aristoteles *aris);
void			ft_usleep(unsigned long wait_time);

#endif