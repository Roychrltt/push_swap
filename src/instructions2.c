/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:29:14 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/20 13:52:17 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_pa(t_node **b, t_node **a)
{
	ps_p(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	ps_pb(t_node **a, t_node **b)
{
	ps_p(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	ps_rr(t_node **a, t_node **b)
{
	ps_r(a);
	ps_r(b);
	ft_putstr_fd("rr\n", 1);
}

void	ps_rra(t_node **a)
{
	ps_rrx(a);
	ft_putstr_fd("rra\n", 1);
}

void	ps_rrb(t_node **b)
{
	ps_rrx(b);
	ft_putstr_fd("rrb\n", 1);
}
