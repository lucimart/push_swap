/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:46:37 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/08 21:51:36 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

/*
* Join all the argv, split them by ' ', alloc space for stacks,
* convert the split arr to int arr and confirm there are no dups
*/
void	parse(char **argv, int **stack_a, int **stack_b)
{
	char	*tmp;
	char	**args;
	int		args_len;

	tmp = strarrjoin((argv + 1), " ");
	args = ft_split(tmp, ' ');
	free(tmp);
	args_len = double_pointer_len((void **)args);
	*stack_a = (int *)malloc(sizeof(int) * args_len);
	*stack_b = (int *)malloc(sizeof(int) * args_len);
	if (!stack_a || !stack_b)
		error();
	if (!str_arr_to_int_arr(args, args_len, stack_a))
		error();
	if (has_duplicated_int(*stack_a, args_len))
		error();
}
