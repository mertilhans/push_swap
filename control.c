/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:16:31 by merilhan          #+#    #+#             */
/*   Updated: 2025/04/20 19:19:28 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ispace(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_number(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '-' || av[i][j] == '+') && j == 0)
				;
			else if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	queue_control(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (i < list->size_a - 1)
	{
		j = i + 1;
		while (j < list->size_a)
		{
			if (list->a[i] > list->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	bit_counter(t_list *list)
{
	int	bit_size;
	int	i;

	i = 0;
	bit_size = list->size_a;
	while (bit_size > 1)
	{
		bit_size /= 2;
		i++;
	}
	return (i);
}

int	dup_control(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (i < list->size_a - 1)
	{
		j = i + 1;
		while (j < list->size_a)
		{
			if (list->a[i] == list->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
