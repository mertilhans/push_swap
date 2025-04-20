/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:20:46 by merilhan          #+#    #+#             */
/*   Updated: 2025/04/20 19:21:04 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list)
{
	int	tmp;

	tmp = list->a[0];
	list->a[0] = list->a[1];
	list->a[1] = tmp;
	ft_putstr("sa\n");
	return ;
}

void	sb(t_list *list)
{
	int	tmp;

	tmp = list->b[0];
	list->b[0] = list->b[1];
	list->b[1] = tmp;
	ft_putstr("sb\n");
	return ;
}

void	ra(t_list *list)
{
	int	tmp;
	int	index;

	index = 0;
	tmp = list->a[index];
	index++;
	while (index < list->size_a)
	{
		list->a[index - 1] = list->a[index];
		index++;
	}
	list->a[list->size_a - 1] = tmp;
	ft_putstr("ra\n");
	return ;
}

void	rb(t_list *list)
{
	int	tmp;
	int	index;

	index = 0;
	tmp = list->b[index];
	index++;
	while (index < list->size_b)
	{
		list->b[index - 1] = list->b[index];
		index++;
	}
	list->b[list->size_b - 1] = tmp;
	ft_putstr("rb\n");
	return ;
}
