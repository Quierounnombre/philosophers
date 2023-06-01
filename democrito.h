/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   democrito.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:43:11 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/01 15:52:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEMOCRITO_H
# define DEMOCRITO_H

typedef enum s_bool
{
	false = 0,
	true = 1
}			t_bool;

/*
@par spinoza fue un filosofo racionalista del siglo 17, y es considerado uno de
sus principales defensores junto a descartes y leibniz, este ultimo fue su
discipulo, importante destacar que en su vertiente del racionalismo, todo es
una cara, un conato, una parte de dios, entendido en este caso como una sustancia
infinita, eterna y perfecta

@brief Structura general del philosophers
@param n_philos numero de filosofos
@param time_to_die cuanto tardan en morir
@param time_to_eat cuanto tardan en comer
@param time_to_sleep cuanto tardan en dormir
@param meals cuantas veces tienen que comer
*/
typedef struct s_spinoza
{
	int		n_philos;
	float	time_to_die;
	float	time_to_eat;
	float	time_to_sleep;
	int		meals;
}			t_spinoza;

#endif