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

static t_stack	*argument_convert(char *line, int ac, char **av, t_stack *a)
{
	int			debug;
	int			*stack;

	debug = 0;
	ac = count_words(line, ' ');
	if (!ft_strlen(line) || !ac)
		print_error(ERR_INVALID);
	if (!(av = ft_strsplit(line, ' ')))
		print_error(ERR_INVALID);
	if (ft_strequ(*av, "-v"))
	{
		debug = 1;
		av++;
		ac--;
	}
	a = stack_init(0, ac, 0, debug);
	ac = 0;
	while (*av)
	{
		if (!ft_isnumber_base(*av, 10))
			print_error(ERR_INVALID);
		a->stack[ac++] = ft_atoi(*(av++));
	}
	return(a);
}

t_stack			*argument_read(int ac, char **av)
{
	int			i;
	t_stack		*a;
	char		*arg_line;

	i = 0;
	arg_line = argument_merge(ac, av);
	a = argument_convert(arg_line, ac, av, a);
	if (duplicates(a->stack, a->lenght))
		print_error(ERR_INVALID);
	a->min = ft_find_min(a->stack, a->lenght);
	a->max = ft_find_max(a->stack, a->lenght);
	return (a);
}