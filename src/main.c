#include "libft.h"
#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac > 2)
	{
		a = argument_read(ac, av);
		for (int i = 0; i < a->lenght; i++)
		{
			ft_printf("%d\n", a->stack[i]);
		}
	}
	else
		print_error(ERR_PUSH_USAGE);
	return 0;
}
