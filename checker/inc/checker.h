#ifndef CHECKER_H
# define CHECKER_H

#include "push_swap.h"

#define ERR_CHECKER "KO"
#define CHECKER_OK "OK!"
#define CHECKER_INVAL "ERROR"
#define ERR_CHECKER_USAGE "Usage: ./checker [-v] [STACK]"

void		checker(t_stack **a, t_stack **b);
void		is_sort(t_stack *a, t_stack *b);

#endif