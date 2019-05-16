#include "libft.h"
#include "push_swap.h"

void	like_selection_sort(t_stack *a, t_stack *b)
{
	int		index;

	index = index_max(b);
	if (index == 0)
		push(b, a);
	else if (PUSH_BACK)
	{
		push(b, a);
		rotate(a);
	}
	else if (index <= b->lenght - index)
		rotate(b);
	else 
		rotate_rev(b);
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
		else if (((a->lenght + b->lenght) % 2 == 0 && b->stack[0] > b->mid) ||
				((a->lenght + b->lenght) % 2 == 1 && b->stack[0] >= b->mid))
			push(b, a);
		else if (PUSH_BACK)
		{
			push(b, a);
			rotate(a);
		}
		else
			rotate(b);
		i--;
	}
}

void		half_to_b(t_stack *a, t_stack *b)
{
	mid(a);
	while ((a->lenght / 2 != b->lenght / 2) &&
								a->lenght > 3)
	{
		if (((a->lenght + b->lenght) % 2 == 0 && a->stack[0] <= a->mid) ||
			((a->lenght + b->lenght) % 2 == 1 && a->stack[0] < a->mid))
			push(a, b);
		else
			rotate(a);
	}
	if (a->lenght == 3)
		sort_three(a, 0);
}

void		part_to_b(t_stack *a, t_stack *b, int divider)
{
	if (divider != a->min && divider <= a->stack[a->LAST])
		return ;
	while (a->stack[0] != divider)
	{
		if (is_previous(a, b, a->stack[a->LAST], a->stack[0]))
			rotate(a);
		else
			push(a, b);
	}
	if (is_previous(a, b, a->stack[a->LAST], find_min(b)))
		return_back(a, b);
}