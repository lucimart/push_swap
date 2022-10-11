/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:38:57 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/11 20:36:15 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	parse(argv, &stack_a, &stack_b);
	sort(&stack_a, &stack_b);
	free(stack_a.arr);
	free(stack_b.arr);
	return (0);
}
