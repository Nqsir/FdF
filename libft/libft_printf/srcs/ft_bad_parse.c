/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bad_parse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 23:05:58 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:20:00 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft_printf.h"

void		ft_bad_parse(t_struct *strt, char *format)
{
	char	*tmpsarg;
	char	*tmps;
	char	c;

	c = ' ';
	tmps = NULL;
	if (!ft_strchr("sSpdiDoOuUxXcCeEfFgGaAnm%hljztLq#0-+ ", *format))
	{
		tmpsarg = ft_strnew(2);
		strt->s_arg = ft_strnew(2);
		strt->s_arg[0] = *format;
		strt->s_arg[1] = '\0';
		if (strt->width && strt->prec <= 0)
		{
			tmps = ft_strnew(strt->width);
			if (strt->flag[1] && !strt->flag[2])
				c = '0';
			ft_memset(tmps, c, strt->width - 1);
		}
		ft_strncpy(tmpsarg, strt->s_arg, 1);
		ft_strjoinfree(tmps, tmpsarg, strt, strt->flag[2]);
	}
}
