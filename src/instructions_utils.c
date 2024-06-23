/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:20:46 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/20 14:59:22 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_content(t_node **a, t_node **b)
{
	int	swap;

	swap = (*a)->content;
	(*a)->content = (*b)->content;
	(*b)->content = swap;
}

void	ps_s(t_node **stack)
{
	swap_content(stack, &(*stack)->next);
}

void	ps_r(t_node **stack)
{
	*stack = (*stack)->next;
}

void	ps_rrx(t_node **stack)
{
	*stack = (*stack)->prev;
}

void	ps_p(t_node **from, t_node **to)
{
	t_node	*new_node;

	if (*from == NULL)
		return ;
	new_node = ft_create_new_node((*from)->content, NULL, NULL);
	ft_delete_first_node(from);
	ft_add_first_node(to, new_node);
}
