/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:02:09 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/23 13:59:18 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sort(t_node *stack)
{
	int		cur;
	int		prev;
	t_node	*temp;

	if (!stack || get_size(stack) == 1)
		return (1);
	prev = stack->content;
	temp = stack->next;
	cur = temp->content;
	while (temp != stack)
	{
		if (cur < prev)
			return (0);
		prev = cur;
		temp = temp->next;
		cur = temp->content;
	}
	return (1);
}

int	check_r_sort(t_node *stack)
{
	int		cur;
	int		first;
	int		prev;
	t_node	*temp;

	first = stack->content;
	prev = first;
	cur = stack->next->content;
	temp = stack->next;
	while (cur != first)
	{
		if (cur > prev)
			return (0);
		prev = cur;
		cur = temp->next->content;
		temp = temp->next;
	}
	return (1);
}

int	get_size(t_node *stack)
{
	int		i;
	t_node	*temp;

	if (!stack->next)
		return (1);
	i = 1;
	temp = stack->next;
	while (temp != stack)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_max(t_node *stack)
{
	int		min;
	int		cur;
	t_node	*temp;

	temp = stack->next;
	min = stack->content;
	cur = temp->content;
	while (cur != stack->content)
	{
		if (cur > min)
			min = cur;
		temp = temp->next;
		cur = temp->content;
	}
	return (min);
}
