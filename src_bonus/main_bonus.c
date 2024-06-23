/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:09:38 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/23 15:00:37 by xiaxu            ###   ########.fr       */
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
static int	is_valid_op(char *s)
{
	return (!ft_strncmp(s, "sa\n", 3) || !ft_strncmp(s, "sb\n", 3)
		|| !ft_strncmp(s, "ss\n", 3) || !ft_strncmp(s, "pa\n", 3)
		|| !ft_strncmp(s, "pb\n", 3) || !ft_strncmp(s, "rr\n", 3)
		|| !ft_strncmp(s, "ra\n", 3) || !ft_strncmp(s, "rb\n", 3)
		|| !ft_strncmp(s, "rra\n", 4) || !ft_strncmp(s, "rrb\n", 4)
		|| !ft_strncmp(s, "rrr\n", 4));
}

static void	do_ops(char *op, t_node **a, t_node **b)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		ps_s(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		ps_s(b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ps_ss_silent(a, b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ps_r(a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		ps_r(b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		ps_rr_silent(a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		ps_rrx(a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		ps_rrx(b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		ps_p(b, a);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		ps_p(a, b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		ps_rrr_silent(a, b);
}

static void	deal_result(t_node *stack_a, char **numbers, char *buffer)
{
	int	size;

	size = 0;
	while (numbers[size])
		size++;
	if (check_sort(stack_a) == 1 && get_size(stack_a) == size)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 2);
	while (size--)
		free(numbers[size]);
	free(numbers);
	clear_stack(&stack_a);
	free(buffer);
}

static void	check_input(int argc, char **numbers, char **buffer)
{
	if (argc != 2)
		exit_error();
	is_valid_number(numbers);
	is_duplicated(numbers);
	*buffer = malloc(5);
	if (!(*buffer))
		exit_error();
}

int	main(int argc, char **argv)
{
	char	*buffer;
	char	**numbers;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	numbers = ft_split(argv[1], ' ');
	buffer = NULL;
	check_input(argc, numbers, &buffer);
	stack_a = NULL;
	build_stack(numbers, &stack_a);
	stack_b = NULL;
	while (1)
	{
		read(0, buffer, 4);
		if (buffer[0] == '\n')
			break ;
		if (!is_valid_op(buffer))
			exit_error();
		do_ops(buffer, &stack_a, &stack_b);
		buffer[3] = '\0';
	}
	deal_result(stack_a, numbers, buffer);
}
