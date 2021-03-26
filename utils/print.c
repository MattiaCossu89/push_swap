#include "checker.h"

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
	t_ilst *last;

	if (!lst)
		return ;
	last = lst->prev;
	while (lst != last)
	{
		ft_putnbr_fd(lst->n, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
	}
	ft_putnbr_fd(lst->n, 1);
	ft_putchar_fd('\n', 1);
}

void	print_line(t_all *all)
{
	int	i;

	i = 0;
	ft_putstr_fd("\t+", 1);
	while (i++ < all->maxnl + 2)
		ft_putchar_fd('-', 1);
	ft_putchar_fd('+', 1);
	i = 0;
	while (i++ < all->maxnl + 2)
		ft_putchar_fd('-', 1);
	ft_putstr_fd("+", 1);
	i = 0;
	while (i++ < all->maxnl + 2)
		ft_putchar_fd('-', 1);
	ft_putstr_fd("+\n", 1);
}

void	print_head(t_all *all)
{
	print_line(all);
	ft_printf("\t| %*s%*s | %*s%*s | %*s%*s |\n",
	all->maxnl / 2 + 1, "a", all->maxnl / 2, "",
	all->maxnl / 2 + 1, "b", all->maxnl / 2, "",
	all->maxnl / 2 + 1, "r", all->maxnl / 2, "");
	print_line(all);
}

void	mnm_a(t_all *all, t_ilst **min, t_ilst **max)
{
	t_ilst *it;
	t_ilst *f;

	f = all->a.ss;
	it = all->a.ss->next;
	*min = f;
	*max = f;
	while (it != f)
	{
		if (it->ri < (*min)->ri)
			*min = it;
		if (it->ri > (*max)->ri)
			*max = it;
		it = it->next;
	}
}

int		pos_a(t_all *all, t_ilst *tof)
{
	t_ilst	*f;
	t_ilst	*it;
	int		i;

	i = 0;
	f = all->a.ss->prev;
	it = all->a.ss;
	while (it != f)
	{
		if (it == tof)
			return (i);
		i++;
		it = it->next;
	}
	if (it != tof)
		return (-1);
	return (i);
}

void	print_sorted(t_all *all, int i)
{
	const char	*color;
	t_ilst		*min;
	t_ilst		*max;

	color = "";
	mnm_a(all, &min, &max);
	if (all->fc)
	{
		if ((all->insort[i]->ri > all->insort[i]->prev->ri ||
			(all->insort[i]->prev->ri == max->ri && all->insort[i] == min)) &&
			(all->insort[i]->ri < all->insort[i]->next->ri ||
			(all->insort[i]->next->ri == min->ri && all->insort[i] == max)))
			color = YEL;
		else
			color = RED;
		if (all->insort[i]->ri == pos_a(all, all->insort[i]))
			color = GRN;
		ft_printf(" %s%*d%s |\n", color,
			all->maxnl, all->insort[i]->n, "\033[0m");

	}
	else
		ft_printf(" %*d |\n",
			all->maxnl, all->insort[i]->n);
}

void	print_body(t_all *all)
{
	int		i;
	t_ilst	*a;
	t_ilst	*b;

	i = 0;
	a = all->a.ss;
	b = all->b.ss;
	while (i < all->len)
	{
		if (i < all->a.len)
			ft_printf("\t| %*d |",
			all->maxnl, a->n);
		else
			ft_printf("\t| %*s |",
			all->maxnl, "");
		if (i < all->b.len)
			ft_printf(" %*d |",
			all->maxnl, b->n);
		else
			ft_printf(" %*s |",
			all->maxnl, "");
		print_sorted(all, i);
		a = a ? a->next : 0;
		b = b ? b->next : 0;
		i++;
	}
}

void	print_stacks(t_all *all)
{
	print_head(all);
	print_body(all);
	print_line(all);
}
