/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:34:32 by xiaxu             #+#    #+#             */
/*   Updated: 2024/07/17 19:26:17 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_until_three(int size, int median, t_node **a, t_node **b)
{
	int	i;

	i = 0;
	while (i < size - 3)
	{
		ps_pb(a, b);
		if ((*b)->content > median && get_size(*b) != 1)
			ps_rb(b);
		i++;
	}
	ps_sort_three(a);
}

int	find_position(t_node *a, int num)
{
	int		i;
	t_node	*temp;

	if (num < find_min(a))
		return (find_position(a, find_min(a)));
	if (num > find_max(a))
		return (find_position(a, find_max(a)) + 1);
	if (a->content > num && a->prev->content < num)
		return (0);
	i = 0;
	temp = a;
	while (temp->content > num)
	{
		temp = temp->next;
		i++;
	}
	while (temp->content < num)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_max_in_two(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	sort_a(t_node **a)
{
	int		pos;
	t_node	*temp;
	int		size;
	int		min;

	pos = 0;
	temp = *a;
	min = find_min(*a);
	while (temp->content != min)
	{
		pos++;
		temp = temp->next;
	}
	size = get_size(*a);
	if (size - pos >= pos)
	{
		while (pos--)
			ps_ra(a);
	}
	else
	{
		while (size > pos++)
			ps_rra(a);
	}
}

void	do_best_solution(t_solutions *solution, t_node **a, t_node **b)
{
	if (solution->sol == RR_RA)
		do_rr_ra(solution, a, b);
	else if (solution->sol == RR_RB)
		do_rr_rb(solution, a, b);
	else if (solution->sol == RRR_RRA)
		do_rrr_rra(solution, a, b);
	else if (solution->sol == RRR_RRB)
		do_rrr_rrb(solution, a, b);
	else if (solution->sol == RRA_RB)
		do_rra_rb(solution, a, b);
	else if (solution->sol == RA_RRB)
		do_ra_rrb(solution, a, b);
	ps_pa(b, a);
}
