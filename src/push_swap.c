#include "libft.h"
#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b, int left, int right)
{
	int	i;

	i = 0;
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
