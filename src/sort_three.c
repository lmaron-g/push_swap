#include "libft.h"
#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b)
{
	int	index;

	index = index_max(a);
	if (index == 0)
		rotate(a, b);
	if (index == 1)
		rotate_rev(a, b);
	if (!is_sorted(a))
		swap(a, b);
}