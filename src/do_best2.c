/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:59:38 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/23 13:13:56 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_ra_rrb(t_solutions *solution, t_node **a, t_node **b)
{
	int	i;
	int	j;

	i = solution->pos_a;
	j = solution->pos_b;
	if (j < get_size(*b) && j != 0)
	{
		while (j++ < get_size(*b))
			ps_rrb(b);
	}
	while (i--)
		ps_ra(a);
}
