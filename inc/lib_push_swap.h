/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucimart <lucimart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:13:42 by lucimart          #+#    #+#             */
/*   Updated: 2022/10/12 00:15:54 by lucimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int	*arr;
	int	len;
	int	cnt;
}		t_stack;

int		bits_in(int nbr);
int		bit_at_ith_is_1(int nbr, int i);
void	error(void);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	parse(char **argv, t_stack *stack_a_ptr, t_stack *stack_b_ptr);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_s(t_stack *stack_a, t_stack *stack_b);
int		shift_r(t_stack *stack_ptr);
int		shift_l(t_stack *stack_ptr);
void	push_a(t_stack *stack_a_ptr, t_stack *stack_b_ptr);
void	push_b(t_stack *stack_a_ptr, t_stack *stack_b_ptr);
void	rotate_a(t_stack *stack_a_ptr);
void	rotate_b(t_stack *stack_b_ptr);
void	rotate_r(t_stack *stack_a_ptr, t_stack *stack_b_ptr);
void	reverse_rotate_a(t_stack *stack_a_ptr);
void	reverse_rotate_b(t_stack *stack_b_ptr);
void	reverse_rotate_r(t_stack *stack_a_ptr, t_stack *stack_b_ptr);

#endif
