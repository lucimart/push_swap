/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:41:50 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/11 22:59:52 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_push_swap.h"

/*
* Take the first element at the top of stack2 and put it at the top of stack1.
* Do nothing if b is empty.
*/
static void	push(t_stack *stack1, t_stack *stack2)
{
	int	first_elem_stack2;
	int	last_elem_stack1;

	if (stack2->cnt == 0 || (stack1->cnt == stack1->len))
		return ;
	first_elem_stack2 = shift_l(stack2);
	last_elem_stack1 = shift_r(stack1);
	stack1->arr[0] = first_elem_stack2;
	stack1->cnt++;
	if (stack1->cnt > 0)
		stack1->arr[stack1->cnt] = last_elem_stack1;
	stack1->cnt++;
}

/*
* Take the first element at the top of b and put it at the top of a.
* Do nothing if b is empty.
*/
void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->cnt == 0 || (stack_a->cnt == stack_a->len))
		return ;
	push(stack_a, stack_b);
	ft_putstr("pa\n");
}

/*
* Take the first element at the top of a and put it at the top of b.
* Do nothing if a is empty.
*/
void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->cnt == 0 || (stack_b->cnt == stack_b->len))
		return ;
	push(stack_b, stack_a);
	ft_putstr("pb\n");
}
