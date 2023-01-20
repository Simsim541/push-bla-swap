/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:53:11 by mberri            #+#    #+#             */
/*   Updated: 2023/01/19 19:53:11 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int print_error(int x)
{
    if(x >= 1)
        write(1, "Error\n", 6);
    exit(1);
    return(-1);
}

numbers *ft_stack_new(void)
{
    numbers *new_alloc;

    new_alloc = NULL;
    new_alloc = (numbers*)malloc(sizeof(numbers));
    new_alloc->prev = NULL;
    new_alloc->number = 0;
    new_alloc->next = NULL;
    return(new_alloc);
}

data    *ft_data_new(void)
{
    numbers *stack_a;
    data    *new_data;

    new_data = NULL;
    new_data =(data *)malloc(sizeof(data));
    stack_a = ft_stack_new();
    new_data->array = NULL;
    new_data->size_a = 0;
    new_data->top_a = stack_a;
    new_data->bottom_a = stack_a;
    new_data->size_b = 0;
    return(new_data);    
}

void    ft_check(int *array, int size)
{
    int i;
    int j;

    i = 0;
    while(i < size - 1)
    {
        j = i + 1;
        while (array[j])
        {
            if (array[i] == array[j])
                print_error(1);
            j++;
        }
        i++;
    }
}

int main(int ac, char *av[])
{
    int array_size;
    int *array_nbr;
    data    *data;

    if(ac < 2)
        print_error(-1);
    array_size = 0;
    data = ft_data_new();
    array_size = get_str_size(ac, av);
    array_nbr = ft_av_to_array(ac, av, array_size);
    ft_check(array_nbr, array_size);
    ft_arr_to_stack(data, array_nbr, array_size);
    ft_check_array_sort(array_nbr, array_size, 0);
    data->array = (int *)array_nbr;
    ft_sort(data);
    return(0);
}