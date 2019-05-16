#include "libft.h"
#include "push_swap.h"

void	sort_three(t_stack *a, int order)
{
	int	index;

	index = order ? index_min(a) : index_max(a) ;
	if (index == 0 && a->lenght == 3)
		rotate(a);
	if (index == 1 && a->lenght == 3)
		rotate_rev(a);
	if ((!order && a->stack[0] > a->stack[1]) ||
		(order && a->stack[0] < a->stack[1]))
		swap(a);
}