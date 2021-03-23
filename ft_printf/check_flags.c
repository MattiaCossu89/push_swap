#include "ft_printf.h"

char	set_mflag(const char **str, t_par *g_cur)
{
	g_cur->mflag = 'k';
	g_cur->zflag = 0;
	(*str)++;
	return (1);
}

char	set_zflag(const char **str, t_par *g_cur)
{
	if (!g_cur->mflag)
		g_cur->zflag = 'k';
	(*str)++;
	return (1);
}

char	set_hflag(const char **str, t_par *g_cur)
{
	g_cur->hflag = 'k';
	(*str)++;
	return (1);
}

char	set_pflag(const char **str, t_par *g_cur)
{
	g_cur->pflag = 'k';
	g_cur->sflag = 0;
	(*str)++;
	return (1);
}

char	set_sflag(const char **str, t_par *g_cur)
{
	g_cur->sflag = 'k';
	(*str)++;
	return (1);
}
