/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   democrito.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:43:11 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/05 10:37:13 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEMOCRITO_H
# define DEMOCRITO_H

/*
Democrito fue un filosofo griego que principalmente se e conoce por el atomismo,
mediante esta visión  filosofica el mundo esta compuesto de atomos y vacio, se
diferencia de la concepción moderna de atomo, desde su indivisibilidad hasta
sus cualidades internas.

por sus multiples trabajos matematicos, fisicos y antropologicos se le considera
como uno de los padres de la ciencia moderna.

Aun así es conocido por su personalidad risueña siendo apodado como "el filosofo
que rie"
*/

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
@param time_to_die cuanto tardan en morir, en ms
@param time_to_eat cuanto tardan en comer, en ms
@param time_to_sleep cuanto tardan en dormir, en ms
@param meals cuantas veces tienen que comer
*/
typedef struct s_spinoza
{
	int		n_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals;
}			t_spinoza;

#endif