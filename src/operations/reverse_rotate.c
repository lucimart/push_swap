/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:41:48 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/11 21:41:42 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_push_swap.h"

/*
* Shift down all elements of stack by 1.
* The last element becomes the first one.
*/
static void	reverse_rotate(t_stack *stack)
{
	int	last_element;

	last_element = shift_r(stack);
	stack->arr[0] = last_element;
	stack->cnt++;
}

/*
* Shift down all elements of stack a by 1.
* The last element becomes the first one.
*/
void	reverse_rotate_a(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

/*
* Shift down all elements of stack b by 1.
* The last element becomes the first one.
*/
void	reverse_rotate_b(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

/*
* reverse_rotate_a and reverse_rotate_b at the same time
*/
void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}
