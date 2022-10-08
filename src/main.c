/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:38:57 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/08 21:49:04 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;
	int	*stack_b;

	if (argc < 2)
		return (0);
	parse(argv, &stack_a, &stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
