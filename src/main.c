/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:38:57 by lucimart          #+#    #+#             */
/*   Updated: 2022/09/30 16:55:27 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

int	main(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
	}
}


// int	are_valid_chars(int argc, char **argv)
// {
// 	int		i;
// 	char	sign_numbers_whitespace[19];

// 	sign_numbers_whitespace = "+-0123456789 \n\t\v\f\r";
// 	while (argc-- > 0)
// 	{
// 		i = ft_strlen(argv[argc]);
// 		while (i-- > 0)
// 		{
// 			if (!in_set(argv[argc][i], sign_numbers_whitespace))
// 				return (0);
// 		}
// 	}
// 	return (1);
// }

// int	parse(int argc, char **argv, int **numbers)
// {
// 	if (argc < 2)
// 		return (0);
// 	else
// 	{
// 		//CHECK: check that each element in argv starts only by sign,
// 		// is numeric and not bigger than int
// 		//ASSIGN: cast the strings into ints and into the *int in order.
// 		if (!check(argc, argv) || !assign(argc, argv, numbers))
// 			return (0);
// 	}
// 	return (1);
// }

// void	error(void)
// {
// 	write(STDERR_FILENO, "Error\n", 7);
// 	exit(EXIT_FAILURE);
// }

// int	main(int argc, char **argv)
// {
// 	int	*numbers;

// 	if (!parse(argc, argv, &numbers))
// 	{
// 		free(numbers);
// 		error();
// 	}
// 	if (is_sorted(numbers))
// 	{
// 		free(numbers);
// 		return (0);
// 	}
// 	// print numbers to test parser
// }
