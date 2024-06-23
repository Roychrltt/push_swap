/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:25:32 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/21 18:37:32 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	partition(int *tab, int start, int end)
{
	int	pivot;
	int	start_tab;

	start_tab = start;
	pivot = tab[start];
	start++;
	while (start <= end)
	{
		while (start <= end && tab[start] < pivot)
			start++;
		while (start <= end && tab[end] > pivot)
			end--;
		if (start < end)
			swap(tab + start, tab + end);
	}
	swap(tab + start_tab, tab + end);
	return (end);
}

void	quick_sort(int *tab, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(tab, start, end);
		quick_sort(tab, start, pivot_index - 1);
		quick_sort(tab, pivot_index + 1, end);
	}
}

int	find_median(int size, char **numbers)
{
	int	i;
	int	*tab;
	int	median;

	tab = malloc(sizeof (int) * (size));
	if (!tab)
		exit_error();
	i = 0;
	while (i < size)
	{
		tab[i] = ps_atoi(numbers[i]);
		i++;
	}
	quick_sort(tab, 0, i - 1);
	median = tab[i / 2];
	free(tab);
	return (median);
}

int	find_smallest(int size, char **numbers)
{
	int	i;
	int	*tab;
	int	smallest;

	tab = malloc(sizeof (int) * (size));
	if (!tab)
		exit_error();
	i = 0;
	while (i < size)
	{
		tab[i] = ps_atoi(numbers[i]);
		i++;
	}
	smallest = tab[--i];
	while (i--)
	{
		if (smallest > tab[i])
			smallest = tab[i];
	}
	free(tab);
	return (smallest);
}
