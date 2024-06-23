/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:54:21 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/19 21:54:12 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_ss_silent(t_node **a, t_node **b)
{
	ps_s(a);
	ps_s(b);
}

void	ps_rr_silent(t_node **a, t_node **b)
{
	ps_r(a);
	ps_r(b);
}

void	ps_rrr_silent(t_node **a, t_node **b)
{
	ps_rrx(a);
	ps_rrx(b);
}
