/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:36:37 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/12 01:18:58 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

static void	radix(t_stack *stack_a, t_stack *stack_b)
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

static void	sort_3(t_stack *stack_a)
{
	int	*arr;

	arr = stack_a->arr;
	if (arr[1] < arr[0] && arr[1] < arr[2] && arr[0] < arr[2])
		swap_a(stack_a);
	else if (arr[1] < arr[0] && arr[1] > arr[2] && arr[0] > arr[2])
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (arr[1] < arr[0] && arr[1] < arr[2] && arr[0] > arr[2])
		rotate_a(stack_a);
	else if (arr[1] > arr[0] && arr[1] > arr[2] && arr[0] < arr[2])
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (arr[1] > arr[0] && arr[1] > arr[2] && arr[0] > arr[2])
		reverse_rotate_a(stack_a);
}

static void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	*arr_a;
	int	*arr_b;

	arr_a = stack_a->arr;
	arr_b = stack_b->arr;
	while (stack_a->cnt != 3)
	{
		if (arr_a[0] == 0 || arr_a[0] == 1)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_3(stack_a);
	if (arr_b[0] < arr_b[1])
		rotate_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 3)
		sort_3(stack_a);
	if (stack_a->len == 5)
		sort_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
