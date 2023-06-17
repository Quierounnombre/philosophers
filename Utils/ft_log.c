/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:15:13 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/18 00:42:37 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

/*
1 = fork
2 = eat
3 = sleep
4 = think
5 = die
*/

/*
Gestiona todo el output por consola del philosophers,
@param philo es el numero del philo que ejecuta la acción
@param action es el tipo de accion que va a ejecutar
*/
void	ft_log(int philo, int action)
{
	char			*s;

	if (action == 1)
		s = "\033[0;31mhas taken a fork\033[0m";
	if (action == 2)
		s = "\033[0;32mis eating\033[0m";
	if (action == 3)
		s = "\033[0;33mis sleeping\033[0m";
	if (action == 4)
		s = "\033[0;34mis thinking\033[0m";
	if (action == 5)
		s = "died";
	printf("\033[0;30m%ld\033[0m %d %s\n", kant(), philo, s);
}
