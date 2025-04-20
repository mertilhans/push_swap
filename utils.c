/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:16:16 by merilhan          #+#    #+#             */
/*   Updated: 2025/04/20 19:24:19 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	if (!*str)
		write(1, "error", 5);
	while (*str)
		write(1, str++, 1);
}

char	**free_mem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	free_list(t_list *list)
{
	if (list == NULL)
		return ;
	if (list->a != NULL)
	{
		free(list->a);
		list->a = NULL;
	}
	if (list->b != NULL)
	{
		free(list->b);
		list->b = NULL;
	}
	if (list->copy_a != NULL)
	{
		free(list->copy_a);
		list->copy_a = NULL;
	}
	if (list->copy_a_index != NULL)
	{
		free(list->copy_a_index);
		list->copy_a_index = NULL;
	}
	return ;
}

void	safe_exit(t_list *list)
{
	ft_putstr("Error\n");
	free_list(list);
	if (list->value)
		free_mem(list->value);
	exit(0);
}

int	ft_avlen(char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (av[j])
	{
		i++;
		j++;
	}
	return (i);
}
