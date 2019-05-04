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

void		push(t_stack *a, t_stack *b)
{
	int		i;
	int		*a_new;
	int		*b_new;

	i = 0;
	if (a->lenght > 0)
	{
		if (!(a_new = (int*)ft_memalloc(sizeof(int) * --a->lenght)))
			print_error(ERR_STACK_INIT);
		if (!(b_new = (int*)ft_memalloc(sizeof(int) * ++b->lenght)))
			print_error(ERR_STACK_INIT);
		while (++i < a->lenght + 1)
			a_new[i - 1] = a->stack[i];
		b_new[0] = a->stack[0];
		i = 0;
		while (++i < b->lenght)
			b_new[i] = b->stack[i - 1];
		free(a->stack);
		free(b->stack);
		a->stack = a_new;
		b->stack = b_new;
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