/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nano.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:23:48 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/20 15:32:01 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_node *stack)
{
	int		min;
	int		cur;
	t_node	*temp;

	temp = stack->next;
	min = stack->content;
	cur = temp->content;
	while (cur != stack->content)
	{
		if (cur < min)
			min = cur;
		temp = temp->next;
		cur = temp->content;
	}
	return (min);
}

void	ps_sort_two(t_node **stack)
{
	if (!check_sort(*stack))
		ps_sa(stack);
}

void	ps_sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->prev->content;
	if (check_sort(*stack))
		return ;
	if (check_r_sort(*stack))
	{
		ps_ra(stack);
		ps_sa(stack);
	}
	else if (first > second && first < third)
		ps_sa(stack);
	else if (first > second && first > third)
		ps_ra(stack);
	else if (first < second && first < third)
	{
		ps_sa(stack);
		ps_ra(stack);
	}
	else
		ps_rra(stack);
}

void	ps_sort_four(t_node **a, t_node **b)
{
	int	min;

	if (check_sort(*a))
		return ;
	min = find_min(*a);
	while ((*a)->content != min && (*a)->prev->content != min)
		ps_ra(a);
	if ((*a)->prev->content == min)
		ps_rra(a);
	if (check_sort(*a))
		return ;
	ps_pb(a, b);
	ps_sort_three(a);
	ps_pa(b, a);
}

void	ps_sort_five(t_node **a, t_node **b)
{
	int	min;

	if (check_sort(*a))
		return ;
	min = find_min(*a);
	while ((*a)->content != min && (*a)->prev->content != min
		&& (*a)->prev->prev->content != min)
		ps_ra(a);
	if ((*a)->prev->content == min)
		ps_rra(a);
	if ((*a)->prev->prev->content == min)
	{
		ps_rra(a);
		ps_rra(a);
	}
	if (check_sort(*a))
		return ;
	ps_pb(a, b);
	ps_sort_four(a, b);
	ps_pa(b, a);
}
