/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:45:00 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/23 14:42:35 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
static void	print_stack(t_node *stack)
{
	t_node	*temp;

	if (!stack)
	{
		printf("Empty stack!\n");
		return ;
	}
	if (!stack->next)
	{
		printf("There is only one element in stack: %d\n", stack->content);
		return ;
	}
	temp = stack->next;
	printf("Content in stack:\n");
	printf("%d\n", stack->content);
	while (temp != stack)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
	}
}
*/
static void	push_swap(char **numbers, t_node **a, t_node **b)
{
	int	size;

	size = get_size(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		ps_sort_two(a);
	else if (size == 3)
		ps_sort_three(a);
	else if (size == 4)
		ps_sort_four(a, b);
	else if (size == 5)
		ps_sort_five(a, b);
	else
		ps_sort_big(size, numbers, a, b);
}

static void	clear_tab(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	while (i--)
		free(numbers[i]);
	free(numbers);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**numbers;

	if (argc == 1)
		return (0);
	if (argc > 2)
		exit_error();
	numbers = ft_split(argv[1], ' ');
	if (!numbers)
		exit_error();
	is_valid_number(numbers);
	is_duplicated(numbers);
	stack_a = NULL;
	build_stack(numbers, &stack_a);
	stack_b = NULL;
	push_swap(numbers, &stack_a, &stack_b);
	clear_stack(&stack_a);
	clear_tab(numbers);
}
