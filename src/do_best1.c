/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:59:38 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/23 13:32:30 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_rr_ra(t_solutions *solution, t_node **a, t_node **b)
{
	int	i;
	int	j;

	i = solution->pos_a;
	j = solution->pos_b;
	if (i == get_size(*a))
		i = 0;
	while (j--)
	{
		ps_rr(a, b);
		i--;
	}
	while (i--)
		ps_ra(a);
}

void	do_rr_rb(t_solutions *solution, t_node **a, t_node **b)
{
	int	i;
	int	j;

	i = solution->pos_a;
	j = solution->pos_b;
	if (i == get_size(*a))
		i = 0;
	while (i--)
	{
		ps_rr(a, b);
		j--;
	}
	while (j--)
		ps_rb(b);
}

void	do_rrr_rra(t_solutions *solution, t_node **a, t_node **b)
{
	int	i;
	int	j;

	i = solution->pos_a;
	j = solution->pos_b;
	while (j != get_size(*b) && j++ < get_size(*b))
	{
		ps_rrr(a, b);
		i++;
	}
	while (i++ < get_size(*a))
		ps_rra(a);
}

void	do_rrr_rrb(t_solutions *solution, t_node **a, t_node **b)
{
	int	i;
	int	j;

	i = solution->pos_a;
	j = solution->pos_b;
	while (i != get_size(*a) && i++ < get_size(*a))
	{
		ps_rrr(a, b);
		j++;
	}
	while (j++ < get_size(*b))
		ps_rrb(b);
}

void	do_rra_rb(t_solutions *solution, t_node **a, t_node **b)
{
	int	i;
	int	j;

	i = solution->pos_a;
	j = solution->pos_b;
	if (i < get_size(*a) && i != 0)
	{
		while (i++ < get_size(*a))
			ps_rra(a);
	}
	while (j--)
		ps_rb(b);
}
