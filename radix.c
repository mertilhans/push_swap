/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:16:10 by merilhan          #+#    #+#             */
/*   Updated: 2025/04/20 19:23:24 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	radix_b(t_list *list, int i, int b_size, int max_bit)
{
	while (b_size-- && i <= max_bit)
	{
		if (((list->b[0] >> i) & 1) == 0)
			rb(list);
		else
			pa(list);
	}
	return ;
}

int	radix_a(t_list *list, int i)
{
	if (queue_control(list))
		return (1);
	else
	{
		if (((list->a[0] >> i) & 1) == 0)
			pb(list);
		else
			ra(list);
	}
	return (1);
}

int	radix(t_list *list)
{
	int	i;
	int	j;
	int	size;
	int	b_size;

	i = 0;
	j = 0;
	while (i <= list->max_bit)
	{
		j = 0;
		size = list->size_a;
		while (j < size)
		{
			radix_a(list, i);
			j++;
		}
		i++;
		b_size = list->size_b;
		radix_b(list, i, b_size, list->max_bit);
	}
	while (list->size_b)
		pa(list);
	return (0);
}
