#include "libft.h"
#include "push_swap.h"

static char	*argument_merge(int ac, char **av)
{
	int		i;
	char	*args;

	i = 2;
	args = ft_strdup(av[1]);
	while (i < ac)
		ft_catarg(&args, av[i++]);
	return (args);
}

static void	convert_args(char *line, int ac, char **av, t_stack *a)
{
	int		i;
	int		debug;
	int		*stack;

	i = 0;
	debug = 0;
	ac = count_words(line, ' ');
	if (!ft_strlen(line) || !ac)
		print_error(ERR_INVALID);
	if (!(av = ft_strsplit(line, ' ')))
		print_error(ERR_INVALID);
	if (!ft_strequ(*av, "-v"))
	{
		debug = 1;
		av++;
		ac--;
	}
	a = stack_init(0, ac, debug);
	while (av)
	{
		if (!ft_isnumber_base(*av, 10))
			print_error(ERR_INVALID);
		a->stack[i++] = ft_atoi(*(av++));
	}
}

t_stack		*argument_read(int ac, char **av)
{
	int		i;
	t_stack	*a;
	char	*arg_line;

	i = 0;
	arg_line = argument_merge(ac, av);
	convert_args(arg_line, ac, av, a);
	if (duplicates(a->stack, a->lenght))
		print_error(ERR_INVALID);
	return (a);
}