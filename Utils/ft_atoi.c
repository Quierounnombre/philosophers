/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:17:44 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/05 10:18:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../laplace.h"

int	ft_atoi(const char *str)
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
