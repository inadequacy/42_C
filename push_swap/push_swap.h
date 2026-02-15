/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:11:57 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/29 14:37:48 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

// sort make happenors
void	normalize(int *stack, int length);
void	push_swap(int *stack_a, int length);
void	radix_function(int *stack_a, int *stack_b, int *lengths, int bit);
void	sort_three(int *stack, int length);
void	sort_five(int *stack_a, int length);

int		count_args(char **args);
int		det_length(char *str);
int		determine_rank(int *stack, int length, int value);
char	**free_chr(char **str);

// sort manipulators - just the ones used
void	push_a(int *stack_a, int *stack_b, int *lengths);
void	push_b(int *stack_a, int *stack_b, int *lengths);
void	rotate_a(int *stack, int length);
void	r_rotate_a(int *stack, int length);
void	swap_a(int *stack);

// validation or verifications or something
int		check_doubles(int *stack, int length);
int		check_nbr(char *argv);
int		*error_msg(char **stack, int argc);
int		find_max(int *stack, int length);
int		*validate_input(int argc, char **argv, int *stack_a, int *length);
int		check_order(int *stack_a, int length);

#endif