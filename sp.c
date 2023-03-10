#include "push_swap.h"

void	sa(data *info)
{
	int	tmp;

	if (info->size_a < 2)
	{
		return ;
	}
	tmp = info->top_a->number;
	info->top_a->number = info->top_a->next->number;
	info->top_a->next->number = tmp;
	write(1, "sa\n", 3);
}

void	sb(data *info)
{
	int	tmp;

	if (info->size_b < 2)
	{
		return ;
	}
	tmp = info->top_b->number;
	info->top_b->number = info->top_b->next->number;
	info->top_b->next->number = tmp;
	write(1, "sb\n", 3);
}

void	ss(data *info)
{
	int	tmp;

	if (info->size_a < 2)
	{
		return ;
	}
	if (info->size_b < 2)
	{
		return ;
	}
	tmp = info->top_a->number;
	info->top_a->number = info->top_a->next->number;
	info->top_a->next->number = tmp;
	tmp = info->top_b->number;
	info->top_b->number = info->top_b->next->number;
	info->top_b->next->number = tmp;
	write(1, "ss\n", 3);
}

void	pa(data *info)
{
	numbers	*tmp;

	if (info->size_b < 1)
		return ;
	tmp = info->top_b;
	if (info->size_b > 1)
	{
		info->top_b = info->top_b->next;
		info->top_b->prev = NULL;
	}
	if (info->size_a == 0)
	{
		tmp->next = NULL;
		info->top_a = tmp;
		info->bottom_a = tmp;
	}
	else
	{
		tmp->next = info->top_a;
		info->top_a->prev = tmp;
		info->top_a = tmp;
	}
	info->size_a += 1;
	info->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(data *info)
{
	numbers	*tmp;

	if (info->size_a < 1)
		return ;
	tmp = info->top_a;
	if (info->size_a > 1)
	{
		info->top_a = info->top_a->next;
		info->top_a->prev = NULL;
	}
	if (info->size_b == 0)
	{
		tmp->next = NULL;
		info->top_b = tmp;
		info->bottom_b = tmp;
	}
	else
	{
		tmp->next = info->top_b;
		info->top_b->prev = tmp;
		info->top_b = tmp;
	}
	info->size_a -= 1;
	info->size_b += 1;
	write(1, "pb\n", 3);
}