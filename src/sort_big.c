/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:25:55 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/23 13:32:44 by xiaxu            ###   ########.fr       */
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
int	get_position_b(t_node *b, int num)
{
	int		i;
	int		cur;
	t_node	*temp;

	i = 0;
	cur = b->content;
	temp = b;
	while (cur != num)
	{
		temp = temp->next;
		cur = temp->content;
		i++;
	}
	return (i);
}

int	find_least_moves(t_solutions *solution, t_node **a, t_node **b, int cur)
{
	solution->pos_a = find_position((*a), cur);
	solution->pos_b = get_position_b((*b), cur);
	solution->size_a = get_size(*a);
	solution->size_b = get_size(*b);
	if (solution->pos_a >= solution->pos_b
		&& solution->pos_a <= solution->size_a / 2)
		return (solution->pos_a);
	else if (solution->pos_b >= solution->pos_a
		&& solution->pos_b <= solution->size_b / 2)
		return (solution->pos_b);
	else if (solution->pos_a >= solution->size_a / 2
		&& solution->pos_b >= solution->size_b / 2)
		return (find_max_in_two(solution->size_a - solution->pos_a,
				solution->size_b - solution->pos_b));
	else if (solution->pos_a >= solution->pos_b)
		return (solution->size_a - solution->pos_a + solution->pos_b);
	else
		return (solution->size_b - solution->pos_b + solution->pos_a);
}

static void	find_cheapest(t_solutions *solution, t_node **a, t_node **b)
{
	t_node	*temp;
	int		cur;
	int		move;
	int		i;

	temp = *b;
	cur = temp->content;
	solution->num = cur;
	solution->move = find_least_moves(solution, a, b, cur);
	i = -1;
	if (solution->move == 0 || solution->move == 1 || get_size(*b) <= 2)
		return ;
	while (++i < get_size(*b))
	{
		temp = temp->next;
		cur = temp->content;
		move = find_least_moves(solution, a, b, cur);
		if (move < solution->move)
		{
			solution->num = cur;
			solution->move = move;
		}
	}
}

void	find_best_solution(t_solutions *solution, t_node **a, t_node **b)
{
	int	i;
	int	j;

	solution->pos_a = find_position((*a), solution->num);
	solution->pos_b = get_position_b((*b), solution->num);
	solution->size_a = get_size(*a);
	solution->size_b = get_size(*b);
	i = solution->pos_a;
	j = solution->pos_b;
	if (i >= j && solution->move == i)
		solution->sol = RR_RA;
	else if (i <= j && solution->move == j)
		solution->sol = RR_RB;
	else if (i >= j && solution->move == solution->size_a - i + j)
		solution->sol = RRA_RB;
	else if (i <= j && solution->move == solution->size_b - j + i)
		solution->sol = RA_RRB;
	else if (solution->move == solution->size_a - i)
		solution->sol = RRR_RRA;
	else
		solution->sol = RRR_RRB;
}

void	ps_sort_big(int size, char **numbers, t_node **a, t_node **b)
{
	int			median;
	t_solutions	*solution;

	solution = malloc(sizeof (t_solutions));
	if (!solution)
		exit_error();
	median = find_median(size, numbers);
	push_until_three(size, median, a, b);
	while ((*b))
	{
		find_cheapest(solution, a, b);
		find_best_solution(solution, a, b);
		do_best_solution(solution, a, b);
	}
	sort_a(a);
	free(solution);
}
