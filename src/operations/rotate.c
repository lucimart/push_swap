/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:41:45 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/09 15:04:48 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_push_swap.h";

/*
* Shift up all elements of stack by 1.
* The first element becomes the last one.
*/
static void	rotate(t_stack *stack_ptr)
{
	t_stack	stack;
	int		first_element;

	stack = *stack_ptr;
	first_element = shift_l(stack_ptr);
	stack.arr[stack.cnt] = first_element;
	stack.cnt++;
}

/*
* Shift up all elements of stack a by 1.
* The first element becomes the last one.
*/
void	rotate_a(t_stack *stack_a_ptr)
{
	rotate(stack_a_ptr);
	ft_putstr("ra\n");
}

/*
* Shift up all elements of stack b by 1.
* The first element becomes the last one.
*/
void	rotate_b(t_stack *stack_b_ptr)
{
	rotate(stack_b_ptr);
	ft_putstr("rb\n");
}

/*
* rotate_a and rotate_b at the same time
*/
void	rotate_r(t_stack *stack_a_ptr, t_stack *stack_b_ptr)
{
	rotate(stack_a_ptr);
	rotate(stack_b_ptr);
	ft_putstr("rr\n");
}
