/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:41:48 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/09 15:08:53 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_push_swap.h";

/*
* Shift down all elements of stack by 1.
* The last element becomes the first one.
*/
static void	reverse_rotate(t_stack *stack_ptr)
{
	t_stack	stack;
	int		last_element;

	stack = *stack_ptr;
	last_element = shift_r(stack_ptr);
	stack.arr[0] = last_element;
	stack.cnt++;
}

/*
* Shift down all elements of stack a by 1.
* The last element becomes the first one.
*/
void	reverse_rotate_a(t_stack *stack_a_ptr)
{
	reverse_rotate(stack_a_ptr);
	ft_putstr("rra\n");
}

/*
* Shift down all elements of stack b by 1.
* The last element becomes the first one.
*/
void	reverse_rotate_b(t_stack *stack_b_ptr)
{
	reverse_rotate(stack_b_ptr);
	ft_putstr("rrb\n");
}

/*
* reverse_rotate_a and reverse_rotate_b at the same time
*/
void	reverse_rotate_r(t_stack *stack_a_ptr, t_stack *stack_b_ptr)
{
	reverse_rotate(stack_a_ptr);
	reverse_rotate(stack_b_ptr);
	ft_putstr("rrr\n");
}
