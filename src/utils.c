/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:08:56 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/12 00:06:20 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/*
* return the amount of bits in a number
* TODO test how it works for negative integers
*/
int	bits_in(int nbr)
{
	int	bits;

	bits = 0;
	while ((nbr >> bits) != 0)
		bits++;
	return (bits);
}

int	bit_at_ith_is_1(int nbr, int i)
{
	return (((nbr >> i) & 1) == 1);
}
