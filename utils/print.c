#include "struct_def.h"

void	print_input(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->len)
	{
		ft_putnbr_fd(all->insort[i]->ri, 1);
		ft_putstr_fd(" -> ", 1);
		ft_putnbr_fd(all->in[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	print_stack(t_ilst *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putnbr_fd(lst->n, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
	}
}
