/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:22:33 by merilhan          #+#    #+#             */
/*   Updated: 2025/04/20 20:00:46 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	single_av(char *av)
{
	char	**value;

	if (ispace(av))
	{
		ft_putstr("Error\n");
		return (0);
	}
	value = ft_split(av, 32);
	if (!value)
	{
		ft_putstr("Error\n");
		return (1);
	}
	init_memory(value, 1);
	free_mem(value);
	return (0);
}

// int	multiple_av(char **av)
// {
//     if (ispace(*av))
//     {
//         ft_putstr("Error\n");
//         return (0);
//     }
//     av++;
// 	init_memory(av, 0);
// 	return (0);
// }

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ac == 2)
			return (single_av(av[1]));
		else
        {
            char **str;
            str = av;
            while(*str)
            {
                if(ispace(*str))
                {
                    ft_putstr("Error\n");
		            return (1);
                }
                str++;
            }
            av++;
			init_memory(av,0);
        }
	}
	return (0);
}
