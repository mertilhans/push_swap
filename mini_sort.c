/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:20:19 by merilhan          #+#    #+#             */
/*   Updated: 2025/04/20 19:20:27 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	three_sort(t_list *list)
{
	if (list->a[1] > list->a[0] && list->a[1] > list->a[2])
		rra(list);
	else if (list->a[0] > list->a[1] && list->a[0] > list->a[2])
		ra(list);
	if (list->a[0] > list->a[1])
		sa(list);
	return (1);
}

static int	find_min(t_list *list)
{
	int		min;
	int		index;
	size_t	min_index;

	index = 0;
	min = INT_MAX;
	min_index = 0;
	while (index < list->size_a)
	{
		if (list->a[index] < min)
		{
			min = list->a[index];
			min_index = index;
		}
		index++;
	}
	return (min_index);
}

static void	move_min_to_b(t_list *list, int min_index)
{
	if (min_index == 1)
		sa(list);
	else if (min_index == 2)
	{
		ra(list);
		sa(list);
	}
	else if (min_index == 3 && list->size_a == 4)
		rra(list);
	else if (min_index == 3 && list->size_a == 5)
	{
		rra(list);
		rra(list);
	}
	else if (min_index == 4)
		rra(list);
	if (queue_control(list) == 0)
		pb(list);
}

void	sort_little(t_list *list)
{
	if (list->size_a == 5)
		move_min_to_b(list, find_min(list));
	if (list->size_a == 4 || list->size_a == 5)
		move_min_to_b(list, find_min(list));
	three_sort(list);
	while (list->size_b > 0)
		pa(list);
}
