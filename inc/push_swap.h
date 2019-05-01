#ifndef PUSH_SWAP
# define PUSH_SWAP

#define ERR_PUSH_USAGE "Usage: ./push_swap [-v] [STACK]"
#define ERR_CHECKER_USAGE "Usage: ./checker [-v] [STACK]"
#define ERR_STACK_INIT "Initialization error: stack_init();"
#define ERR_INVALID "Invalid stack"

typedef struct	s_stack
{
	int			id;
	int			mid;
	int			debug;
	int			lenght;
	int			*stack;
}				t_stack;

t_stack			*argument_read(int ac, char **av);
t_stack			*stack_init(int id, int lenght, int debug);

#endif
