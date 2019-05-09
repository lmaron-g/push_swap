#include "libft.h"
#include "push_swap.h"

/*
** TODO: 
**			else if (a->lenght < 20)
**				sort_twenty(a, b);
*/

void	sort_three(t_stack *a, t_stack *b)
{
	int	index;

	index = index_max(a->stack, a->lenght);
	if (index == 0)
		rotate(a, b);
	if (index == 1)
		rotate_rev(a, b);
	if (!is_sorted(a))
		swap(a, b);
}

void	half_to_b(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	mid(a);
	i = a->lenght;
	while (i >= 0)
	{
		if (a->stack[0] < a->mid)
			push(a, b);
		else
			rotate(a, b);
		i--;
	}
}

void	mover(t_stack *a, t_stack *b, int move)
{
	int	i;

	i = 0;
	if (move > 0)
		while (i++ < move)
			rotate(a, b);
	if (move < 0)
		while (i-- > move)
			rev_rotate(a, b);
}

void	like_selection_sort(t_stack *a, t_stack *b)
{
	int	move;
	int	index;

	move = MAX_INT;
	index = index_max(b->stack, b->lenght);
	if (index <= b->lenght - index)
		move = index;
	else 
		move = -1 * (b->lenght - index);
	mover(b, a, move);
}

void	half_to_a(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	mid(b);
	i = b->lenght;
	while (i >= 0)
	{
		if (b->stack[0] >= b->mid)
			push(b, a);
		else
		{
			if (is_previous(a, b, a->stack[a->lenght - 1], b->stack[0]) ||
				b->stack[0] == a->min)
			{
				push(b, a);
				rotate(a, b);
			}
			else
				rotate(b, a);
		}
		i--;
	}
}

void	return_back(t_stack *a, t_stack *b)
{
	if (b->lenght == 0)
		return ;
	if (b->lenght <= 13)
		like_selection_sort(a, b);
	half_to_a(a, b);
	return_back(a, b);

}

void	sort_quickly(t_stack *a, t_stack *b)
{
	half_to_b(a, b);
	return_back(a, b);
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