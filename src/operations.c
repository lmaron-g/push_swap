#include "libft.h"
#include "push_swap.h"

void	swap(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->lenght > 1)
	{
		tmp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = tmp;
	}
}

void		push(t_stack **a, t_stack **b)
{
	int		i;
	t_stack *a_new;
	t_stack *b_new;

	i = 0;
	if ((*a)->lenght > 0)
	{
		a_new = stack_init((*a)->id, (*a)->lenght - 1, (*a)->mid, (*a)->debug);
		b_new = stack_init((*b)->id, (*b)->lenght + 1, (*b)->mid, (*b)->debug);
		while (++i < (*a)->lenght)
			a_new->stack[i - 1] = (*a)->stack[i];
		b_new->stack[0] = (*a)->stack[0];
		i = 0;
		while (++i < (*b)->lenght + 1)
			b_new->stack[i] = (*b)->stack[i - 1];
		stack_free(a);
		stack_free(b);
		*a = a_new;
		*b = b_new;
	}
}

void	rotate(t_stack *a, t_stack *b)
{
	int		i;
	int		change;

	i = 0;
	change = a->stack[0];
	while (i < a->lenght - 1)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = change;
}

void		rotate_rev(t_stack *a, t_stack *b)
{
	int		i;
	int		change;

	i = a->lenght - 1;
	change = a->stack[i];
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[i] = change;
}