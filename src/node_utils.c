/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:08:30 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/23 14:34:44 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_create_new_node(int content, t_node *next, t_node *prev)
{
	t_node	*new;

	new = malloc(sizeof (t_node));
	if (!new)
		exit_error();
	new->content = content;
	new->next = next;
	new->prev = prev;
	return (new);
}

void	ft_add_first_node(t_node **stack, t_node *new_node)
{
	t_node	*swap_prev;

	if (!(*stack))
	{
		*stack = new_node;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	else if ((*stack)->next == NULL && (*stack)->prev == NULL)
	{
		(*stack)->next = new_node;
		(*stack)->prev = new_node;
		new_node->prev = *stack;
		new_node->next = *stack;
	}
	else
	{
		swap_prev = (*stack)->prev;
		swap_prev->next = new_node;
		new_node->next = *stack;
		new_node->prev = swap_prev;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

void	ft_delete_first_node(t_node **stack)
{
	t_node	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	if ((*stack)->next == NULL && (*stack)->prev == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		if ((*stack)->next == (*stack)->prev)
		{
			(*stack)->next->next = NULL;
			(*stack)->next->prev = NULL;
		}
		else
		{
			(*stack)->next->prev = (*stack)->prev;
			(*stack)->prev->next = (*stack)->next;
		}
		*stack = (*stack)->next;
		free(temp);
	}
}

void	clear_stack(t_node **stack)
{
	while (*stack)
		ft_delete_first_node(stack);
}

void	build_stack(char **numbers, t_node **stack)
{
	int		num;
	int		i;
	t_node	*next_node;
	t_node	*prev_node;

	i = 0;
	num = ps_atoi(numbers[i]);
	*stack = ft_create_new_node(num, NULL, NULL);
	prev_node = *stack;
	i++;
	while (numbers[i])
	{
		num = ps_atoi(numbers[i]);
		next_node = ft_create_new_node(num, NULL, prev_node);
		prev_node->next = next_node;
		prev_node = next_node;
		i++;
	}
	if (i > 1)
	{
		next_node->next = *stack;
		(*stack)->prev = next_node;
	}
}
