/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:06:51 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/23 14:23:18 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	is_valid_number(char **numbers)
{
	size_t	i;
	size_t	j;
	char	*cur;

	i = 0;
	while (numbers[i])
	{
		cur = numbers[i];
		j = 0;
		while (cur[j])
		{
			if (!ft_isdigit(cur[j]) && !(j == 0 && (cur[j] == '-'
						|| cur[j] == '+')))
			{
				exit_error();
			}
			j++;
		}
		i++;
	}
}

int	ps_atoi(char *str)
{
	long	result;
	int		sign;
	size_t	i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if ((sign == 1 && (result > (INT_MAX - str[i] + '0') / 10))
			|| (sign == -1 && (result * sign < (INT_MIN + str[i] - '0') / 10)))
			exit_error();
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	is_duplicated(char **numbers)
{
	int	i;
	int	j;

	i = 1;
	while (numbers[i])
	{
		j = 0;
		while (j < i)
		{
			if (ps_atoi(numbers[j]) == ps_atoi(numbers[i]))
				exit_error();
			j++;
		}
		i++;
	}
}
