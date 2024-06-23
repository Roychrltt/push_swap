/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:10:33 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/23 13:35:22 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_solutions
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;
	int	num;
	int	move;
	int	sol;
}	t_solutions;

# define RR_RA 1
# define RR_RB 2
# define RRR_RRA 3
# define RRR_RRB 4
# define RRA_RB 5
# define RA_RRB 6

// Check Input
void	exit_error(void);
void	is_valid_number(char **numbers);
void	is_duplicated(char **numbers);
int		ps_atoi(char *str);

//Check Sort
int		check_sort(t_node *stack);
int		check_r_sort(t_node *stack);
int		get_size(t_node *stack);
int		find_min(t_node *stack);
int		find_max(t_node *stack);

// Sort Nano Stacks
void	ps_sort_two(t_node **stack);
void	ps_sort_three(t_node **stack);
void	ps_sort_four(t_node **a, t_node **b);
void	ps_sort_five(t_node **a, t_node **b);

// Node Utils
t_node	*ft_create_new_node(int content, t_node *next, t_node *prev);
void	ft_add_first_node(t_node **stack, t_node *new_node);
void	ft_delete_first_node(t_node **stack);
void	clear_stack(t_node **stack);
void	build_stack(char **numbers, t_node **stack);

// Find Median
void	swap(int *x, int *y);
int		partition(int *tab, int start, int end);
void	quick_sort(int *tab, int start, int end);
int		find_median(int size, char **numbers);
int		find_smallest(int size, char **numbers);

// Do Best
void	do_rr_ra(t_solutions *solution, t_node **a, t_node **b);
void	do_rr_rb(t_solutions *solution, t_node **a, t_node **b);
void	do_rrr_rra(t_solutions *solution, t_node **a, t_node **b);
void	do_rrr_rrb(t_solutions *solution, t_node **a, t_node **b);
void	do_rra_rb(t_solutions *solution, t_node **a, t_node **b);
void	do_ra_rrb(t_solutions *solution, t_node **a, t_node **b);

// Sort Big
void	push_until_three(int size, int median, t_node **a, t_node **b);
int		get_position_b(t_node *b, int num);
int		find_position(t_node *a, int num);
int		find_max_in_two(int a, int b);
void	sort_a(t_node **a);
void	find_best_solution(t_solutions *solution, t_node **a, t_node **b);
void	do_best_solution(t_solutions *solution, t_node **a, t_node **b);
void	ps_sort_big(int size, char **numbers, t_node **a, t_node **b);

// Instruction Utils
void	swap_content(t_node **a, t_node **b);
void	ps_s(t_node **stack);
void	ps_r(t_node **stack);
void	ps_rrx(t_node **stack);
void	ps_p(t_node **from, t_node **to);

// Instructions
void	ps_sa(t_node **a);
void	ps_sb(t_node **b);
void	ps_ss(t_node **a, t_node **b);
void	ps_ra(t_node **a);
void	ps_rb(t_node **b);
void	ps_pa(t_node **b, t_node **a);
void	ps_pb(t_node **a, t_node **b);
void	ps_rr(t_node **a, t_node **b);
void	ps_rra(t_node **a);
void	ps_rrb(t_node **b);
void	ps_rrr(t_node **a, t_node **b);

// Bonus Silent Instructions
void	ps_ss_silent(t_node **a, t_node **b);
void	ps_rr_silent(t_node **a, t_node **b);
void	ps_rrr_silent(t_node **a, t_node **b);

// Bonus

#endif
