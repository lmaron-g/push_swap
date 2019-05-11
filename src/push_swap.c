#include "libft.h"
#include "push_swap.h"

/*
** TODO: 
**			else if (a->lenght < 20)
**				sort_twenty(a, b);
**
*/

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
	part_to_b(a, b, a->min);
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