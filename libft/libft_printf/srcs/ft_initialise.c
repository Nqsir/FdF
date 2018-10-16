/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_initialise.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:08:58 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:22:00 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft_printf.h"

void	ft_initialise(t_struct *strt)
{
	if (strt->s_arg)
	{
		free(strt->s_arg);
		strt->s_arg = NULL;
	}
	if (strt->ws_arg)
	{
		free(strt->ws_arg);
		strt->ws_arg = NULL;
	}
	strt->type = 0;
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
