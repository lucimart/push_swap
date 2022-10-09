/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:21:56 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/09 14:44:15 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_push_swap.h";

/*
* Shift every int in the array of the stack to the right
* and return the popped last element, leaving the first
* position empty  (a 0 that must be changed)
*/
int	shift_r(t_stack *stack_ptr)
{
	t_stack	stack;
	int		ret;
	int		tmp;
	int		i;

	stack = *stack_ptr;
	i = stack.cnt;
	ret = stack.arr[stack.cnt - 1];
	while (i > 1)
	{
		stack.arr[i - 1] = stack.arr[i - 2];
		i--;
	}
	stack.arr[0] = 0;
	stack.cnt--;
	return (ret);
}

/*
* Shift every int in the array of the stack to the left
* and return the popped first element, leaving the last
* position empty (a 0 that must be changed)
*/
int	shift_l(t_stack *stack_ptr)
{
	t_stack	stack;
	int		ret;
	int		tmp;
	int		i;

	stack = *stack_ptr;
	i = stack.cnt;
	ret = stack.arr[0];
	while (i < stack.cnt - 1)
	{
		stack.arr[i] = stack.arr[i + 1];
		i++;
	}
	stack.arr[i] = 0;
	stack.cnt--;
	return (ret);
}
