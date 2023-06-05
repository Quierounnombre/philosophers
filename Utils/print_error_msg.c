/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:27:10 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/05 14:27:32 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

t_bool	print_error_msg(char *error)
{
	printf("%s", error);
	return (false);
}
