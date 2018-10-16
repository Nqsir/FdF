/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_first.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 11:25:04 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:20:09 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft_printf.h"

void		ft_first(t_struct *strt)
{
	strt->oct = 0;
	strt->s_arg = NULL;
	strt->ws_arg = NULL;
	strt->type = 0;
	strt->err = 0;
	strt->size = 0;
	strt->prec = -1;
	strt->width = 0;
	strt->flag[0] = 0;
	strt->flag[1] = 0;
	strt->flag[2] = 0;
	strt->flag[3] = 0;
	strt->flag[4] = 0;
	strt->nega = 0;
	strt->arg = 0;
	strt->l_arg = 0;
	strt->bad_c = 0;
}
