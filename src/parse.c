/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:46:37 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/09 20:41:55 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

char	**join_and_split(char **arr)
{
	char	*tmp;
	char	**args;

	tmp = strarrjoin((arr + 1), " ");
	args = ft_split(tmp, ' ');
	free(tmp);
	return (args);
}

void	index_arr(int *arr, int len, int **index_arr_ptr)
{
	int	i;
	int	index;
	int	*index_arr;

	i = 0;
	fill_int_arr(index_arr_ptr, len, -1);
	index_arr = *index_arr_ptr;
	while (smallest_int(index_arr, len) == -1)
	{
		if (smallest_int(arr, len) == INT_MAX)
		{
			index = smallest_int_index(index_arr, len);
			index_arr[index] = i;
			i++;
		}
		else
		{
			index = smallest_int_index(arr, len);
			index_arr[index] = i;
			i++;
		}
		arr[index] = INT_MAX;
	}
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int *arr, int len)
{
	stack_a->arr = (int *)malloc(sizeof(int) * len);
	stack_b->arr = (int *)malloc(sizeof(int) * len);
	if (!stack_b->arr || !stack_a->arr)
		error();
	stack_a->len = len;
	stack_b->len = len;
	stack_a->cnt = len;
	stack_b->cnt = 0;
	index_arr(arr, len, &(stack_a->arr));
}

/*
* Join all the argv, split them by ' ', alloc space for stacks,
* convert the split arr to int arr and confirm there are no dups
*/
void	parse(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		*tmp;
	char	**args;
	int		args_len;

	args = join_and_split(argv);
	args_len = double_pointer_len((void **)args);
	if (!str_arr_to_int_arr(args, args_len, &tmp))
		error();
	if (has_duplicated_int(tmp, args_len))
		error();
	init_stack(stack_a, stack_b, tmp, args_len);
	free(tmp);
	free_str_arr(args);
}
