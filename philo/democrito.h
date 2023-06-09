/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   democrito.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:43:11 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/28 16:16:11 by vicgarci         ###   ########.fr       */
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

typedef _Atomic int				t_p_int;
typedef _Atomic unsigned long	t_p_ul;

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
	t_p_int	meals;
}			t_spinoza;

/*
@par aristoteles fue un discipulo de platón, a diferencia de su maestro el
coloco la experiencia como la fuente de conocimiento predilecta, esto se ve
reflejado por ejemplo en el cuadro de "la escuela de atenas" donde se les
puede ver a ambos debatir.

Junto a su maestro se le considera uno de los padres de la filosofía occidental,
fue el maestro de alejandro magno y es reconocido por multiples aportaciones
a numerosas disciplinas.

@brief Estructura creada para cada filosofo
@param id Es el identificador del aristoteles
@param spinoza es la estructura general del philo
@param pthread	es el identificador del theread
@param crono es el hilo que gestiona el tiempo
@param t_last_meal es el tiempo desde que termino su ultima comida
@param fork mutex para el control de las comidas
@param right es el filosofo que tiene a su derecha.
@param should_close gestiona si el programa debería de cerrarse
@param write controla el acceso a al log
*/
typedef struct s_aristoteles
{
	t_p_int					id;
	t_spinoza				spinoza;
	pthread_t				thread;
	pthread_t				crono;
	t_p_int					t_last_meal;
	pthread_mutex_t			fork;
	struct s_aristoteles	*right;
	t_p_int					*should_close;
	pthread_mutex_t			*write;
	t_p_ul					init_time;
}			t_aristoteles;

//------------------------------------------------------------------------------

# ifndef MIN_ARGCS
#  define MIN_ARGCS 5
# endif

# ifndef MAX_ARGCS
#  define MAX_ARGCS 6
# endif

# ifndef ERROR_MSG_N_ARGS
#  define ERROR_MSG_N_ARGS "El numero de argumentos es incorrecto\n"
# endif

# ifndef ERROR_MSG_INCORRECT_PARSE
#  define ERROR_MSG_INCORRECT_PARSE "\n\n\
Los argumentos entán mal formateados,\
tienen que estar en formato numerico entero(POSITIVO),\n\
no nulo, ej: '4' '1000' '1000' '1000' ('5') etc, distribuidos \
de esta manera:\n\
numero de filosofos\n\
tiempo hasta su muerte(en ms)\n\
tiempo para comer(en ms)\n\
tiempo para dormir(en ms)\n\
(OPCIONAL)Numero de comidas\n\n\n"
# endif

# ifndef US_TO_MS
#  define US_TO_MS 1000
# endif

# ifndef T_PROGRES
#  define T_PROGRES 1
# endif

#endif