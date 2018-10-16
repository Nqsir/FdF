/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_for_pct.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 17:50:47 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:21:05 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft_printf.h"

static void		ft_width_and_flags(t_struct *strt)
{
	char	*tmpsarg;
	char	*tmps;
	char	c;

	c = ' ';
	tmps = ft_strnew(strt->width - 1);
	if (strt->flag[1] && !strt->flag[2])
		c = '0';
	if (strt->width)
		ft_memset(tmps, c, strt->width - 1);
	tmpsarg = ft_strnew(2);
	ft_strncpy(tmpsarg, strt->s_arg, 1);
	ft_strjoinfree(tmps, tmpsarg, strt, strt->flag[2]);
}

void			ft_for_pct(t_struct *strt)
{
	strt->s_arg = ft_strnew(2);
	strt->s_arg[0] = '%';
	strt->s_arg[1] = '\0';
	if (strt->width)
		ft_width_and_flags(strt);
}
