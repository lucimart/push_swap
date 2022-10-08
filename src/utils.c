/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:08:56 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/08 19:08:58 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_push_swap.h"

void	error(void)
{
	write(STDERR_FILENO, "Error\n", 7);
	exit(EXIT_FAILURE);
}
