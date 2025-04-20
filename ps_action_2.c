/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:21:23 by merilhan          #+#    #+#             */
/*   Updated: 2025/04/20 19:22:23 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *list)
{
	int	tmp;
	int	i;

	i = 0;
	if (list->size_b > 0)
	{
		tmp = list->b[0];
		while (i < list->size_b - 1)
		{
			list->b[i] = list->b[i + 1];
			i++;
		}
		list->size_b--;
		i = list->size_a;
		while (i > 0)
		{
			list->a[i] = list->a[i - 1];
			i--;
		}
		list->a[0] = tmp;
		list->size_a++;
		ft_putstr("pa\n");
	}
	return ;
}

void	pb(t_list *list)
{
	int	tmp;
	int	i;

	i = 0;
	if (list->size_a > 0)
	{
		tmp = list->a[0];
		while (i < list->size_a - 1)
		{
			list->a[i] = list->a[i + 1];
			i++;
		}
		list->size_a--;
		i = list->size_b;
		while (i > 0)
		{
			list->b[i] = list->b[i - 1];
			i--;
		}
		list->b[0] = tmp;
		list->size_b++;
		ft_putstr("pb\n");
	}
	return ;
}

void	rra(t_list *list)
{
	int	i;
	int	temp;

	temp = list->a[list->size_a - 1];
	i = list->size_a - 1;
	while (i > 0)
	{
		list->a[i] = list->a[i - 1];
		i--;
	}
	list->a[i] = temp;
	ft_putstr("rra\n");
	return ;
}
