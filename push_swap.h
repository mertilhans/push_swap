/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merilhan <merilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:29:49 by merilhan          #+#    #+#             */
/*   Updated: 2025/04/20 19:29:50 by merilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define INT_MAX 2147483647

typedef struct s_list
{
	int		*a;
	int		*b;
	int		*copy_a;
	int		*copy_a_index;
	int		size_a;
	int		size_b;
	int		max_bit;
	char	**value;
}			t_list;
void		pa(t_list *list);
void		pb(t_list *list);
void		ra(t_list *list);
void		rb(t_list *list);
void		sa(t_list *list);
void		sb(t_list *list);
void		rra(t_list *list);
void		ft_putstr(char *str);
void		free_list(t_list *list);
void		safe_exit(t_list *list);
void		bubble_sort(t_list *list);
void		number_sort(t_list *list);
void		size_sort(t_list *list);
void		init_memory(char **av, int is_av);
void		check_av(t_list *list, char **av);
int			ft_avlen(char **av);
int			radix(t_list *list);
int			dup_control(t_list *list);
int			bit_counter(t_list *list);
int			queue_control(t_list *list);
int			is_number(char **av);
int			ispace(char *s);
size_t		ft_strlen(const char *s);
long int	ft_atoi(char *str);
char		**ft_split(char const *s, char c);
char		**free_mem(char **arr);
void		sort_little(t_list *list);

#endif
