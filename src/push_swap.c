#include "libft.h"
#include "push_swap.h"

/*
** TODO: 
**			else if (a->lenght < 20)
**				sort_twenty(a, b);
**
**			fix mid();
*/

void	like_selection_sort(t_stack *a, t_stack *b)
{
	int	index;

	index = index_max(b->stack, b->lenght);
	if (index == 0)
		push(b, a);
	else if (PUSH_BACK)
	{
		push(b, a);
		rotate(a, b);
	}
	else if (index <= b->lenght - index)
		rotate(b, a);
	else 
		rotate_rev(b, a);
}

void	half_to_a(t_stack *a, t_stack *b)
{
	int	i;

	mid(b);
	i = b->lenght + 1;
	while (i >= 0)
	{
		if (b->lenght < 13)
			like_selection_sort(a, b);
		else if (b->stack[0] > b->mid)
			push(b, a);
		else if (PUSH_BACK)
		{
			push(b, a);
			rotate(a, b);
		}
		else
			rotate(b, a);
		i--;
	}
}

void	half_to_b(t_stack *a, t_stack *b)
{
	int	i;

	mid(a);
	i = a->lenght;
	while (i >= 0)
	{
		if (a->stack[0] <= a->mid)
			push(a, b);
		else
			rotate(a, b);
		i--;
	}
}

void	return_back(t_stack *a, t_stack *b);

void	part_to_b(t_stack *a, t_stack *b, int divider)
{
	if (divider <= a->stack[a->lenght - 1])
		return ;
	while (a->stack[0] != divider)
	{
		if (is_previous(a, b, a->stack[a->lenght - 1], a->stack[0]))
			rotate(a, b);
		else
			push(a, b);
	}
	if (is_previous(a, b, a->stack[a->lenght - 1],
		find_min(b->stack, b->lenght)))
		return_back(a, b);
}

void	return_back(t_stack *a, t_stack *b)
{
	int	divider;
	
	if (b->lenght == 0)
		return ;
	divider = a->stack[0];
	half_to_a(a, b);
	while (SORT_PART)
		rotate(a, b);
	return_back(a, b);
	part_to_b(a, b, divider);
}

void	sort_quickly(t_stack *a, t_stack *b)
{
	half_to_b(a, b);
	return_back(a, b);
	part_to_b(a, b, a->stack[(a->lenght - 1) / 2]);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->lenght < 4)
		sort_three(a, b);
	else
		sort_quickly(a, b);
}




























/*
void	mover(t_stack *a, t_stack *b, int move)
{
	int	i;

	i = 0;
	if (move > 0)
		while (i++ < move)
			rotate(a, b);
	if (move < 0)
		while (i-- > move)
			rotate_rev(a, b);
}
*/