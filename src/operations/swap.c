/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:41:41 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/12 00:15:03 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_push_swap.h"

/*
* Given a ptr to an int arr with at least length 2,
* swap the position of the first 2 elements
*/
static void	swap(int **arr_ptr)
{
	int	*arr;
	int	tmp;

	arr = *arr_ptr;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
}

void	swap_a(t_stack *stack)
{
	if (stack->cnt < 2)
		return ;
	swap(&stack->arr);
	ft_putstr("sa\n");
}

void	swap_b(t_stack *stack)
{
	if (stack->cnt < 2)
		return ;
	swap(&stack->arr);
	ft_putstr("sb\n");
}

/*
* Swap 2 arrs at the same time
*/
void	swap_s(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->cnt < 2 || stack_b->cnt < 2)
		return ;
	swap(&stack_a->arr);
	swap(&stack_b->arr);
	ft_putstr("ss\n");
}
