/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:46:37 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/09 16:25:24 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

/*
* Join all the argv, split them by ' ', alloc space for stacks,
* convert the split arr to int arr and confirm there are no dups
*/
void	parse(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	char	*tmp;
	char	**args;
	int		args_len;

	tmp = strarrjoin((argv + 1), " ");
	args = ft_split(tmp, ' ');
	free(tmp);
	args_len = double_pointer_len((void **)args);
	if (!str_arr_to_int_arr(args, args_len, &(stack_a->arr)))
		error();
	stack_b->arr = (int *)malloc(sizeof(int) * args_len);
	if (!stack_b->arr)
		error();
	if (has_duplicated_int(stack_a->arr, args_len))
		error();
	stack_a->len = args_len;
	stack_b->len = args_len;
	stack_a->cnt = args_len;
	stack_b->cnt = 0;
}
