/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:41:41 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/11 21:18:09 by lucimart         ###   ########.fr       */
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

void	swap_a(int **arr_ptr, int len)
{
	if (len < 2)
		return ;
	swap(arr_ptr);
	ft_putstr("sa\n");
}

void	swap_b(int **arr_ptr, int len)
{
	if (len < 2)
		return ;
	swap(arr_ptr);
	ft_putstr("sb\n");
}

/*
* Swap 2 arrs at the same time
*/
void	swap_s(int **arr_ptr_a, int len_a, int **arr_ptr_b, int len_b)
{
	if (len_a < 2 || len_b < 2)
		return ;
	swap(arr_ptr_a);
	swap(arr_ptr_b);
	ft_putstr("ss\n");
}
