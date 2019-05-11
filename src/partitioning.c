#include "libft.h"
#include "push_swap.h"

static void	like_selection_sort(t_stack *a, t_stack *b)
{
	int		index;

	index = index_max(b);
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

void		half_to_a(t_stack *a, t_stack *b)
{
	int		i;

	mid(b);
	i = b->lenght;
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

void		half_to_b(t_stack *a, t_stack *b)
{
	int		i;

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

void		part_to_b(t_stack *a, t_stack *b, int divider)
{
	if (divider != a->min && divider <= a->stack[a->LAST])
		return ;
	while (a->stack[0] != divider)
	{
		if (is_previous(a, b, a->stack[a->LAST], a->stack[0]))
			rotate(a, b);
		else
			push(a, b);
	}
	if (is_previous(a, b, a->stack[a->LAST], find_min(b)))
		return_back(a, b);
}