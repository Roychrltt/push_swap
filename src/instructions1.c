/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:29:14 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/20 13:51:57 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_sa(t_node **a)
{
	ps_s(a);
	ft_putstr_fd("sa\n", 1);
}

void	ps_sb(t_node **b)
{
	ps_s(b);
	ft_putstr_fd("sb\n", 1);
}

void	ps_ss(t_node **a, t_node **b)
{
	ps_s(a);
	ps_s(b);
	ft_putstr_fd("ss\n", 1);
}

void	ps_ra(t_node **a)
{
	ps_r(a);
	ft_putstr_fd("ra\n", 1);
}

void	ps_rb(t_node **b)
{
	ps_r(b);
	ft_putstr_fd("rb\n", 1);
}
