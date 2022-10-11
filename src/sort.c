/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:36:37 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/11 21:20:56 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

/*
* return the amount of bits in a number
* TODO test how it works for negative integers
*/
static int	bits_in(int nbr)
{
	int	bits;

	bits = 0;
	while ((nbr >> bits) != 0)
		bits++;
	return (bits);
}

static int	bit_at_ith_is_1(int nbr, int i)
{
	return (((nbr >> i) & 1) == 1);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bits;
	int	i;
	int	j;

	if (is_sorted(stack_a->arr, stack_a->cnt))
		return ;
	bits = bits_in(stack_a->len - 1);
	i = 0;
	j = 0;
	while (i < bits)
	{
		while (j < stack_a->len)
		{
			if (bit_at_ith_is_1(stack_a->arr[0], i))
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		j = 0;
		while (stack_b->cnt != 0)
			push_a(stack_a, stack_b);
		i++;
	}
}
