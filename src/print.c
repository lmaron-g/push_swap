#include "libft.h"
#include "push_swap.h"

void	stack_print(t_stack a, t_stack b)
{
	int	i;
	int	end;

	end = FT_MAX(a.lenght, b.lenght);
	i = end;
	if (a.lenght == 0)
		a.lenght = -1;
	if (b.lenght == 0)
		b.lenght = -1;
	while (i >= 0)
	{
		if (i <= a.LAST && i > b.LAST)
			ft_printf("%8d %8c\n", a.stack[a.lenght - i - 1], ' ');
		if (i > a.LAST && i <= b.LAST)
			ft_printf("%8c %8d\n", ' ', b.stack[b.lenght - i - 1]);
		if (i <= a.LAST && i <= b.LAST)
			ft_printf("%8d %8d\n", a.stack[a.lenght - i - 1], 
									b.stack[b.lenght - i - 1]);
		i--;
	}
}