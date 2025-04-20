/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:16:21 by merilhan          #+#    #+#             */
/*   Updated: 2025/04/20 19:18:37 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_list *list)
{
	int	i;
	int	swap;
	int	len;

	i = 0;
	len = list->size_a;
	while (i < len)
	{
		list->copy_a[i] = list->a[i];
		i++;
	}
	i = 0;
	while (i < len - 1)
	{
		if (list->copy_a[i] > list->copy_a[i + 1])
		{
			swap = list->copy_a[i];
			list->copy_a[i] = list->copy_a[i + 1];
			list->copy_a[i + 1] = swap;
			i = -1;
		}
		i++;
	}
	return ;
}

void	number_sort(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < list->size_a)
	{
		j = 0;
		while (j < list->size_a)
		{
			if (list->a[i] == list->copy_a[j])
				list->copy_a_index[i] = j;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < list->size_a)
	{
		list->a[i] = list->copy_a_index[i];
		i++;
	}
	return ;
}

void	size_sort(t_list *list)
{
	if (list->size_a <= 5)
	{
		sort_little(list);
		return ;
	}
	bubble_sort(list);
	number_sort(list);
	list->max_bit = bit_counter(list);
	radix(list);
	return ;
}

void	init_memory(char **av, int is_av)
{
	t_list	list;

	if (is_av == 1)
		list.value = av;
	else
		list.value = NULL;
	list.size_a = ft_avlen(av);
	list.a = malloc(sizeof(int) * list.size_a);
	if (!list.a)
		safe_exit(&list);
	list.b = malloc(sizeof(int) * list.size_a);
	if (!list.b)
		safe_exit(&list);
	list.copy_a = malloc(sizeof(int) * list.size_a);
	if (!list.copy_a)
		safe_exit(&list);
	list.copy_a_index = malloc(sizeof(int) * list.size_a);
	if (!list.copy_a_index)
		safe_exit(&list);
	list.size_b = 0;
	check_av(&list, av);
	free_list(&list);
	return ;
}

void	check_av(t_list *list, char **av)
{
	int			i;
	long int	value;

	i = 0;
	if (is_number(av) == 1)
		safe_exit(list);
	while (av[i])
	{
		value = ft_atoi(av[i]);
		if ((value == 0 && av[i][0] == '-') || (value == 3000000))
			safe_exit(list);
		if ((value > 2147483647 || value < -2147483648))
			safe_exit(list);
		else
			list->a[i] = value;
		i++;
	}
	if (dup_control(list) == 1)
		safe_exit(list);
	if (queue_control(list))
		return ;
	size_sort(list);
	return ;
}
