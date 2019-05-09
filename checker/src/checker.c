#include "checker.h"
#include "push_swap.h"
#include "libft.h"

void		is_sorts(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	if (b->lenght)
		print_error(ERR_CHECKER);
	while (++i < a->lenght)
		if (a->stack[i - 1] > a->stack[i])
			print_error(ERR_CHECKER);
	print_error(CHECKER_OK);
}

static void	apply_instructions_sp(t_stack **a, t_stack **b, char *line)
{
	if (ft_strequ(line, "pa"))
		push(b, a);
	else if (ft_strequ(line, "pb"))
		push(a, b);
	else if (ft_strequ(line, "sa"))
		swap(*a, *b);
	else if (ft_strequ(line, "sb"))
		swap(*b, *a);
	else if (ft_strequ(line, "ss"))
	{
		swap(*a, *b);
		swap(*b, *a);
	}
	else
		print_error(CHECKER_INVAL);
}

static void	apply_insrtuctions_r(t_stack **a, t_stack **b, char *line)
{
	if (ft_strequ(line, "ra"))
		rotate(*a, *b);
	else if (ft_strequ(line, "rb"))
		rotate(*b, *a);
	else if (ft_strequ(line, "rra"))
		rotate_rev(*a, *b);
	else if (ft_strequ(line, "rrb"))
		rotate_rev(*b, *a);
	else if (ft_strequ(line, "rr"))
	{	
		rotate(*a, *b);
		rotate(*b, *a);
	}
	else if (ft_strequ(line, "rrr"))
	{
		rotate_rev(*a, *b);
		rotate_rev(*b, *a);
	}
	else
		print_error(CHECKER_INVAL);
}

void		checker(t_stack **a, t_stack **b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (*line == 's' || *line == 'p')
			apply_instructions_sp(a, b, line);
		else if (*line == 'r')
			apply_insrtuctions_r(a, b, line);
		else if (ft_strequ(line, ""))
			break ;
		else
			print_error(CHECKER_INVAL);
		ft_strdel(&line);
	}
	is_sorts(a, b);
}