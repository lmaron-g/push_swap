#include "libft.h"
#include "push_swap.h"

static char		*argument_merge(int ac, char **av)
{
	int			i;
	char		*args;

	i = 2;
	args = ft_strdup(av[1]);
	while (i < ac)
		ft_catarg(&args, av[i++]);
	return (args);
}

static t_stack	*argument_convert(char *line, int ac, char **av, int mode)
{
	int			debug;
	t_stack		*stack;

	debug = mode;
	ac = count_words(line, ' ');
	if (!ft_strlen(line) || !ac)
		print_error(ERR_INVALID);
	if (!(av = ft_strsplit(line, ' ')))
		print_error(ERR_INVALID);
	if (mode && ft_strequ(*av, "-v"))
	{
		debug = 2;
		av++;
		ac--;
	}
	stack = stack_init('a', ac, 0, debug);
	ac = 0;
	while (*av)
	{
		if (!ft_isnumber_base(*av, 10))
			print_error(ERR_INVALID);
		stack->stack[ac++] = ft_atoi(*(av++));
	}
	return(stack);
}

/*
** mode: 0 = push_swap; 1 = cheker;
*/
t_stack			*argument_read(int ac, char **av, int mode)
{
	int			i;
	t_stack		*a;
	char		*arg_line;

	i = 0;
	arg_line = argument_merge(ac, av);
	a = argument_convert(arg_line, ac, av, mode);
	if (duplicates(a->stack, a->lenght))
		print_error(ERR_INVALID);
	a->min = find_min(a);
	a->max = find_max(a);
	return (a);
}