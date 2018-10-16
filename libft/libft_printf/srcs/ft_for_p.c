/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_for_p.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 12:00:01 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:20:52 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft_printf.h"

static void		ft_prec(t_struct *strt, char **tmps, char **tmpsarg)
{
	*tmps = ft_strnew(strt->prec - strt->l_arg);
	ft_memset(*tmps, '0', strt->prec - strt->l_arg);
	strt->flag[2] = 0;
	*tmpsarg = ft_strnew(strt->l_arg);
	ft_strcpy(*tmpsarg, strt->s_arg);
	if (strt->arg == 0)
		ft_strjoinfree(*tmps, *tmpsarg, strt, 1);
	else
		ft_strjoinfree(*tmps, *tmpsarg, strt, strt->flag[2]);
	*tmpsarg = strt->s_arg;
	strt->s_arg = ft_strjoin("0x", *tmpsarg);
	free(*tmpsarg);
}

static void		ft_width(t_struct *strt, char **tmps, char **tmpsarg)
{
	*tmps = ft_strnew(strt->width - strt->l_arg);
	if ((strt->flag[1] && !strt->flag[2]))
		ft_memset(*tmps, '0', strt->width - strt->l_arg - 2);
	else
		ft_memset(*tmps, ' ', strt->width - strt->l_arg - 2);
	*tmpsarg = ft_strnew(strt->l_arg);
	ft_strcpy(*tmpsarg, strt->s_arg);
	if (strt->arg == 0 && strt->flag[1])
		ft_strjoinfree(*tmps, *tmpsarg, strt, 1);
	else
		ft_strjoinfree(*tmps, *tmpsarg, strt, strt->flag[2]);
}

void			ft_for_p(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;

	tmps = NULL;
	tmpsarg = NULL;
	strt->s_arg = ft_itoa_base(strt->arg, 16, "0123456789abcdef");
	strt->l_arg = ft_strlen(strt->s_arg);
	if (strt->prec == 0)
		ft_strcpy(strt->s_arg, "0x");
	else if (strt->prec < strt->l_arg)
	{
		tmpsarg = strt->s_arg;
		strt->s_arg = ft_strjoin("0x", tmpsarg);
		free(tmpsarg);
	}
	if (strt->prec > strt->l_arg)
		ft_prec(strt, &tmps, &tmpsarg);
	if ((strt->width - 2) > strt->l_arg)
		ft_width(strt, &tmps, &tmpsarg);
}
