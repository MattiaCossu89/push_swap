#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "glob_func.h"

void	compute_sorting(t_all *all);
void	find_max_sub_rev(t_all *all);
t_ilst	**ft_realloc_arr(t_ilst **in, size_t n);
void	set_stacks(t_all *all);
void	sort(t_all *all);

#endif
