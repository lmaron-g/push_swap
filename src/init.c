#include "libft.h"
#include "push_swap.h"

t_stack		*stack_init(int id, int lenght, int mid, int debug)
{
	t_stack	*stack;

	if (!(stack = (t_stack*)ft_memalloc(sizeof(t_stack))))
		print_error(ERR_STACK_INIT);
	if (!(stack->stack = (int*)ft_memalloc(sizeof(int)*lenght)))
		print_error(ERR_STACK_INIT);
	stack->lenght = lenght;
	stack->debug = debug;
	stack->id = id;
	return (stack);
}

void		stack_free(t_stack **a)
{
	if (!(a && *a))
		return ;
	if ((*a)->lenght != 0)
	{
		(*a)->lenght = 0;
		(*a)->debug = 0;
		(*a)->id = 0;
		free((*a)->stack);
		free(*a);
	}
	*a = 0;
}