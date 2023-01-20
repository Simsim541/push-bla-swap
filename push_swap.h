/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:46:41 by mberri            #+#    #+#             */
/*   Updated: 2023/01/19 19:46:41 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct t_numbers
{
    struct t_numbers *prev;
    int     number;
    struct t_numbers *next;
}numbers;

typedef struct t_data
{
    int *array;
    int size_a;
    numbers *top_a;
    numbers *bottom_a;
    int size_b;
    numbers *top_b;
    numbers *bottom_b;
}data;

int     ft_isspace(char c);
int     ft_isdigit(int c);
void    ft_check(int *array, int size);
static int	count_words(char const *s, char c);
static int	words_len(char const *s, char c);
static char	**ft_free(char **split, int i);
static char	**splitfill(char const *s, int words, char c, char **splitted);
char	**ft_split(char	const *s, char c);
void    ft_free_str(char **str);
int     print_error(int x);
data    *ft_data_new(void);
numbers *ft_stack_new(void);
int     ft_atoil(const char *str);
void    set_str_to_array(int *array, int *arr_index, char **str);
int     get_str_size(int ac, char *av[]);
int     get_split_str_size(char **split_str);
int     *ft_av_to_array(int ac, char *av[], int size);
void    ft_arr_to_stack(data *info, int *array, int size);
void    ft_check_array_sort(int *array, int size, int index);
void    ra(data *info);
void    rb(data *info);
void    rr(data *info);
void    rra(data *info);
void    rrb(data *info);
void    rrr(data *info);
void    sa(data *info);
void    sb(data *info);
void    ss(data *info);
void    pa(data *info);
void    pb(data *info);
void    ft_sort(data *info);
void	ft_sort_three(data *info);
void	ft_big_sort(data *info);
int     set_a_location(int num, data *info);
void	get_min_rotate(data *info, int *a, int *b);
void	ft_sort_big_last(data *info);
void	ft_sort_3div_insruct(data *info, int pivot1, int pivot2);
void	ft_sort_three_division(data *info);
int     ft_get_bigger(int a, int b, int a_loc, int b_loc);
void	ft_rotate_same(data *info, int *a, int *b);
void    ft_rotate_a(data *info, int a);
void    ft_rotate_b(data *info, int b);
int     get_stack_min(numbers *stack);
int     set_a_location_min(data *info);
int     get_stack_max(numbers *stack);
int     set_a_location_max(data *info);
int     set_a_location_mid(int num, data *info);

#endif