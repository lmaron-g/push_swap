#include "libft.h"

/*
** is sub_number previous for main_number in two stacks?
*/
int		is_previous(t_stack *a, t_stack *b, int sub, int main)
{
	int	i;
	int	min;
	int	dif;

	i = 0;
	min = main - sub;
	if (min == 1)
		return (1);
	while (i < a->lenght)
	{
		dif = main - a->stack[i];
		if (dif > 0)
			if (dif < min)
				return (0);
		i++;
	}
	i = 0;
	while (i < b->lenght)
	{
		dif = main - b->stack[i];
		if (dif > 0)
			if (dif < min)
				return (0);
		i++;
	}
	return (1);
}