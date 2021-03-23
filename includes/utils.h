#ifndef UTILS_H
# define UTILS_H

# include "struct_def.h"

void	insert_input(t_all *all, int ac, char **av);
void	init_input(t_all *all);
void	sort_input(t_all *all);
void	print_input(t_all *all);
void	print_stack(t_ilst *lst);
void	fill_stack_a(t_all *all);
void	exit_all(t_all *all);
void	exit_error(t_all *all);
int		min(int a, int b);
t_ilst	**ft_realloc_arr(t_ilst **in, size_t n);
void	clear_lists(t_all *all);
#endif
