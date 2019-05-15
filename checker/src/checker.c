#include "checker.h"
#include "push_swap.h"
#include "mlx.h"
#include "libft.h"

static void	is_sorts(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	if (b->lenght)
		termination(ERR_CHECKER, 1);
	while (++i < a->lenght)
		if (a->stack[i - 1] > a->stack[i])
			termination(ERR_CHECKER, 1);
	termination(CHECKER_OK, 1);
}

static void	apply_instructions_sp(t_stack *a, t_stack *b, char *line)
{
	if (ft_strequ(line, "pa"))
		push(b, a);
	else if (ft_strequ(line, "pb"))
		push(a, b);
	else if (ft_strequ(line, "sa"))
		swap(a);
	else if (ft_strequ(line, "sb"))
		swap(b);
	else if (ft_strequ(line, "ss"))
	{
		swap(a);
		swap(b);
	}
	else
		termination(CHECKER_INVAL, 1);
}

static void	apply_insrtuctions_r(t_stack *a, t_stack *b, char *line)
{
	if (ft_strequ(line, "ra"))
		rotate(a);
	else if (ft_strequ(line, "rb"))
		rotate(b);
	else if (ft_strequ(line, "rra"))
		rotate_rev(a);
	else if (ft_strequ(line, "rrb"))
		rotate_rev(b);
	else if (ft_strequ(line, "rr"))
	{	
		rotate(a);
		rotate(b);
	}
	else if (ft_strequ(line, "rrr"))
	{
		rotate_rev(a);
		rotate_rev(b);
	}
	else
		termination(CHECKER_INVAL, 1);
}

void		checker(t_stack *a, t_stack *b, t_fdf *fdf)
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
			termination(CHECKER_INVAL, 1);
		ft_strdel(&line);
		/*
		сюда
		*/
	}
	is_sorts(a, b);
}